/****************************************************************************/
/* Cormen, Leiserson, Rivest, Stein. Introduction to Algorithms, 2nd Ed.    */
/* Chapter 22. Elementary Graph Algorithms                                  */
/*         22.2 Breadth-first search                                        */
/* Written by Alexander Bogatyrev                               26.05.2009  */
/****************************************************************************/
/* adjacency-list representation                                            */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>                    // for malloc()
#include <limits.h>                    // for INT_MAX

#define  N          8
#define  WHITE     'W'
#define  GRAY      'G'
#define  BLACK     'B'
#define  INFINITY  INT_MAX
#define  NIL       -1

int head = 0, tail = 0;                // head and tail of queue

struct elem {                          // an element in the list
   int vert;                           // vertex v of edge (u,v)
   struct elem *next;
};

struct elem *Adj[N];                   // array Adj consists |V| lists,
                                       // one for each vertex in V
int d[N],                              // distance from the source s
    pi[N],                             // predecessor or parent of vertex
    color[N],                          // color of vertex
    Q[N];                              // FIFO queue of gray vertices


void Create_Edge(int u, int v);
void Build_Graph(void);
void Print_Adjacency_List(void);
void BFS(int);
void Print_Path(int, int);
int  Queue_Empty(void);
void Enqueue(int);
int  Dequeue();


int main(void) {
   int src;

   Build_Graph();
   Print_Adjacency_List();

   src = 1;
   BFS(src);
   Print_Path(src, 7);

   return 0;
}

void Create_Edge(int u, int v) {
	struct elem *x;
	x =  (struct elem *)malloc (sizeof (struct elem));
	x->vert = v;
	x->next = Adj [u];
	Adj [u] = x;
	struct elem *y;
	y =  (struct elem *)malloc (sizeof (struct elem));
	y->vert = u;
	y->next = Adj [v];
	Adj [v] = y;
}


void Build_Graph(void) {

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


void Print_Adjacency_List(void) {
	struct elem *head;
	int i;
	for (i = 0; i < N; i++){
		head = Adj[i];
		printf ("%d",i);
		while(head != NULL){
			printf ("->%d",head->vert);
			head = head->next;
		}
		printf ("\n");
	}
}


// breadth-first search
void BFS(int s) {
	struct elem *head_in;
	int i;
	int u;
	for (i = 0; i < N; i++){
		color[i] = WHITE;
		d[i] = INFINITY;
		pi[i] = NIL;
	}
	color[s] = GRAY;
	d[s] = 0;
	pi[s] = NIL;
	Enqueue (s);
	while (Q[head] != NIL){
		u = Dequeue();
		head_in = Adj[u];
		while (head_in != NULL){
			if (color[head_in->vert] == WHITE){
				d[head_in->vert] = d[u]+1;
				pi[head_in->vert] = u;
				Enqueue (head_in->vert);
		}
		color[u] = BLACK;
	}
	
}


// prints out the vertices on a shortest path from s to v
void Print_Path(int s, int v) {
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


int Dequeue(void) {
   int x;
   x = Q[head];
   if (head == N-1)
      head = 0;
   else
      head++;
   return x;
}
