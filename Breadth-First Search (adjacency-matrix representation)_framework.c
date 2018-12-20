/****************************************************************************/
/* Cormen, Leiserson, Rivest, Stein. Introduction to Algorithms, 2nd Ed.    */
/* Chapter 22. Elementary Graph Algorithms                                  */
/*         22.2 Breadth-first search                                        */
/* Written by Alexandr Bogatyrev                                01.12.2008  */
/****************************************************************************/
/* adjacency-matrix representation                                          */
/****************************************************************************/

#include <stdio.h>
#include <limits.h>                    // for INT_MAX

#define  N          8
#define  WHITE     'W'
#define  GRAY      'G'
#define  BLACK     'B'
#define  INFINITY  INT_MAX
#define  NIL       -1


int Adj[N][N];                         // adjacency matrix

int d[N],                              // distance from the source s
    pi[N],                             // predecessor or parent of vertex
    color[N],                          // color of vertex
    Q[N];                              // FIFO queue of gray vertices


void Create_Edge(int, int);
void Build_Graph();
void Print_Adjacency_Matrix();
void BFS(int);
void Print_Path(int, int);
int  Queue_Empty(void);
void Enqueue(int);
int  Dequeue();


int main(void) {
   int src;

   Build_Graph(Adj, N);
   Print_Adjacency_Matrix(Adj, N);

   src = 1;
   BFS(src);
   Print_Path(src, 7);

   return 0;
}


void Create_Edge(int u, int v) {
	Adj[u][v] = Adj[v][u] = 1;
}


void Build_Graph(int A[][N], int n) {

   printf(" Figure 22.3                                   \n");
   printf(" r --- s     t --- u      0 --- 1     2 --- 3  \n");
   printf(" |     |   / |   / |      |     |   / |   / |  \n");
   printf(" |     |  /  |  /  |      |     |  /  |  /  |  \n");
   printf(" |     | /   | /   |      |     | /   | /   |  \n");
   printf(" v     w --- x --- y      4     5 --- 6 --- 7  \n\n");
   	Create_Edge(4,0);
	Create_Edge(0,1);
	Create_Edge(1,5);
	Create_Edge(5,2);
	Create_Edge(5,6);
	Create_Edge(6,2);
	Create_Edge(2,3);
	Create_Edge(6,3);
	Create_Edge(3,7);
	Create_Edge(6,7);

}


void Print_Adjacency_Matrix(void) {
	int c;
	int k;
	printf("\n");
	int i;
	int j;
	printf("   |"); 
	for (i = 0,c = 114; i < N; i++,c++)
		printf(" %c |",c); 
	printf("\n----");

	for (i = 0; i < N; i++)
		printf("----"); 
		
	for(i = 0, c = 114; i< N; i++,c++){
		printf("\n");
		printf(" %c |", c);
		for(j = 0; j < N; j++)
			printf(" %d |", Adj[i][j]);
		printf("\n");
		printf("----");
		for (k = 0; k < N; k++){
			printf("----");	
		}
	}
	printf("\n\n");
	
}


// breadth-first search
void BFS(int s) {
	int i;
	int u;
	int v;
	int z;
	for (i = 0; i < N; i++){
		color[i] = WHITE;
		d[i] = INFINITY;
		pi[i] = NIL;
	}
	color[s] = GRAY;
	d[s] = 0;
	pi[s] = NIL;
	Enqueue (s);
	while (!Queue_Empty()){
		u = Dequeue();
		for (v = 0; v < N;v++){
			if (Adj[u][v] != 0)
				if (color[v] == WHITE){
					color[v] = GRAY;
					d[v] = d[u]+1;
					pi[v] = u;
					Enqueue (v);
				}
		}
		color[u] = BLACK;
	}
}


// prints out the vertices on a shortest path from s to v
void Print_Path(int s, int v){
	if (v == s)
		printf("->%d",s);
	else if (pi[v] == NIL)
			printf("Cannot build the way from %d to %d",s,v);
		else{ 	
			Print_Path(s,pi[v]);
			printf("->%d",v);
		}
}


#define  TRUE   1
#define  FALSE  0

int head = 0, tail = 0;                // head and tail of queue

int Queue_Empty(void) {
   if (head == tail)
      return TRUE;
   else
      return FALSE;
}


void Enqueue(int x) {
   Q[tail] = x;
   if (tail == N-1)
      tail = 0;
   else
      tail++;
}


int Dequeue() {
   int x;

   x = Q[head];
   if (head == N-1)
      head = 0;
   else
      head++;
   return x;
}
