//очередь использу€ один св€знyый список
#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;
struct Object *tail = NULL;

int Overflow(void){
	struct Object *p; 	
	if (p != NULL)
		return true;
	else
		return false;
}

int Empty(void){
	if (head != NULL)
		return true;
	else 
		return false;
}

void Print (void){
	struct Object *p;
	p = head;
	while (p != NULL){
		printf ("%4d",p->key);
		p = p->next;
	}
	printf ("\n");
	p = head;
	while (p != NULL){
	if (p == head)
		printf ("   h");
	else if (p == tail)
		printf ("   t");
		else
		printf ("    ");
	p = p->next;
		}
	printf ("\n");
}

void Enqueue (int k){
	if (Overflow ()){
	struct Object *p, *pp;
	p = (struct Object *) malloc(sizeof(struct Object));
	if (head == NULL){
		head = p;
	}
	tail->next = p;
	p->key = k;
	p->next = NULL;
	tail = p;
	}
	else {
		printf ("Overflow");
		exit (1);
	}
}

void Dequeue (){
	if (Empty()){
	struct Object *p;
	p = head;
	head = p->next;
	free (p);
	}
	else {
		printf ("Empty");
		exit (1);
	}
}

int main (void){
	Enqueue (1);           
	Print ();
	
	Enqueue (4);          
	Print ();
	
	Enqueue (16);          
	Print ();
	
	Enqueue (9);           
	Print ();  
	
	Dequeue ();            
	Print ();
	
	getchar();
	return 0;
}
