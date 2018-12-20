#include <stdio.h>
#include <stdlib.h>

typedef struct Object obj;

struct Object {
	int key;
	struct Object *next;
	struct Object *prev;
};

obj *head = NULL;

void LIST_PRINT (void){
	obj *p;
	p=head;
	while ( p != NULL ){
		printf ("->%d",p->key);
		p = p->next;
	}
	printf ("\n");
}

void LIST_INSERT (int k){
	obj *p;
	p = (obj *) malloc(sizeof(obj));
	p->key = k;
	p->next = head;
	p->prev = NULL;
	if (head != NULL)
		head->prev = p;
	head = p;
	LIST_PRINT();
}

obj * LIST_SEARCH (int k){
	obj *p;
	p = head;
	while ( p->key != k && p != NULL )
		p = p->next;
	return p;
}

void LIST_DELETE (obj *x){
	
	if ( x->prev != NULL )
		x->prev->next = x->next; 
	else
		head = x->next;
		
	if ( x->next != NULL )
		x->next->prev = x->prev;
	
	free(x);
	LIST_PRINT ();
}

int main (void){
	struct Object *key;
	LIST_INSERT(1);
	LIST_INSERT(4);
	LIST_INSERT(16);
	LIST_INSERT(9);
	key = LIST_SEARCH(1);
	LIST_DELETE(key);
	getchar ();
}
