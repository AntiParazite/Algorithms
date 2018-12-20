#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;
struct Object *tail = NULL;

int Overflow(struct Object *p){

	if (p == NULL)
		return true;
	else
		return false;
}

int Empty(void){
	if (head == NULL)
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
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	
	if (!Overflow (p)){
		if (head == NULL){
			head = p;
			tail = p;
		}
		tail->next = p;
		p->key = k;
		p->next = NULL;
		tail = p;
	}
	else {
		printf ("Stack Overflow");
		exit (1);
	}
}

int Dequeue (){
	struct Object *p;
	int x;
	if (!Empty()){
		p = head;
		head = p->next;
		x = p->key;
		free (p);
		return x;
	}
	else {
		printf ("Stack Empty");
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
	
	int x = Dequeue ();  
	printf ("\n   x = %d\n\n", x);   
	Print ();
	
	getchar();
	return 0;
}
