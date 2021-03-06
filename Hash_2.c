#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 9

struct Object{
	int key;
	struct Object *next;
};

typedef struct Object obj;

obj *T[M] = {0};

int h (int k){
	float A = (sqrt(5)-1)/2, y = k*A;
	return M*(y - (int)y);
}


obj *Hash_Search(int k){
	obj *p;
	p = T[h(k)];
	while (p != NULL && p->key != k)
		p = p->next;
	return p;
}

void Hash_Insert ( int k ){
	obj *x;
	x = (obj *) malloc(sizeof(obj));
	x->key = k;
	x->next = T[h( x->key )];
	T[h( x->key )] = x;
}

void Hash_Delete( obj *x ){
	obj *head;
	head = T[h( x->key )];
	if ( head->key != x->key ){
		while ( x->key != head->next->key )
			head = head->next;
		head->next = x->next;
	}
	else		
		T[h( x->key )] = x->next;
	free(x);
}

void Print(void){
	obj *tmp1,*tmp2;
	int i = 0;
	while (i != M){
		printf ("%d    ",i);
		if (T[i] != NULL){
			tmp1 = T[i];
			while (tmp1 != NULL){
				printf ("->%d",tmp1->key);
				tmp1 = tmp1->next;
			}
		}
		printf ("\n");
		i++;
	}
	printf ("\n");
}

int main (void) {
	obj *key;
	Hash_Insert(1); //5
	Hash_Insert(4); //4
	Hash_Insert(16); //7
	Hash_Insert(9); //5
	Hash_Insert(18); //1
	Hash_Insert(27); //6
	
	Print ();
	
	key = Hash_Search (18);
	Hash_Delete (key);
	
	Print ();
	return 0;
} 
