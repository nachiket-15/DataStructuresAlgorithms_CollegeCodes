#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define SIZE 30

//Structure for queue
typedef struct node{
    char array[SIZE];
    int front;
    int rear;

}Queue;

void init_queue(Queue*q){
    q->front=q->rear=-1;
} 

int isQueueFull(Queue*q){
    return (q->rear==(SIZE-1));
}

int isQueueEmpty(Queue*q){
    return (q->front==-1);
}

void enqueue(Queue* q, char value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    else {
        if (isQueueEmpty(q)){
            q->front = 0;
        }

        q->rear++;
        q->array[q->rear] = value;
    }
}

char dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return '\0';
    }

    char value = q->array[q->front];

    if (q->front == q->rear)
        init_queue(q);
    else
        q->front++;

    return value;
}

//Node structure - represents node in linked list
typedef struct Node{
    char vertex;
    int weight;
    //Pointer to next node
    struct Node*next;
}Node;

//Structure for Graph
typedef struct Graph
{
    int numVertices;
    //Double pointer to store adjacent lists
    Node**adjList;
}Graph;

//Creating newnode of linked list
Node*createNode(char vertex,int weight){
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->vertex=vertex;
    newnode->weight=weight;
    newnode->next=NULL;
    return newnode;
}

//Creating Graph 
Graph*creategraph(int vertices){
    Graph*graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=vertices;

    //memory is allocated for the adjLists array, which will store the adjacency lists. The size of the array is determined by multiplying the number of vertices (vertices) by the size of a pointer to a Node (sizeof(Node*))
    graph->adjList=(Node**)malloc(sizeof(Node*)*vertices);

    for(int i=0;i<vertices;i++){
        graph->adjList[i]=NULL;
    }

    return graph;
}

void addEdge(Graph* graph, char src, char dest,int weight) {
    //Create node for dest 
    Node* newNode = createNode(dest,weight);
    //make its next as adjaceny list of src
    newNode->next = graph->adjList[src-'a'];
    //Now make this node head in adj list of src
    graph->adjList[src-'a'] = newNode;

    //Create node for src
    newNode = createNode(src,weight);
    //Make its next as adj list of dest
    newNode->next = graph->adjList[dest-'a'];
    //Make it head in adj list of dest 
    graph->adjList[dest-'a'] = newNode;
}


void printGraph(Graph*graph){
    //store number of vertices in a variable
    int numVertices=graph->numVertices;
    //Iterate over each vertex's adjaceny list 
    for(int i=0;i<numVertices;i++){
        //Make a pointer pointing current adjacency list
        Node*currentNode=graph->adjList[i];

        printf("Adjacency list of vertex %c :",i+'a');
        while(currentNode){
            printf(" (%c , %d) ",currentNode->vertex,currentNode->weight);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}

void bfs(Graph* graph, char start) {

    //Starting index is calculated by subtracting ascii value of a from ascii value of start
    int startIdx = start - 'a';

    //Visited array is created & initialized with zeros using calloc function
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));

    //calloc(total_no_of_elements,size_of_each_element)

    //Mark the starting character (using its index - found by subtracting ascii value of a)
    visited[startIdx] = 1;

    //Create a queue , have pointer q to it.  
    Queue* q = (Queue*)malloc(sizeof(Queue));
    //Initialize your queue
    init_queue(q);

    //Push the starting character into queue
    enqueue(q, start);


    printf("\nBFS Traversal from starting index %c is: ", start);

    //BFS traversal begins with next while loop that continues till queue is empty
    while (!isQueueEmpty(q)) {
        //Get the front element of queue and pop it from queue
        char currentVertex = dequeue(q);
        //Print that front element
        printf("%c ", currentVertex);

        //Get the index of that front element so that we can loop in its adjacency list
        int currentIdx = currentVertex - 'a';

        //Temp is pointer to adjacency list of front element
        Node* temp = graph->adjList[currentIdx];

        while (temp) {
            //Neighbour of front element found from adj list
            int neighbour = temp->vertex;
            //Index of neighbour
            int neighbourIdx=temp->vertex-'a';

            //If neighbour is unvisited , then mark it as visited and push it into queue
            if (visited[neighbourIdx] == 0) {
                visited[neighbourIdx] = 1;
                enqueue(q,neighbour);
            }
            
            //Move ahead temp pointer 
            temp = temp->next;
        }
    }

    //Free the memory allocated to visited array
    free(visited);
    //Free the queue
    free(q);
}

void dfsRecursive(Graph* graph,int vertex,int* visited);

void dfs(Graph* graph, char start) {
    int startIdx = start - 'a';
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));

    printf("\nDFS Traversal from starting index %c is: ", start);
    visited[startIdx] = 1; // Mark the starting vertex as visited
    dfsRecursive(graph, startIdx, visited);

    free(visited);
}

void dfsRecursive(Graph* graph, int vertex, int* visited) {
    printf("%c ", vertex + 'a');

    Node* temp = graph->adjList[vertex];

    while (temp) {
        int neighbor = temp->vertex - 'a';

        if (visited[neighbor] == 0) {
            visited[neighbor] = 1; // Mark the neighbor as visited
            dfsRecursive(graph, neighbor, visited);
        }temp = temp->next;
    }
}

//Prims algorithm
int findMinKey(int key[], bool mstSet[], int numVertices)
{
    int min = INT_MAX, minIndex;

    //Iterate over both arrays mstSet and Key 
    for (int v = 0; v < numVertices; v++)
    {   
        //If the vertex is unvisited and edge weight is minimum than what it was already
        if (mstSet[v] == false && key[v] < min)
        {
            //Then assign min variable new min value i.e. key[v]
            min = key[v];
            //Index of that minimum value is v
            minIndex = v;
        }
    }
    //So basically in this function we found out minimum edge weight from Key array such that ,that particular vertex was unvisited 
    //We finally return the index of minimum edge weight 
    return minIndex;
}

void printMST(int parent[],int key[], int numVertices, Graph* graph)
{
    printf("\n\nMinimum spanning tree for given graph is \n");
    printf("\nEdge   Weight\n");
    int total_min_weight=0;
    for (int i = 1; i < numVertices; i++){
        printf("%c - %c    %d\n", parent[i] + 'a', i + 'a',key[i]);
        total_min_weight+=key[i];
    }

    printf("Total minimum weight of required MST is : %d\n",total_min_weight);
}

void primMST(Graph* graph)
{
    //Get the number of vertices of given graph
    int numVertices = graph->numVertices;

    //Make a parent array of size equal to no of vertices in graph
    int parent[9];

    //Make a key array of size equal to no of vertices in graph
    //Key array is made to keep track of minimum weight edge connecting each vertex to mst
    int key[9];
    //key[i] represents minimum weight of an edge connecting to vertex i


    //Make a boolean array mstset of size equal to no of vertices in graph
    bool mstSet[9];


    //Initialize all key array values with (infinity) and mark mst as unvisited
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    //Choose a starting vertex and mark its edge weight as zero 
    key[0] = 0;
    //For the chosen vertex mark its parent as -1
    parent[0] = -1;

    //Iterate till one vertex less as one of vertex is initialzed already by us (0 here)
    for (int count = 0; count < numVertices - 1; count++)
    {
        //Get the index of minimum edge weight vertex from key array which is unvisited (in mstSet)
        int u = findMinKey(key, mstSet, numVertices);
        //As now we have visited it , so mark it visited
        mstSet[u] = true;

        //Initialize a node type pointer named node that points to adjacency list
        //That would help us to iterate over its neighbours
        Node* node = graph->adjList[u];

        while (node)
        {
            //Get the index of neighbours by subtracting ASCII value of character 'a'
            int v = node->vertex - 'a';

            //Check if adjacent vertex v is not included in mst 
            //Also check if weight of edge connecting current vertex u to v is smaller than current key value for v 
            if (mstSet[v] == false && node->weight < key[v])
            {
                //If both conditions are true then it means edge from u to v has samller weight than any other path to v 

                //Update the parent of adjacent vertex v with u 
                parent[v] = u;
                //Update key value of vertex v with weight of edge from u to v
                key[v] = node->weight;
            }

            //Move node pointer to next adjcant node
            node = node->next;
        }
    }
    
    //Print the required mst
    printMST(parent,key, numVertices, graph);
    // for(int i=0;i<numVertices;i++){
    //     printf("%d ,",key[i]);
    // }
}

int main(){
    int num_of_vertices =9;
    Graph*graph=creategraph(num_of_vertices);

    addEdge(graph,'a','b',2);
    addEdge(graph,'a','d',6);
    addEdge(graph,'a','c',4);
    addEdge(graph,'b','c',5);
    addEdge(graph,'d','c',1);
    addEdge(graph,'e','c',2);
    addEdge(graph,'d','h',4);
    addEdge(graph,'d','f',3);
    addEdge(graph,'e','f',1);
    addEdge(graph,'e','i',3);
    addEdge(graph,'e','g',5);
    addEdge(graph,'f','g',4);

    printGraph(graph);


    bfs(graph,'a');
    dfs(graph,'a');


    primMST(graph);

    // printf("%d",'a');

}



 

