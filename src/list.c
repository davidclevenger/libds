#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* list_make(void (*dealloc)(void* dealloc))
{
	List* list = (List*) malloc(sizeof(List));
	if( list == NULL )
	{
		fprintf(stderr, "malloc failure\n");
	}

	list->next = NULL;
	list->size = 0;
	list->dealloc = dealloc;

	return list;
}

void list_append(List* list, void* data)
{
	Node* trav;
	
	trav = list->next;

	while( trav != NULL )
	{
		trav = trav->next;
	}

	trav = (Node*) malloc(sizeof(Node));
	if( trav == NULL )
	{
		fprintf(stderr, "malloc failure\n");
	}
	
	list->size += 1;
	trav->next = NULL;
	trav->data = data;
}

void* list_get(List* list, int idx)
{
	Node* trav;

	if( idx >= list->size )
	{
		fprintf(stderr, "List: index out of bounds\n");
		return NULL;
	}

	int curr = 0;
	trav = list->next;

	while( curr < idx )
	{
		trav = trav->next;
	}

	return trav->data;
}

void list_remove(List* list, void* data)
{
	Node* trav;
	Node* prev;
	
	trav = list->next;

	while( trav != NULL )
	{
		if( trav->data == data )
		{

		}
	}
}

void list_free(List* list)
{

}
