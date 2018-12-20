#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;

void List_Insert_Sort (int k){
	struct Object *p;
	struct Object *pk;
	pk = (struct Object *) malloc(sizeof(struct Object));
	p = head;
	int f = 0;
	pk->key = k;
	while (p->next != NULL && f == 0){
		if (k > p->key){
			pk->next = head;
			head = pk;
			f = 1;
		}else
			if (k > p->next->key){
				pk->next = p->next;
				p->next = pk;
				f = 1;
			}
		p = p->next;
	}
	if (p->next == NULL){
			pk->next = NULL;
			p->next = pk;
	}
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


int main (void){
	List_insert (3);            
	List_insert (4);            
	List_insert (9);           
	List_insert (16);        
	List_insert (10);
	List_print ();
	List_Insert_Sort (12);
	List_print ();
	getchar();
	return 0;
}
