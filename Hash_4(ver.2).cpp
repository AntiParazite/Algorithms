#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 11
#define NIL 0

int T[M] = {-1};
int c1 = 1, c2 = 3;

int h1(int k){
	return k%M;
}

int h2(int k){
	return 1 + ( k%(M - 1) );
}

int h(int k, int i){
	return (h1(k) + i)%M;
}

int hh(int k, int i){
	return (h1(k) + c1*i + c2*i*i)%M;
}

int hhh(int k, int i){
	return (h1(k) + i*h2(k))%M;
}

int Hash_Insert ( int k ){
	int i = 0;
	int j;
	while ( i != M ){
		j = h(k,i);
		if (T[j] == NIL){
			T[j] = k;
			return j;
		}
		else
			i++;	
	}
	printf ("ERROR!!! Hash-Table is overflow");
	exit(1);
}

int Hash_Search( int k ){
	int i = 0;
	int j = h(k,i);
	for (i = 0; i != M,T[j] != NIL; i++){
		if (T[j] == k)
			return j;
		j = h(k,i);	
	}
	return NIL;
}

void Hash_Delete( int x ){
	T[x] = NIL;
}

void Print(void){
	int i = 0;
	while (i != M){
		printf (" %d    ",i);
		if (T[i] != NIL){
				printf ("-> %d ",T[i]);
		}
		printf ("\n");
		i++;
		printf ("----|-----------|");
		printf ("\n");
	}
	printf ("\n\n");
}

int main (void) {
	int key;
	
	Hash_Insert(10);
	Hash_Insert(22);
	Hash_Insert(31);
	Hash_Insert(4);
	Hash_Insert(15);
	Hash_Insert(28);
	Hash_Insert(17);
	Hash_Insert(88);
	Hash_Insert(59);
	Print();
	
	key = Hash_Search(88);
	Hash_Delete(key);
	Print();
	
	getchar ();
	return 0;
} 
