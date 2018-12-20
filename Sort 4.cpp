#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define N 10
#define INFINITY -INT_MAX

int A[N+1] = { -1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };  
int S = N;
int key = 1;

void Max_Heap(int);
void Print_Array(void);
int Heap_Maximum (void);
int Heap_Extract_Max (void);
void Heap_Increase_Key(int, int);
int PARENT(int);
void Max_Heap_Insert(int);

int Heap_Maximum (void){
	return A[1];
}

int Heap_Extract_Max (void){
	int max;
	if (S < 1){
		printf ("Error");
		exit (1);
	}
	max = A[1];
	A[1] = A[S];
	S--;
	Max_Heap(1);
	return max;
}

void Heap_Increase_Key(int i, int key){
	int tmp;
	if (key < A[i]){
		printf ("New key more than that");
		exit (1);
	}
	A[i]=key;
	while (i>1 && A[PARENT(i)] < A[i]){
		tmp = A[i];
		A[i] = A [PARENT(i)];
		A[PARENT(i)] = tmp;
		i = PARENT(i);
	}
}

void Max_Heap_Insert(int key){
	
	S++;
	A[S] = INFINITY;
	Heap_Increase_Key (S, key);
}

void Build_Max_Heap (void){
	int i, tmp;
	for(i = S/2; i > 0; i --){
		Max_Heap(i);
	}
}

int PARENT (int i){
	return i/2;
}

int LEFT (int i){
	return i*2;
}

int RIGHT (int i){
	return i*2+1;
}

void Max_Heap (int i){
	int largest, tmp;
	int l=LEFT(i);
	int r=RIGHT(i);
	if(l <= S && A[l]>A[i])
		largest= l;	
	else
		largest= i;
	if(r <= S && A[r]>A[largest])
		largest= r;
	if(largest!= i){
		tmp= A[i];
		A[i]= A[largest];
		A[largest]= tmp;
		Max_Heap(largest);
	}		
}

void Heapsort(void){
	int i, tmp;
	for(i=N; i>=2; i--){
		Build_Max_Heap();		
		tmp= A[1];
		A[1]= A[S];
		A[S]= tmp;
		S--;
		Print_Array();
	}
}

void Print_Array(void){
	int i;
	printf("\nArray\n");
	for(i=1; i<=N; i++)
		printf ("%4d", A[i]);
}
void Print_Max_Heap(void) {
   int i;

   for (i=1; i <= N; i++)
      printf("%4d", A[i]);
   putchar('\n');
}

int main(void) {
   int i;

   Print_Array();
   Build_Max_Heap();
   Print_Array();

   Heap_Increase_Key(9, 15);                // Figure 6.5
   Print_Max_Heap();

   i = Heap_Extract_Max();
   printf("Extract element with largest key <- %d\n", i);
   Print_Max_Heap();

   i = Heap_Extract_Max();
   printf("Extract element with largest key <- %d\n", i);
   Print_Max_Heap();

   i = Heap_Extract_Max();
   printf("Extract element with largest key <- %d\n", i);
   Print_Max_Heap();

   Max_Heap_Insert(12);
   printf("Insert element 12\n");
   Print_Max_Heap();

   getchar();
   return 0;
}
