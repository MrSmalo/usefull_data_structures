#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define INF 99999999;

typedef struct Heap {

	int* arr;
	int size;
	int capacity;

}heap_t;

//swap array indexes
int swap(int *arr, int i, int j);

//creating a new heap
heap_t* createHeap(int capacity);

//get the left child index of specipic index
int left(heap_t* heap, int i);

//get right child of index specific index
int right(heap_t* heap, int i);

//get parent index of specific index
int parent(int i);

//heapify
void heapify(heap_t* heap,int i);

//insert a value to heap
void insertHeap(heap_t* heap, int val);

//building an heap out of array
heap_t* buildHeap(int* arr, int len);

//print heap
void printHeap(heap_t* heap);

