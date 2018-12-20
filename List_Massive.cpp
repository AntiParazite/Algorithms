#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NIL 0
#define N 8

int next[N+1] = {-1, 2, 3, 4, 5, 6, 7, 8, 0}, key[N+1];
int prev[N+1];
int freeL = 1, headL = NIL, x;

int List_Search(int);
void List_Insert(int);
void List_Delete(int);
void Print();
void Free_Object(int);
int Allocate_Object();

int main(void){
	int key;
	List_Insert(4);
	List_Insert(16);
	List_Insert(25);
	List_Insert(9);
	Print();
	key = List_Search(16);
	List_Delete (key);
	Print();
	getch ();
	return 0;
}

int List_Search(int k){
	x = headL;
	while(x != NIL && key[x] != k)
		x = next[x];
	return x;
}

void List_Insert(int k){
	x = Allocate_Object ();
	key[x] = k;
	next[x] = headL;
	if(headL != NIL)
		prev[headL] = x;
	headL = x;
	prev[x] = NIL;
}

void List_Delete(int x){
	if(prev[x] != NIL)
		next[prev[x]] = next[x];
	else
		headL = next[x];
	if(next[x] != NIL)
		prev[next[x]] = prev[x];
	Free_Object(x);
}

void Print(void){
	int x = headL;
	while (x != NIL){
		printf ("%5d",key[x]);
		x = next[x];
	}
	printf("\n");
}

void Free_Object(int x){
	next[x] = freeL;
	freeL = x;
}

int Allocate_Object(void){
	if(freeL != NIL){
		x = freeL;
		freeL = next[x];
	}
	else{
		printf("error: out of space\n");;
	}
	return x;
}

