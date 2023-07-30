#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 100

typedef struct {
    int numVertices;
    int adjacencyMatrix[SIZE][SIZE];
} Graph;

int minDistance(int dist[], int visited[], int numVertices) {
    int min = INT_MAX, minIndex, v;
    for (v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[], int numVertices) {
    printf("Vertex\tDistance from Source\n");
    int v;
    for (v = 0; v < numVertices; v++) {
        printf("%d\t%d\n", v, dist[v]);
    }
}

void dijkstra(Graph* graph, int src) {
    int dist[SIZE];
    int visited[SIZE];
    int parent[SIZE];
    int v;

    // Initialize arrays
    for (v = 0; v < graph->numVertices; v++) {
        dist[v] = INT_MAX;
        visited[v] = 0;
        parent[v] = -1;
    }

    dist[src] = 0;

    int count;
    for (count = 0; count < graph->numVertices - 1; count++) {
        int u = minDistance(dist, visited, graph->numVertices);
        visited[u] = 1;

        int i;
        for (i = 0; i < graph->numVertices; i++) {
            if (!visited[i] && graph->adjacencyMatrix[u][i] && dist[u] != INT_MAX
                && dist[u] + graph->adjacencyMatrix[u][i] < dist[i]) {
                dist[i] = dist[u] + graph->adjacencyMatrix[u][i];
                parent[i] = u;
            }
        }
    }

    printSolution(dist, graph->numVertices);
}

int main() {
    Graph graph;
    int numVertices, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    graph.numVertices = numVertices;

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &graph.adjacencyMatrix[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(&graph, source);

    return 0;
}
