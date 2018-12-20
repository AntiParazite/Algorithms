#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;

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
		printf ("->%d",p->key);
		p = p->next;
	}
	printf ("\n");
}

void Push (int k){
	if (Overflow ()){
		struct Object *p;
		p = (struct Object *) malloc(sizeof(struct Object));
		p->key = k;
		p->next = head;
		head = p;
	}
	else{
		printf ("Overflow");
		exit(1);
	}
}

void Pop (void){
	if (Empty ()){
		struct Object *p;
		p = head;
		head = p->next;
		free (p);
	}
	else{
		printf ("Empty");
		exit (1);
	}
}

int main (void){
	struct Object *key;
	Push (1);            
	Print ();
	
	Push (4);            
	Print ();
	
	Push (16);           
	Print ();
	
	Push (9);            
	Print ();   
	
	Pop ();              
	Print ();

	
	getchar();
	return 0;
}
