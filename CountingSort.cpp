#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define N 15
int A[N+1];

void Random(int);
void CountingSort(int);
void PrintArray(void);

int main(void){
	int k;
	printf("input k:");
	scanf("%d", &k);
	srand(time(0));
	Random(k);
	PrintArray();
	putchar('\n');
	CountingSort(k);
	putchar('\n');
	PrintArray();
	getch();
	return 0;
}

void Random(int k){
	short i;
	for(i=1;i<=N;i++)
		A[i]=rand()%k+1;
}

void CountingSort(int k){
	short i,j;
	int *B, *C;
	putchar('\n');
	printf("0");
	B=(int*)malloc((N+1)*sizeof(int));
	C=(int*)malloc((k+1)*sizeof(int));
	printf("1");
	for(i=1;i<=k;i++)
		C[i]=0;
	printf("2");
	for(j=1;j<=N;j++)
		C[A[j]]++;
	printf("3");
	for(i=2;i<=k;i++)
		C[i]=C[i]+C[i-1];
	printf("4");
	for(j=N;j>=1;j--){
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	printf("5");
	for(i=1;i<=N;i++)
		A[i]=B[i];
	printf("6");
	printf("7");
}

void PrintArray(){
	short i;
	for(i=1;i<=N;i++){
		printf("%d", A[i]);
		putchar('\n');
	}
	putchar('\n');
}
