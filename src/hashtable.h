#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#define INITIAL_SIZE 23

typedef struct
{
	int size;
	int* table;
} Hashtable;

Hashtable* hash_init(void (*dealloc)(void*));
void hash_add(Hashtable*, const char*, void*);
void hash_get(Hashtable*, const char*);
void hash_remove(Hashtable*, const char*);
void hash_free(Hashtable*);

/* utility */
void resize(Hashtable* ht);
int hash(const char*);
int next_prime(int);
int key_ok(const char*);
int is_prime(int);

#endif
