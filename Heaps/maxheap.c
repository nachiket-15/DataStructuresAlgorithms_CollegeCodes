//MAX HEAP

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
    int *array;
    int size;
    int capacity;
}Heap;

Heap*createheap(int capacity){
    Heap*heap=(Heap*)malloc(sizeof(Heap)*capacity);
    heap->array=(int*)malloc(sizeof(int)*capacity);
    heap->capacity=capacity;
    heap->size=0;

    return heap;
}

void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Required during insertion
void heapifyUp(Heap*heap,int index){
    int parent=(index-1)/2;
    if(index > 0  &&  heap->array[index] > heap->array[parent]){
        swap(&heap->array[index],&heap->array[parent]);
        heapifyUp(heap,parent);
    }
}

//Required during deletion
void heapifyDown(Heap*heap,int index){
    int leftchild=2*index+1;
    int rightchild=2*index+2;
    int largest=index;

    if(leftchild < heap->size && heap->array[leftchild] > heap->array[largest]){
        largest=leftchild;
    }

    if(rightchild < heap->size && heap->array[rightchild] > heap->array[largest]){
        largest=rightchild;
    }

    if(largest!=index){
        swap(&heap->array[largest],&heap->array[index]);
        heapifyDown(heap,largest);
    }
}

void insert(Heap*heap,int value){
    if(heap->size == heap->capacity){
        printf("Heap is full");
        //Then exit the function
        return;
    }

    heap->array[heap->size]=value;
    //Heapify up requires pointer to heap and index of element to be heapified
    heapifyUp(heap,heap->size);
    heap->size=heap->size+1;
}

int removeMax(Heap*heap){
    
    if(heap->size==0){
        printf("Heap is empty");
        return -1;
    }

    int max=heap->array[0];
    //Replace by last node of heap tree 
    heap->array[0]=heap->array[heap->size-1];
    heap->size--;
    heapifyDown(heap,0);
    return max;
}



void heapSort(Heap* heap, int* array) {
    for (int i = heap->size - 1; i >= 0; i--) {
        array[i] = removeMax(heap);
    }
}


void printHeap(Heap*heap){
    printf("Heap consists of : \n");

    for(int i=0;i<heap->size;i++){
        printf("%d ",heap->array[i]);
    }
    printf("\n");
}

int main(){

    Heap*heap=createheap(100);
    //Create an array to store user inputs
    int *array;

    //Total no of inputs 
    printf("Dear user, Enter total inputs : \n");
    int s;
    scanf("%d",&s);

    array=(int*)malloc(sizeof(int)*s);



    //User inputs 
    printf("Dear user, Enter input elements : \n");
    for(int i=0;i<s;i++){
        scanf("%d",&array[i]);
    }


    //Insert input given by user into heap and make max heap from them
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
