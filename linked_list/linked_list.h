#include <stdio.h>
#include <stdlib.h>

//define a node
typedef struct Node
{
	int key;
	struct Node* next;
}node_t;

//define a list
typedef struct List
{
	node_t** head;
}list_t;

//create a new node 
node_t* createNode(int key);

//create a list
list_t* createList(node_t** head);

//add new node to head of a list
void listInsert(list_t* list, node_t* node);

//return the first node with desired key
node_t* listSearch(list_t *list, int key);

//return prev node
node_t* prevNode(list_t *list, node_t *node);

//delete a desire node
void listDelete(list_t* list, node_t* node);

//print a list
void printList(list_t *list);