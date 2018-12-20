#include <stdio.h>
#include <clocale>
#include <stdlib.h>
#include <time.h>
#define N 9

int A[N + 1] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
int i;

int Randomized_Select (int , int , int);
int Randomized_Partition (int , int);

int Randomized_Select (int p, int r, int i){
	int k, q;
	
	if (p == r)
		return A[p];
	
	q = Randomized_Partition(p, r);
	k = q - p + 1;
	
	if (i == k)
		return A[q];
	else if (i < k)
		return Randomized_Select(p, q-1, i);	
	else 
		return Randomized_Select(q+1, r, i - k);	
}	

int Partition(int p, int r){
	int x, j, tmp;
	x = A[r];
	i = p - 1;
	for(j = p; j <= r-1; j++){
		if(A[j] < x){
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
    }
	tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	return i + 1;
}

int Random(int p, int r){
	return p + rand()%(r - p + 1);
}

int Randomized_Partition(int p, int r){
	int i, tmp;
	i = Random(p, r);
	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;
	return Partition(p, r);
}

int main(void){
	srand(time(0));
	int k, p, r;
	i = 3;
	printf("massiv v nachale: \n");
	for(k = 0; k <= N; k++)
		printf("%d  ", A[k]);
		
	printf("\nresult = %d", Randomized_Select(0, N, i));
}
