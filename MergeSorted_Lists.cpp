#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head1 = NULL;
struct Object *head2 = NULL;
struct Object *head3 = NULL;

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

void List_print3 (void){
	struct Object *p;
	p=head3;
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
}

void List_insert2 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head2;
	head2 = p;
}

void List_insert3 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head3;
	head3 = p;
}

void Sort_list (void){
	struct Object *p1, *p2;
	p1 = head1;
	p2 = head2;
	while (p1 != NULL && p2 != NULL)
		if (p1->key > p2->key){
			List_insert3 (p2->key);
			p2 = p2->next;
		}
		else{
			List_insert3 (p1->key);
			p1 = p1->next;
		}
	while (p1 == NULL && p2 != NULL){
		List_insert3 (p2->key);
		p2 = p2->next;
	}
	while (p1 != NULL && p2 == NULL){
		List_insert3 (p1->key);
		p1 = p1->next;
	}
}

int main (void){
	List_insert1 (16);            
	List_insert1 (9);            
	List_insert1 (4);           
	List_insert1 (1);
	List_print1 ();
	
	List_insert2 (10); 			 
	List_insert2 (6);			
	List_insert2 (2);
	List_print2 ();
	
	Sort_list ();
	List_print3 ();
	getchar();
	return 0;
}
