#include <stdio.h>

#define N 10

int A[N+1] = {0,10,9,6,3,7,1,2,8,5,4};  
int S = N;

void Max_Heap(int);
void Printf_A(void);

void Build_Max_Heap (void){
	int i, tmp;
	for(i = S/2; i > 0; i --){
		Max_Heap(i);
	}
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
		Printf_A();
	}
}

void Printf_A(void){
	int i;
	printf("\nArray\n");
	for(i=1; i<=N; i++)
		printf ("%d ", A[i]);
}

int main (void){
	Heapsort();
	Printf_A();
	return 0;
}
