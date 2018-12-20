#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 16

int A[N]={5,4,2,7,1,6,3,8,10,99,44,33,24,13,11,18};

void printf_A();

void Shell_Sort(void){
	int i,j,k;
	int tmp;
	for(k = N/2; k > 0; k /=2)
        for(i = k; i < N; i+=1)
        {
            tmp = A[i];
            for(j = i; j>=k; j-=k)
            {
                if(tmp < A[j-k])
                    A[j] = A[j-k];
            	else
                    break;
            }
            A[j] = tmp;
            printf("\n*** %d ***\n\n",j);
            printf_A();
            printf ("\n");
        }
        
}

void printf_A(){
	int i;
	for(i=0;i<N;i++){
		printf("%d", A[i]);
		printf(" ");
	}
}
int main(void){
	Shell_Sort();
//	printf_A();
	getch();
	return 0;
}

