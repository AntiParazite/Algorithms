#include <stdio.h>
#define N 5

int Array[N] = {-5,7,2,16,4};
int i,j;

void Insertion_Sort() {
    int tmp;
    for (i = 1; i < N; i++) {
	j = i;
        while (j > 0 && Array[j - 1] > Array[j]) {
        tmp = Array[j];
        Array[j] = Array[j - 1];
        Array[j - 1] = tmp;
        j--;	
        }
    }
}

void Print_Array(void){
	int i;
    for (i=0; i < N; i++)
       printf("%4d", Array[i]);
    printf("\n");   
}

int main (void){
	Insertion_Sort();
	Print_Array();
	getchar();
	return 0;
}
