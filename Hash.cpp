#include <stdio.h>
#include <math.h>
#define M 9

struct Object{
	int key;
	struct Object *next;
};

typedef struct Object obj;

obj *T[M] = {0};

int h1(int k){
	return k%M;
}

int h2 (int k){
	float A = (sqrt(5)-1)/2, y = k*A;
	return M*(y - int(y));
}
/*
obj *Hash_Search(int k){
	obj *p;
	p = T[h1(k)];
	while (p != NULL && p->key != k)
		p = p->next;
	return p;
}
*/
void Hash_Insert ( obj *x ){
	x->next = T[h1( x->key )];
	T[h1( x->key )] = x;
}
/*
void Hash_Delete( obj *x ){
	obj *head;
	head = T[h1( x->key )];
	if ( head != x->key )
		while ( x->key != head->next->key )
			head = head->next;
	free(x);
}
*/
void Print_Hash(){
	for ( int i = 0; i<M; i ++)
		printf("   %d", T[i]);
	printf ("\n");	
}

int main (void){
	Hash_Insert(4);
	Hash_Insert(16);
	Hash_Insert(25);
	Hash_Insert(9);
	Print_Hash;
	
	getchar();
	return 0;
}
