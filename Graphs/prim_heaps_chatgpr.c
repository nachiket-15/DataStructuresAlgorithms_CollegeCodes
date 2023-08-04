#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure to represent the adjacency list for each vertex
typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

// Function to create a new node with the given vertex and weight
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(sizeof(Node*) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Structure to represent a heap node
typedef struct HeapNode {
    int vertex;
    int key;
} HeapNode;

// Structure to represent a min heap
typedef struct MinHeap {
    int capacity;
    int size;
    int* pos;
    HeapNode** array;
} MinHeap;

// Function to create a new min heap node
HeapNode* createHeapNode(int vertex, int key) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = vertex;
    node->key = key;
    return node;
}

// Function to create a new min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->pos = (int*)malloc(sizeof(int) * capacity);
    minHeap->array = (HeapNode**)malloc(sizeof(HeapNode*) * capacity);
    return minHeap;
}

// Function to swap two heap nodes
void swapHeapNodes(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation at a given index
void heapify(MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = minHeap->array[smallest];
        HeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;

        swapHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        heapify(minHeap, smallest);
    }
}

// Function to check if the given min heap is empty
bool isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Function to extract the minimum node from the min heap
HeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    HeapNode* root = minHeap->array[0];
    HeapNode* lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    heapify(minHeap, 0);

    return root;
}

// Function to decrease the key value of a given vertex
void decreaseKey(MinHeap* minHeap, int vertex, int key) {
    int i = minHeap->pos[vertex];
    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if a given vertex is present in the min heap
bool isInMinHeap(MinHeap* minHeap, int vertex) {
    if (minHeap->pos[vertex] < minHeap->size)
        return true;
    return false;
}

void printMST(int parent[], int n, Node** graph) {
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", parent[i], i);
}


// Function to perform Prim's algorithm to construct MST
void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(sizeof(int) * numVertices);
    int* key = (int*)malloc(sizeof(int) * numVertices);
    MinHeap* minHeap = createMinHeap(numVertices);

    for (int v = 1; v < numVertices; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = createHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    key[0] = 0;
    minHeap->array[0] = createHeapNode(0, key[0]);
    minHeap->pos[0] = 0;
    minHeap->size = numVertices;

    while (!isEmpty(minHeap)) {
        HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->vertex;

        Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (isInMinHeap(minHeap, v) && temp->weight < key[v]) {
                key[v] = temp->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            temp = temp->next;
        }
    }

    printMST(parent, numVertices, graph->adjList);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("Enter the edges and weights:\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);

    return 0;
}
