#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;
struct Object *tail = NULL;

void Print (void){
	struct Object *p;
	p = head;
	while (p != NULL){
		printf ("%5d",p->key);
		p = p->next;
	}
	printf ("\n");
	p = head;
	while (p != NULL){
	if (p == head)
		printf ("    h");
	else if (p == tail)
		printf ("    t");
		else
		printf ("     ");
	p = p->next;
		}
	printf ("\n");
}

void Enqueue (int k){
	struct Object *p, *pp;
	p = (struct Object *) malloc(sizeof(struct Object));
	if (head == NULL){
		head = p;
		tail = p;
	}
	tail->next = p;
	p->key = k;
	p->next = NULL;
	tail = p;
}

void Dequeue (){
	struct Object *p;
	p = head;
	head = p->next;
	free (p);
}

int main (void){
	Enqueue (1);           Print ();
	Enqueue (4);           Print ();
	Enqueue (16);          Print ();
	Enqueue (9);           Print ();  
	Dequeue ();            Print ();
	getchar();
	return 0;
}
