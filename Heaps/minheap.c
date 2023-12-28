#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int* array;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(sizeof(int) * capacity);
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
    heapifyUp(heap, heap->size - 1);
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


void heapSort(Heap* heap, int* array) {
    for(int i=0;i<heap->size;i++){
        array[i]=removeMin(heap);
    }
}


void printHeap(Heap* heap) {
    printf("Heap consists of:\n");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    Heap* heap = createHeap(100);

    printf("Enter the total number of inputs:\n");
    int s;
    scanf("%d", &s);
    int* array = (int*)malloc(sizeof(int) * s);

    printf("Enter the input elements:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d", &array[i]);
    }

   
    for(int i=0;i<s;i++){
        insert(heap,array[i]);
    }
    printHeap(heap);

    heapSort(heap,array);
    printf("Array after applying heapsort on it : ");
    for(int i=0;i<s;i++){
        printf("%d ",array[i]);
    }
    printf("\n");


    return 0;
}
