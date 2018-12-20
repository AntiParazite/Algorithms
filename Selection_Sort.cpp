#include <stdio.h>
#define N 8

int Array[N] = {-5,1,12,5,16,2,12,14};
int i,j;

void Selection_Sort(void) { 
      int  minIndex, tmp;
      for (i = 0; i < N; i++) {
            minIndex = i;
            for (j = i + 1; j < N; j++)
                  if (Array[j] < Array[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = Array[i];
                  Array[i] = Array[minIndex];
                  Array[minIndex] = tmp;
            }
      }
}

void Print_Array(void){
	int i;
    for (i=0; i < N; i++)
       printf("%4d", Array[i]);
}

int main (void){
	Selection_Sort();
	Print_Array();
	getchar();
	return 0;
}
