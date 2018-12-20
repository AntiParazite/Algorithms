#include <stdio.h> 
#include <string.h> 
#include <math.h>
#define d 256 

void Rabin_Karp(char pattern[], char text[], int q){ 
    int M = strlen(pattern); 
    int N = strlen(text); 
    int i, j; 
    int p = 0; 
    int t = 0; 
   // int h = pow(d,(M-1))%q;
	int h = 1; 
    for (i = 0; i < M-1; i++) 
    	h = (h*d)%q; 
    for (i = 0; i < M; i++){ 
        p = (d*p + pattern[i])%q; 
        t = (d*t + text[i])%q; 
    } 
    for (i = 0; i <= N - M; i++){ 
        if ( p == t ){
            for (j = 0; j < M; j++){ 
                if (text[i+j] != pattern[j]) 
                    break; 
            } 
            if (j == M) 
                printf("Pattern found at index %d \n", i); 
        }  
        if ( i < N-M ){ 
            t = (d*(t - text[i]*h) + text[i+M])%q; 
            if (t < 0) 
            	t = (t + q); 
        } 
    } 
} 

void search(char pattern[], char text[]){ 
    int M = strlen(pattern); 
    int N = strlen(text); 
    for (int i = 0; i <= N - M; i++){ 
        int j; 
        for (j = 0; j < M; j++) 
            if (text[i + j] != pattern[j]) 
                break;   
        if (j == M)
            printf("Pattern found at index %d \n", i); 
    } 
} 

int main(void){ 
    char text[] = "GEEKS FOR GEEKS"; 
    char pattern[] = "GEEK"; 
    int q = 101;
    printf("***Rabin-Karp algorithm***\n\n"); 
    Rabin_Karp(pattern, text,q);
    printf("\n***Naive string-matching***\n\n"); 
    search(pattern, text); 
    return 0; 
} 
