//Radix Sort
#include <stdio.h>
#include <stdlib.h>
#define N 9

void Countin_Sort(int p);
void Print_A();
void Radix_Sort (void);

int A[N+1]={33, 51, 19, 40, 22, 29, 56, 83, 11, 12};
int n=9;
int d = 2;
int x;

int main(void){
 	Print_A();
 	printf("\n");
 	Radix_Sort();
 	Print_A();
 	getchar();
 	return 0;
}

void Radix_Sort (void){
	int p = 1;
	for (int i = 0;i <= d; i++){
		Countin_Sort(p);
		p*=10;
	}
}

void Countin_Sort(int p){
 	int i,j;
	int *B,*C;
 	B=(int*)malloc((N+1)*sizeof(int));
 	C=(int*)malloc((9+1)*sizeof(int));
 	
	for(i=0;i<=9;i++)
 	     C[i]=0;    
 	
     for(j=1;j<=N;j++){
 		x = A[j]/p%10;
 	    C[x]=C[x]+1;
 	}
 	
     for(i=2;i<=9;i++)
 	    C[i]=C[i]+C[i-1];   
 	
     for(j=N;j>=1;j--){
 		x = A[j]/p%10;
 	 	B[C[x]]=A[j];
 	 	C[x]=C[x]-1;
	}
	
    for(i=1;i<=N;i++)
		A[i]=B[i];
	
    free(B);
	free(C);
}

void Print_A() {
   int i;
   for (i=1; i <=N; i++){
      printf("%d ",A[i]);
   }
   printf("\n");
}
