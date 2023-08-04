#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define SIZE 30


//Node structure - represents node in linked list
typedef struct Node{
    int vertex;
    int weight;
    //Pointer to next node
    struct Node*next;
}Node;

//Structure for Graph
typedef struct Graph
{
    int numVertices;
    Node**adjList;
}Graph;


Node*createNode(int vertex,int weight){
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

void addEdge(Graph* graph, int src, int dest,int weight) {
    //Create node for dest 
    Node* newNode = createNode(dest,weight);
    //make its next as adjaceny list of src
    newNode->next = graph->adjList[src];
    //Now make this node head in adj list of src
    graph->adjList[src] = newNode;

    //Create node for src
    newNode = createNode(src,weight);
    //Make its next as adj list of dest
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}


void dijkstra(Graph* graph, int source) {
    int numVertices = graph->numVertices;

    int distances[numVertices]; // Array to store the shortest distances
    bool visited[numVertices]; // Array to track visited vertices


    // Initialize distances and visited arrays
    for (int i = 0; i < numVertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }


    // Distance of source vertex from itself is always 0
    distances[source] = 0;

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

        while (currentNode) {

            int vertex = currentNode->vertex;
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
    for (int i = 1; i <= numVertices; i++) {
        printf("%d\t%d\n", i, distances[i]);
    }
    
}

int main(){
    int num_of_vertices =9;
    Graph*graph=creategraph(num_of_vertices);

    addEdge(graph,1,2,2);
    addEdge(graph,1,4,6);
    addEdge(graph,1,3,4);
    addEdge(graph,2,3,5);
    addEdge(graph,4,3,1);
    addEdge(graph,5,3,2);
    addEdge(graph,4,8,4);
    addEdge(graph,4,6,3);
    addEdge(graph,5,6,1);
    addEdge(graph,5,9,3);
    addEdge(graph,5,7,5);
    addEdge(graph,6,7,4);

    
    dijkstra(graph,1);
    //gfg has adj matrix implementation 

}