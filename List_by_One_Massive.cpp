#include <stdio.h>
#include <stdlib.h>

#define N 6

int List[N*3+1] = {-1,0,0,6,0,0,9,0,0,12,0,0,15,0,0,18,0,0,0};
int freeL = 3, head = NULL, x;

int List_Search(int);
void List_Insert(int);
void List_Delete(int);
void Print();
void Free_Object(int);
int Allocate_Object();

void printt(void){
	for (int i = 1; i < N*3+1; i++){
		printf ("%3d",List[i]);
		if (i % 3 == 0)
			printf ("     ");
	}
	printf ("\n");
}

int main(void){
	int key;
	
	List_Insert(4);
	List_Insert(16);
	List_Insert(25);
	List_Insert(9);
	
	Print();
	printt();
	getchar();
	
	key = List_Search(16);
	List_Delete (key);
	
	Print();
	printt();
	getchar();
	
	return 0;
}

int List_Search(int k){
	x = head;
	while(x != NULL && List[x-1] != k)
		x = List[x-2];
	return x;
}

void List_Insert(int k){
	x = Allocate_Object ();
	List[x-1] = k;
	List[x-2] = head;
	if(head != NULL)
		List[head] = x;
	head = x;
	List[x] = NULL;
}

void List_Delete(int x){
	if(List[x-2] != NULL)
		List[List[x-2]] = List[x];
	else
		head = List[x];
	if(List[x] != NULL)
		List[List[x]-2] = List[x-2];
	Free_Object(x);
}


void Print(void){
	int x = head;
	while (x != NULL){
		printf ("%5d",List[x-1]);
		x = List[x-2];
	}
	printf("\n");
}

void Free_Object(int x){
	List[x] = freeL;
	freeL = x;
}

int Allocate_Object(void){
	if(freeL != NULL){
		x = freeL;
		freeL = List[x];
	}
	else{
		printf("error: out of space\n");
	}
	return x;
}

