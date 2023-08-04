#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a subset
typedef struct Subset {
    int parent;
    int rank;
} Subset;

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node** adjList;
}Graph;

// Function to create a new node
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency list
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    // Initialize the adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an undirected edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to find the subset of an element
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}



// Function to perform union of two subsets
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}



// Function to compare two edges
int compareEdges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to perform Kruskal's algorithm
void kruskalMST(Graph* graph) {
    int numVertices = graph->numVertices;
    Edge result[numVertices];
    int e = 0;
    int i = 0;

    // Get the total number of edges
    int numEdges = 0;
    for (int v = 0; v < numVertices; v++) {
        Node* temp = graph->adjList[v];
        while (temp != NULL) {
            numEdges++;
            temp = temp->next;
        }
    }

    Edge edges[numEdges];

    // Store all the edges in a separate array
    int edgeIndex = 0;
    for (int v = 0; v < numVertices; v++) {
        Node* temp = graph->adjList[v];
        while (temp != NULL) {
            edges[edgeIndex].src = v;
            edges[edgeIndex].dest = temp->vertex;
            edges[edgeIndex].weight = temp->weight;
            edgeIndex++;
            temp = temp->next;
        }
    }

    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    Subset subsets[numVertices];

    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < numVertices - 1 && i < numEdges) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d    Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

// Example usage
int main() {
    int numVertices = 4;  // Number of vertices
    Graph* graph = createGraph(numVertices);

    // Add edges
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);

    kruskalMST(graph);

    return 0;
}
