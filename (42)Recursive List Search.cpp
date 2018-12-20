#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;

struct Object * Recursive_List_Search (struct Object *p, int key){
	if (p != NULL && p->key != key)
		return Recursive_List_Search (p->next, key);
	else return p;
}

void List_print (void){
	struct Object *p;
	p=head;
	while (p != NULL){
		printf ("->%d",p->key);
		p = p->next;
	}
	printf ("\n");
}

void List_insert (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head;
	head = p;	
}

struct Object * List_search (int k){
	struct Object *p;
	p = head;
	while (p->key != k && p != NULL)
		p = p->next;
	return p;
}

void List_delete (struct Object *k){
	struct Object *p, *pprev;
	p = head;
	while (p->key != k->key && p != NULL){
		pprev = p;
		p = p->next;
	}
	if (p == head)
		head = p->next;
	else
		pprev->next = p->next;
	free (p);	
}

int main (void){
	struct Object *key;
	List_insert (1);            List_print ();
	List_insert (4);            List_print ();
	List_insert (16);           List_print ();
	List_insert (9);            List_print ();
	key = Recursive_List_Search (head, 4); 
	List_delete (key);          List_print ();
	getchar();
	return 0;
}
