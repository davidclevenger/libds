#ifndef __LIST_H__
#define __LIST_H__

/* node struct */
typedef struct node
{
	struct node* next;
	void* data;
} Node;

/* head struct */
typedef struct
{
	Node* next;
	void* (*dealloc)(void* data);
	int size;
	char pad[4];
} List;

List* list_init(void* (*dealloc)(void*));
void list_append(List*, void*);
void* list_get(List*, int); 
void list_remove(List*, int);
void list_free(List*);

#endif
