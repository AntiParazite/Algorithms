#include <stdio.h>
#include <stdlib.h>

#define N 12

int Q[N+1] = {-1} ;
int headQ = 1, tailQ = 1;
int lengthQ = N;

int QUEUE_OVERFLOW (){
	if ( ( headQ == tailQ+1 ) || ( tailQ == N && headQ == 1 ) )
		return true;
	else
		return false;
}

int QUEUE_EMPTY(){
	if ( tailQ == headQ )
		return true;
	else 
		return false;
}
void Print_A(){
	
	for ( int i = 1; i <= N; i++ )
		printf ( "%4d",Q[i] );
    printf ( "\n" );
    	
    for ( int j = 1; j <= lengthQ; j++ )	
		if ( j == headQ )
			printf ( "   h" );
		else if ( j == tailQ )
			printf ( "   t" );
		else 
			printf ( "    " );
    	printf ( "\n" );
}

void ENQUEUE (int x){
	if ( QUEUE_OVERFLOW() ){
		printf ( "ERROR - OVERFLOW" );
		exit (1);			
	}
	
	else{
		Q[tailQ] = x;
		if (tailQ == lengthQ)
			tailQ = 1;
		else 
			tailQ++;
	}
}

int DEQUEUE(){
	int x;
	if ( QUEUE_EMPTY() ){
		printf ( "ERROR - EMPTY" );
		exit (1);
	}
	else{
		x =  Q[headQ];
		if (headQ == lengthQ)
			headQ = 1;
		else
			headQ++;
		return x;
	}
}

int main (void){
	int x;
	
	ENQUEUE(0);
	ENQUEUE(0);
	ENQUEUE(0);
	ENQUEUE(0);
	ENQUEUE(0);
	ENQUEUE(0);
	ENQUEUE(15);
	ENQUEUE(6);
	ENQUEUE(9);
	ENQUEUE(8);
	ENQUEUE(4);
	x = DEQUEUE();
	x = DEQUEUE();
	x = DEQUEUE();
	x = DEQUEUE();
	x = DEQUEUE();
	x = DEQUEUE();
	Print_A();
	
	ENQUEUE(17);
	ENQUEUE(3);
	ENQUEUE(5);
	Print_A();
	
	x = DEQUEUE();
	printf ("x = %d \n", x);
	Print_A();
	getchar ();
}
