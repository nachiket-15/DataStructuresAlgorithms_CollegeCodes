
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>

typedef struct Heap {
    int* array;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)calloc(capacity, sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;

    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap* heap, int index) {

    int parent = (index - 1) / 2;

    if (index > 0 && heap->array[index] < heap->array[parent]) {
        swap(&heap->array[index], &heap->array[parent]);
        heapifyUp(heap, parent);
    }

}

void heapifyDown(Heap* heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap->size && heap->array[leftChild] < heap->array[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->array[rightChild] < heap->array[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->array[smallest], &heap->array[index]);
        heapifyDown(heap, smallest);
    }
}

void insert(Heap* heap, int value) {

    if (heap->size == heap->capacity) {
        printf("Heap is full");
        return;
    }

    heap->array[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size-1);

}

int removeMin(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty");
        return -1;
    }

    int min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return min;
}

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;


typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;


Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjList = (Node**)malloc(sizeof(Node*) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void decreaseKey(Heap* heap, int vertex, int newKey) {
    int index = -1;

    // Find the index of the vertex in the heap
    for (int i = 0; i < heap->size; i++) {
        if (heap->array[i] == vertex) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Vertex not found in the heap");
        return;
    }

    // Update the key with the new value
    heap->array[index] = newKey;

    // Maintain the heap property by heapifying up
    heapifyUp(heap, index);
}

void primMST(Graph* graph) {

    int numVertices = graph->numVertices;

    int* parent = (int*)malloc(sizeof(int) * numVertices);
    int* key = (int*)malloc(sizeof(int) * numVertices);
    bool* inMST = (bool*)malloc(sizeof(bool) * numVertices);

    Heap* minHeap = createHeap(numVertices);

    for (int v = 1; v < numVertices; v++) {
        parent[v] = -1;
        key[v] = INT_MAX;
        inMST[v] = false;

        insert(minHeap, key[v]);
    }

    // Initialize inMST for the first vertex
    inMST[0] = true;
    key[0] = 0;
    insert(minHeap, key[0]);


    while (minHeap->size > 0) {
        int u = removeMin(minHeap);
        inMST[u] = true;

        Node* temp = graph->adjList[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (inMST[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                decreaseKey(minHeap, v, key[v]);
            }

            temp = temp->next;
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d\n", parent[i], i);
    }

    free(parent);
    free(key);
    free(inMST);
}

int main() {
    int numVertices = 9;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    primMST(graph);

    return 0;
}
