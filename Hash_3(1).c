#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define M 6

struct Object{
	int key;
	struct Object *next;
};

typedef struct Object obj;

obj *T[M] = {0};
int p = 17;

int h(int k, int a, int b){
	return ((a*k+b)%p)%M;
}

obj *Hash_Search(int k ,int a,int b){
	obj *p;
	p = T[h(k, a,b)];
	while (p != NULL && p->key != k)
		p = p->next;
	return p;
}

void Hash_Insert ( int k, int a, int b  ){
	obj *x;
	x = (obj *) malloc(sizeof(obj));
	x->key = k;
	x->next = T[h( x->key ,a,b )];
	T[h( x->key ,a,b )] = x;
}

void Hash_Delete( obj *x ,int a, int b){
	obj *head;
	head = T[h( x->key , a,b)];
	if ( head->key != x->key ){
		while ( x->key != head->next->key )
			head = head->next;
		head->next = x->next;
	}
	else		
		T[h( x->key,a,b )] = x->next;
	free(x);
}

void Print(void){
	obj *tmp1,*tmp2;
	int i = 0;
	while (i != M){
		printf (" %d |  ",i);
		if (T[i] != NULL){
			tmp1 = T[i];
			while (tmp1 != NULL){
				printf ("->%d  |",tmp1->key);
				tmp1 = tmp1->next;
			}
		}
		else
			printf ("     |");
		printf ("\n");
		i++;
		printf ("---|-------|");
		printf ("\n");
	}
	printf ("\n");
}

int main (void) {
	srand( time(NULL) );
	int a = rand()%(p-1), b = 1 + rand()%(p-1);
	obj *key;
	Hash_Insert( 89, a, b );

/*	Hash_Insert(4);
	Hash_Insert(16);
	Hash_Insert(9);
	Hash_Insert(18);
	Hash_Insert(27);
*/	

	Print();
	printf("a = %d\nb = %d",a,b);
/*	
	key = Hash_Search(18);
	Hash_Delete(key);
	
	Print();*/
	return 0;
} 

