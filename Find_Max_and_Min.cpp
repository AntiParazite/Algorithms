#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 9

int A[N] = {9,10,11,8,3,7,1,5,4};
int i;
int max, min;

void Find_Max_and_Min (void){
	
	if (N % 2 == 1){
		
		max = A[0];
		min = A[0];
		
		for (i = 1; i < N; i+=2){
			
			if (A[i] > A[i+1]){
				
				if (A[i+1] < min)
					min = A[i+1];
				
				if (A[i] > max)
					max = A[i];
			}
			
			if (A[i] < A[i+1]){
				
				if (A[i] < min)
					min = A[i];
				
				if (A[i+1] > max)
					max = A[i+1];
			}
		}
	}
	
	if (N % 2 == 0){
		
		max = - INF;
		min = INF;
		
		for (i = 0; i < N; i += 2){
			
			if (A[i] > A[i+1]){
				
				if (A[i+1] < min)
					min = A[i+1];
				
				if (A[i] > max)
					max = A[i];
			}
			
			if (A[i] < A[i+1]){
				
				if (A[i] < min)
					min = A[i];
				
				if (A[i+1] > max)
					max = A[i+1];
			}	
		}
	}
	
	printf ("\nmax = %d", max);
	printf ("\nmin = %d", min);
	
}

void Print_A(){
   
   for (i = 0; i < N; i++){
      printf("%d ",A[i]);
   }
   
   printf("\n");
}

int main (void){
	Print_A();
	Find_Max_and_Min();
	getchar();
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                        
