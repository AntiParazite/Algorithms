#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <stdlib.h>

#define N 8
#define Q INT_MAX

int A[N]={2,4,5,7,1,2,3,6}, p=0, r=N-1;

void Merge_Sort(int,int);
void Merge(int, int, int);
void printf_Array(void);

int main(void){
	printf_Array();
	Merge_Sort(p,r);
	printf_Array();
	getch();
	return 0;
}

void Merge_Sort(int p, int r){
	int q;
	if(p<r){
	   q=(p+r)/2;
	   Merge_Sort(p,q);
	   Merge_Sort(q+1,p);
	   Merge(p,q,r);
    }
}

void Merge(int p, int q, int r){
	int *L, *R;
	int i,j;
	int key;
	int n1, n2;
	n1=q-p+1;
	n2=r-q;
	L=(int *)malloc((n1+2)*sizeof(int));
	R=(int *)malloc((n2+2)*sizeof(int));
	for(i=1;i<=n1;i++)
	   L[i]=A[p+i-1];
	for(j=1;j<=n2;j++)
	   R[j]=A[q+j];
	L[n1+1]=Q;
	R[n2+1]=Q;
	j=1;
	i=1;
	for(key=p;key<=r;key++){
	   if(L[i]<=R[j]){
	   	   A[key]=L[i];
	   	   i++;
	   }
	   else{
	      A[key]=R[j];
	      j++;
	   }
	   putchar('\n');
	   printf_Array();
    }
    putchar('\n');
    free(R);
    free(L);
}

void printf_Array(){
	short i;
	for(i=0;i<N;i++){
		printf("%d", A[i]);
	}
	putchar('\n');
}
