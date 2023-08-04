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
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int wt) {
    graph->adjacencyMatrix[src][dest] = wt;
    graph->adjacencyMatrix[dest][src] = wt;
}

// Structure for queue
typedef struct {
    int array[SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = q->rear = -1;
}

int isQueueFull(Queue* q) {
    return (q->rear == (SIZE - 1));
}

int isQueueEmpty(Queue* q) {
    return (q->front == -1);
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    } else {
        if (isQueueEmpty(q))
            q->front = 0;

        q->rear++;
        q->array[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = q->array[q->front];

    if (q->front == q->rear)
        init_queue(q);
    else
        q->front++;

    return value;
}

// Breadth - First Search traversal
void bfs(Graph* graph, int startVertex) {
    // Create a visited array to keep track of visited vertices
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;

    // Create a queue for BFS
    Queue queue;
    init_queue(&queue);

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(&queue, startVertex);

    printf("BFS traversal: ");

    while (!isQueueEmpty(&queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex is not visited, mark it as visited and enqueue it
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }

    printf("\n");
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
    bfs(graph, startVertex);

    free(graph);

    return 0;
}
