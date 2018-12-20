#include <stdio.h>
#include <stdlib.h>
 
struct bucket{
    int count;
    int* value;
};
 
int compareIntegers(const void* first, const void* second){
    int x = *((int*)first), y =  *((int*)second);
    if (x == y){
        return 0;
    }
    else if (x < y){
        return -1;
    }
    else{
        return 1;
    }
}
 
void bucketSort(int array[],int n){
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++){
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++){
        if (array[i] < 0){
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10){
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else{
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}

void printArray(int A[], int size){ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 
 
int main(void) { 
    int arr[] = { 5, -34, 10, 1, -42, 123, 2, 395, 5, 4, 1234, 7 };
    int arr_size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_size); 
    bucketSort(arr, arr_size);  
	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
 
}
