#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* list_init(void* (*dealloc)(void* data))
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

	if( list->next == NULL )
	{
		list->next = (Node*) malloc(sizeof(Node));
		list->next->data = data;
		list->next->next = NULL;
		list->size += 1;
		return;
	}
	
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

void list_remove(List* list, int idx)
{
	Node* trav = NULL;
	Node* prev = NULL;
	int curr = 0;

	if( idx >= list->size )
	{
		fprintf(stderr, "List: index out of bounds\n");
		return;
	}
	
	trav = list->next;

	while( curr < idx )
	{
		prev = trav;
		trav = trav->next;
		++curr;
	}

	if( prev == NULL ) /* first node */
	{
		list->next = trav->next;
	}
	else /* node 2 - size */
	{
		prev->next = trav->next;
	}

	if( list->dealloc != NULL )
	{
		list->dealloc(trav->data);
	}

	free(trav);
}

void list_free(List* list)
{
	Node* trav;
	
	while( list->next != NULL )
	{
		/* pop front and relink */
		trav = list->next;
		list->next = trav->next;
		
		if( list->dealloc != NULL )
		{
			list->dealloc(trav->data);
		}

		free(trav);
	}
	
	free(list);
}
