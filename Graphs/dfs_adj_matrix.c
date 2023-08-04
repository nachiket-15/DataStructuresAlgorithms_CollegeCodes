#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Node {
    int numVertices;
    int adjacencyMatrix[SIZE][SIZE];
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    int i, j;
    // Initialize adjacency matrix with 0
    for (i = 0; i <= numVertices; i++) {
        for (j = 0; j <= numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest,int wt) {
    graph->adjacencyMatrix[src][dest] = wt;
    graph->adjacencyMatrix[dest][src] = wt;
}

// Depth-First Search traversal
void dfsHelper(Graph* graph, int vertex, bool* visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recursive call for all adjacent vertices
    for (int i = 0; i <= graph->numVertices; i++) {
        if (!visited[i] && graph->adjacencyMatrix[vertex][i]) {
            dfsHelper(graph, i, visited);
        }
    }
}

void dfs(Graph* graph, int startVertex) {
    // Create a visited array to keep track of visited vertices
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i <= graph->numVertices; i++)
        visited[i] = false;

    printf("DFS traversal: ");
    dfsHelper(graph, startVertex, visited);

    free(visited);
}

int main() {
    int num_of_vertices =9;
    Graph*graph=createGraph(num_of_vertices);

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


    int startVertex = 1;
    dfs(graph, startVertex);

    free(graph);

    return 0;
}
