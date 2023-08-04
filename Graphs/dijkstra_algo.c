#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define SIZE 30
//DIJSTRA for characters 

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


void dijkstra(Graph* graph, char source) {
    int numVertices = graph->numVertices;
    int distances[numVertices]; // Array to store the shortest distances
    bool visited[numVertices]; // Array to track visited vertices

    // Initialize distances and visited arrays
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    distances[source - 'a'] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < numVertices - 1; count++) {
        // Find the vertex with the minimum distance value
        int minDistance = INT_MAX;
        int minIndex;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Update the distances of the adjacent vertices
        Node* currentNode = graph->adjList[minIndex];
        while (currentNode != NULL) {
            int vertex = currentNode->vertex - 'a';
            int weight = currentNode->weight;

            if (!visited[vertex] && distances[minIndex] != INT_MAX &&
                distances[minIndex] + weight < distances[vertex]) {
                distances[vertex] = distances[minIndex] + weight;
            }

            currentNode = currentNode->next;
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%c\t%d\n", i + 'a', distances[i]);
    }
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

    // primMST(graph);
    dijkstra(graph,'a');

  

}