#include <stdio.h>
#include <stdlib.h>

void List_insert (int k);
void List_insert1 (int k);

struct Object {
	int key;
	struct Object *next;
};

struct Object *head = NULL;
struct Object *head1 = NULL;

void List_Copy_Upwards (struct Object *p){
	if (p != NULL){
        List_Copy_Upwards (p->next);
		List_insert1 (p->key);
	}
}

void List_Copy_Backwards (struct Object *p){
	if (p != NULL){
		List_insert1 (p->key);
        List_Copy_Backwards (p->next);
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
void List_print1 (void){
	struct Object *p;
	p=head1;
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

void List_insert1 (int k){
	struct Object *p;
	p = (struct Object *) malloc(sizeof(struct Object));
	p->key = k;
	p->next = head1;
	head1 = p;
}

int main (void){
	List_insert (1);            List_print ();
	List_insert (4);            List_print ();
	List_insert (16);           List_print ();
	List_insert (9);            List_print ();
	List_Copy_Backwards (head);
	List_print1 ();
	printf ("\n");
//	List_Copy_Backwards (head);
//  List_print1 ();
	getchar();
	getchar();
	return 0;
}
