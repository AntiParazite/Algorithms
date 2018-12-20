#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 9
#define TRUE 1
#define FALSE 0

int S[N+1] = {-1} ;
int topS = 0;
int lengthS = N;

int OVERFLOW (){
	if (topS > lengthS)
		return FALSE;
	else
		return TRUE;
}

int STACK_EMPTY(){
	if (topS == 0)
		return TRUE;
	else 
		return FALSE;
}
void Print_A(){
	
	for (int i = 1; i <= N; i++)
		printf("%d   ",S[i]);
    	printf ("\n");
    	
    for (int j = 1; j < topS; j++)	
		printf("    ");
	printf("  ^\n");
    	
    	   
}

void PUSH (int x){
	if (OVERFLOW()){
		topS++;
		S[topS] = x;
	}
	
	else {
		printf ("ERROR - OVERFLOW");
		exit (1);
	}
}

int POP(){
	if (STACK_EMPTY()){
		printf ("ERROR - EMPTY");
		exit (1);
	}
	else {
		topS--;
		return S[topS+1];
	}
}

int main (void){
	int x;
	
	PUSH (15);
	PUSH (6);
	PUSH (2);
	PUSH (9);
	Print_A();
	
	PUSH (17);
	PUSH (3);
	Print_A();
	
	x = POP();
	printf ("\n x = %d \n", x);
	Print_A();
	
	getchar();
	return 0;
}
