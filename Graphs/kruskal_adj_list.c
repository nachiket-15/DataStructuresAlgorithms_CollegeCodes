#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Comparator function to use in sorting
int comparator(const void* p1, const void* p2) {
    const struct Edge* x = (const struct Edge*)p1;
    const struct Edge* y = (const struct Edge*)p2;
    return x->weight - y->weight;
}

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent of a node
int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;

    // Following helps us in path compression
    return parent[component] = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[], int n) {
    // Finding the parents
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;

        // Since the rank increases if
        // the ranks of two sets are the same
        rank[u]++;
    }
}

// Function to find the MST using Kruskal's algorithm
void kruskalAlgo(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Store the result MST
    int e = 0; // Index variable for result[]

    // Sort all the edges in the graph in ascending order
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comparator);

    int parent[V];
    int rank[V];

    // Function to initialize parent[] and rank[]
    makeSet(parent, rank, V);

    printf("Following are the edges in the constructed MST:\n");

    for (int i = 0; e < V - 1 && i < graph->E; i++) {
        struct Edge next_edge = graph->edge[i];

        int v1 = findParent(parent, next_edge.src);
        int v2 = findParent(parent, next_edge.dest);

        // If including this edge does not form a cycle, include it in the result MST
        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, V);
            result[e++] = next_edge;
            printf("%d -- %d == %d\n", next_edge.src, next_edge.dest, next_edge.weight);
        }
    }

    printf("Minimum Cost Spanning Tree: ");
    int minCost = 0;
    for (int i = 0; i < e; i++) {
        minCost += result[i].weight;
    }
    printf("%d\n", minCost);
}

// Driver code
int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    kruskalAlgo(graph);

    return 0;
}
