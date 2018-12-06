#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct
{
	int x;
} testStruct;

void structDestroy(void* in)
{
	testStruct* ts;
	ts = (testStruct*) in;
	free(ts);
}

int main()
{
	List* list;
	testStruct* a;
	testStruct* b;
	testStruct* c;
	testStruct* d;
	testStruct* grab;

	a = (testStruct*) malloc(sizeof(testStruct));
	b = (testStruct*) malloc(sizeof(testStruct));
	c = (testStruct*) malloc(sizeof(testStruct));
	d = (testStruct*) malloc(sizeof(testStruct));

	a->x = 3;
	b->x = -11;
	c->x = 25;
	d->x = 55;

	list = list_init(structDestroy);
	assert( list->size == 0 );
	assert( list->next == NULL );

	list_append(list, (void*) a);
	list_append(list, (void*) b);
	list_append(list, (void*) c);
	list_append(list, (void*) d);

	/* |H| -> |a: 3| -> |b: -11| -> |c: 25| -> |d: 55| */
	assert( list->size == 4 );

	grab = (testStruct*) list_get(list, -1);
	assert( grab == NULL );

	grab = (testStruct*) list_get(list, 0);
	assert( grab->x == 3 ); 

	grab = (testStruct*) list_get(list, 1);
	assert( grab->x == -11 );

	grab = (testStruct*) list_get(list, 2);
	assert( grab->x == 25 );

	grab = (testStruct*) list_get(list, 3);
	assert( grab->x == 55 );

	grab = (testStruct*) list_get(list, 4);
	assert( grab == NULL );

	/* |H| -> |a: 3| -> |b: -11| -> |c: 25| -> |d: 55| */
	/* remove from front */
	list_remove(list, 0);
	assert( list->size == 3 );
	/* |H| -> |b: -11| -> |c: 25| -> |d: 55| */

	/* reove from middle */
	list_remove(list, 1);
	assert( list->size == 2 );
	/* |H| -> |b: -11| -> |d: 55| */

	/* remove from end */
	list_remove(list, 1);
	assert( list->size == 1 );
	/* |H| -> |b: -11| */

	list_free(list);

	free(a);
	free(c);
	free(d);

	/* 
	* if there are no memory leaks,
	* then list_free() took care of
	* deallocating.
	*/

	return 0;
}
