#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head1 = NULL;
struct Object *head2 = NULL;

void List_print1 (void){
	struct Object *p;
	p=head1;
	while (p != NULL){
		printf ("->%d",p->key);
		p = p->next;
	}
	printf ("\n");
}

void List_print2 (void){
	struct Object *p;
	p=head2;
	while (p != NULL){
		printf ("->%d",p->key);
		p = p->next;
	}
	printf ("\n");
}

void List_insert1 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head1;
	head1 = p;
	free(p);
}

void List_insert2 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head2;
	head2 = p;
	free(p);
}

void concatenatio (){
	struct Object *p;
	p = head2;
	while (p->next != NULL)
		p = p->next;
	p->next = head1;
	head1 = head2;
}

int main (void){
	List_insert1 (1);            
	List_insert1 (4);            
	List_insert1 (16);           
	List_insert1 (9);            List_print1 ();
	List_insert2 (2); 			 
	List_insert2 (6);			
	List_insert2 (10);           List_print2 ();
	
	concatenatio ();
	List_print1 ();
	
	getchar();
	return 0;
}
