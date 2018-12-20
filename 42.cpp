#include <stdio.h>
#include <stdlib.h>

struct Object {
	int key;
	struct Object *next;
};

struct Object *head1 = NULL;
struct Object *head2 = NULL;

void add_sort ();
void add_sort2 ();

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
}

void List_insert2 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head2;
	head2 = p;
}

void concatenatio (){
	struct Object *p;
	p = head2;
	while (p->next != NULL)
		p = p->next;
	p->next = head1;
	head1 = head2;
}

void Sort_list1 (void){
	struct Object *p;
	p = head1;
	while (p != NULL){
		add_sort ();
		p = p->next;
	}
}

void Sort_list2 (void){
	struct Object *p1, *p2;
	int tmp;
	p1 = head2;
	p2 = head2;
	while (p1 != NULL){
		add_sort2 ();
		p1 = p1->next;
	}
}

void add_sort2 (){
	struct Object *p;
	int tmp;
	p = head2;
	while (p->next != NULL){
			if (p->key < p->next->key){
				tmp = p->key;
				p->key = p->next->key;
				p->next->key = tmp;
			}
			p = p->next;
		}
}

void add_sort (){
	struct Object *p;
	int tmp;
	p = head1;
	while (p->next != NULL){
			if (p->key < p->next->key){
				tmp = p->key;
				p->key = p->next->key;
				p->next->key = tmp;
			}
			p = p->next;
		}
}

void Sort_list (void){
	struct Object *p;
	p = head1;
	while (p != NULL){
		add_sort ();
		p = p->next;
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
	
	Sort_list1 ();
	List_print1 ();
	
	Sort_list2 ();
	List_print2 ();
	
	concatenatio ();
	List_print1 ();
	
	Sort_list ();
	List_print1 ();
	getchar();
	return 0;
}
