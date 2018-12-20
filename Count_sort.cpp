#include<stdio.h>
#include<stdlib.h>
#define N 12

void Count_Sort(void);
void Print_A();

int A[N+1]={13, 19, 3, 5, 12, 8, 7, 4, 11, 2, 6, 21, 18};
int k=21,n=12;

int main(void){
 	Print_A();
 	printf("\n");
 	Count_Sort( );
 	Print_A();
 	getchar();
 	return 0;
}

void Count_Sort(void){
 	int i,j;
	int *B,*C;
 	B=(int*)malloc((n+1)*sizeof(int));
 	C=(int*)malloc((k+1)*sizeof(int));
	for(i=1;i<=k;i++)
 	     C[i]=0;
 	for(j=1;j<=n;j++)
 	    C[A[j]]=C[A[j]]+1;
 	for(i=2;i<=k;i++)
 	    C[i]=C[i]+C[i-1];
 	for(j=n;j>=1;j--){
 	 	B[C[A[j]]]=A[j];
 	 	C[A[j]]=C[A[j]]-1;
	}
	for(i=1;i<=N;i++)
		A[i]=B[i];
	free(B);
	free(C);
}

void Print_A() {
	int i;
    for (i=1; i <=N; i++){
       printf("%4d", A[i]);
    }
}
