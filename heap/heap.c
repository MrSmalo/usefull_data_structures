#include "./heap.h"

heap_t* createHeap(int capacity) {
	heap_t* heap;
	heap = (heap_t*)malloc(sizeof(heap_t));
	if (heap == NULL)
	{
		return 0;
	}
	heap->arr = (int*)malloc(sizeof(int) * capacity);
	if (heap->arr == NULL)
	{
		return 0;
	}
	heap->size = 0;
	heap->capacity = capacity;
	return heap;
}

int swap(int* arr,int i,int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int left(heap_t* heap, int i) {

	int sum = i*2+1, flag = INF;
	flag = (sum < heap->size) ? sum : flag;

	return flag;
}

int right(heap_t* heap, int i) {
	int sum = i * 2 + 2, flag = INF;
	flag = (sum < heap->size) ? sum : flag;

	return flag;
}

int parent(int i)
{
	int sum = (i-1)/2, flag = INF;
	flag = (sum > -1) ? sum : flag;

	return flag;
}

void heapify(heap_t* heap, int i)
{
	int l, r, largest, *arr = heap->arr, size = heap->size;
	l = left(heap,i);
	r = right(heap,i);
	largest = (l < size && arr[l] > arr[i]) ? l : i;
	largest = (r < size && arr[r] > arr[largest]) ? r : largest;
	if (largest != i)
	{
		swap(arr,i,largest);	
		heapify(heap,largest);
	}

}

void reorderHeap(heap_t* heap) {
	int i = heap->size - 1,parentI = parent(i);
	int* arr = heap->arr;
	while (i != 0 && arr[parentI] < arr[i])
	{
		swap(arr, parentI, i);
		i = parentI;
		parentI = parent(i);
	}
}

void insertHeap(heap_t* heap, int val) {
	int* arr = heap->arr;
	int size = (heap->size) + 1, capacity = heap->capacity;
	if (size <= capacity)
	{
		(heap->size)++;
		arr[size - 1] = val;
		reorderHeap(heap);
	}
	else
	{
		printf("insert heap error occured");
	}
}

heap_t* buildHeap(int* arr, int len)
{
	heap_t *heap = createHeap(len);
	heap->arr = arr;
	heap->size = len;
	int i = len / 2;
	while (i >= 0) {
		heapify(heap,i);
		i--;
	}
	return heap;
}


void printHeap(heap_t* heap)
{
	printf("\n%d",heap->arr[0]);
	for (size_t i = 1; i < heap->size; i++)
	{
		printf(",%d", heap->arr[i]);
	}
}



main() {
	srand(time(NULL));
	heap_t* heap1;
	int *arr,len = 10;
	arr = (int*)malloc(sizeof(int) * len);
	if (arr == NULL)
	{
		return 0;
	}
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = rand() % 50;
	}
	heap1 = buildHeap(arr,len);
	printHeap(heap1);
	return 0;
}