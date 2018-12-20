#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 10
#define DEL -1

int T[M] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int c1 = 1, c2 = 3;

int h1(int k){
	return k%M;
}

int h2(int k){
	return 1 + ( k%(M - 1) );
}

int h(int k, int i){
	return ( h1(k) + i )%M;
}


int Hash_Search( int k ){
	int i = 0;
	int j = h(k,i);
	while (T[j] != DEL && i != M){
		j = h(k,i);
		if (T[j] == k)
			return j;
		i++;	
	}
	return NULL;
}

int Hash_Insert ( int k ){
	int i = 0;
	int j;
	while ( i != M ){
		j = h(k,i);
		if (T[j] == DEL){
			T[j] = k;
			return j;
		}
		else
			i++;	
	}
	printf ("ERROR!!! Hash-Table is overflow");
	exit(1);
}

void Hash_Delete( int x ){
	T[x] = -1;
}

void Print(void){
	int i = 0;
	while (i != M){
		printf (" %d |  ",i);
		if (T[i] != DEL)
				printf ("->%d  ",T[i]);
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
	
	int key = Hash_Search(10);
	Hash_Delete(key);
	
	Print();
	
	Hash_Insert(10);
	Print();
	
	return 0;
} 
