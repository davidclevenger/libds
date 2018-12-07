#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

Hashtable* hash_init(void (*dealloc)(void*))
{
	
}

void hash_add(Hashtable* ht, const char* key, void* data)
{

}

void hash_get(Hashtable* ht, const char* key)
{

}

void hash_remove(Hashtable* ht, const char* key)
{

}

void hash_free(Hashtable* ht)
{

}

/* utility */

void resize(Hashtable* ht)
{
	int curr;
	int stepup;
	curr = ht->size;
	stepup = next_prime(curr);

}

int hash(const char* key)
{
	int acc;
	int len;
	int i;

	len = strlen(key);

	for(i = 0; i < len; i++)
	{
		/* pull valid range down */ 
		/* '48' is '0' in ASCII */
		acc += pow( key[i] - 47, i+1) 
	}

	return acc;
}

int next_prime(int curr)
{
	int next;

	for( next = curr + 1; !is_prime(next); ++next);

	return next;
}

int check_key(const char* key)
{
	char* c;
	c = key;

	while(*c)
	{
		/* only alphanumeric keys */
		if( !((*c > 47) && (*c < 58)) && /* numeric range */
			!((*c > 64) && (*c < 91)) && /* uc alpha range */
			!((*c > 96) && (*c < 123)) ) /* lc alpha range */
		{
			fprintf(stderr, "Hashtable: bad key\n");
			return 0;
		}
		++c;
	}

	return 1;
}

int is_prime(int x)
{
	int i;
	int ub;

	ub = (int)sqrt(curr);

	for(i = 2; i <= ub; i++)
	{
		if( x % i == 0 )
		{
			return 0;
		}
	}
	
	return 1;
}
