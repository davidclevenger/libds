#ifndef __LIST_H__
#define __LIST_H__

/* head struct */
typedef struct
{
	Node* next;
	void* (*dealloc)(void* data);
	int size;
	char pad[4];
} List;

/* node struct */
typedef struct
{
	Node* next;
	void* data;
} Node;

List* list_init(List*, void (*dealloc));
void list_append(List*, void* data);
void* list_get(List*, int idx); 
void list_remove(List*, void* data)
void list_free(List*);

#endif
