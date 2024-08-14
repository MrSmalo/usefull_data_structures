#include "linked_list.h"

node_t *createNode(int key) {

	node_t *node = NULL;
	node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL)
	{
		return 0;
	}
	node->key = key;
	node->next = NULL;
	return node;
}

list_t* createList(node_t** head) {
	list_t* list = NULL;
	list = (list_t*)malloc(sizeof(list_t));
	if (list == NULL)
	{
		return 0;
	}
	list->head = head;
	return list;
}

void listInsert(list_t *list,node_t *node) {
	node->next = *list->head;
	*list->head = node;
}

node_t* listSearch(list_t *list,int key) {

	node_t* node = *list->head;
	while (node->key != key) {
		if (node->next == NULL)
		{
			printf("Node not found\n");
			return NULL;
		}
		node = node->next;
	}

	return node;
}

node_t* prevNode(list_t *list, node_t *node)
{
	node_t *preNode = *list->head;
	if (node == preNode)
	{
		return NULL;
	}
	while (preNode->next != node)
	{
		preNode = preNode->next;
	}
	return preNode;
}

void listDelete(list_t* list, node_t* node)
{
	//first node
	if(node == *list->head)
	{
		*list->head = node->next;
		free(node);
		return;
	}

	node_t* preNode = prevNode(list,node);
	//last node
	if(node->next == NULL)
	{
		free(node);
		preNode->next = NULL;
		return;
	}

	preNode->next = node->next;
	free(node);
}

void printList(list_t* list)
{
	node_t* node = *list->head;
	while (node->next != NULL) {
		printf("-->%d",node->key);
		node = node->next;
	}
	printf("-->%d\n", node->key);
}

int main() {
	
	list_t *l1,*l2;
	node_t *node,*head1,*head2;
	head1 = createNode(0);
	head2 = createNode(5);
	l1 = createList(&head1);
	l2 = createList(&head2);
	for (size_t i = 0; i < 4; i++)
	{
		node = createNode(i+1);
		listInsert(l1, node);
	}
	for (size_t i = 5; i < 11; i++)
	{
		node = createNode(i + 1);
		listInsert(l2, node);
	}
	printList(l1);
	printList(l2);
	return 0;
}