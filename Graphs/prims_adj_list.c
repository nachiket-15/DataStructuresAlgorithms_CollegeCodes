#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define SIZE 30

typedef struct Node{
    char vertex;
    int weight;
    struct Node*next;
}Node;

typedef struct Graph
{
    int numVertices;
    Node**adjList;
}Graph;


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
    int parent[numVertices];

    //Make a key array of size equal to no of vertices in graph
    //Key array is made to keep track of minimum weight edge connecting each vertex to mst
    int key[numVertices];
    //key[i] represents minimum weight of an edge connecting to vertex i


    //Make a boolean array mstset of size equal to no of vertices in graph
    bool mstSet[numVertices];


    //Initialize all key array values with (infinity) and mark mst as unvisited
    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;    
    parent[0] = -1;

  
    for (int count = 0; count < numVertices - 1; count++)
    {
        //Get the index of minimum edge weight vertex from key array which is unvisited (in mstSet)
        int u = findMinKey(key, mstSet, numVertices);
        
        mstSet[u] = 1;

        Node* node = graph->adjList[u];

        while (node)
        {
            int v = node->vertex - 'a';
            if (mstSet[v] == false && node->weight < key[v])
            {
                parent[v] = u;
                key[v] = node->weight;
            }

            node = node->next;
        }
    }
    
    //Print the required mst
    printMST(parent,key, numVertices, graph);
    
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

    primMST(graph);

  

}

