//Представления графов
#include <stdio.h>
#include <stdlib.h>

#define  N          8

struct elem {                          // an element in the list
   int i;
   int j;                           // vertex v of edge (u,v)
   struct elem *next;
};

struct elem *Adj[N] = {NULL};                   // array Adj consists |V| lists,
                                       // one for each vertex in V


void Create_Edge(int, int);
void Build_Graph();
void Print_Adjacency_List();


int main(void) {
	
   Build_Graph();
   Print_Adjacency_List();

   return 0;
}


void Create_Edge(int u, int v) {
	struct elem *x,*y;

	x =  (struct elem *)malloc (sizeof (struct elem));
	x->i = u;
	x->j = v;
	x->next = Adj [u];
	Adj [u] = x;

	y =  (struct elem *)malloc (sizeof (struct elem));
	y->i = v;
	y->j = u;
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
	int i,j, k;
	for (i = 0; i < N; i++){
		head = Adj[i];
		printf ("i=%d || ",i);
		for (j = 0; j < N; j++){
			if (head != 0){
				if (head->i == i && head->j == j){
					printf ("1 ");
					head = head->next;
					if (head == NULL)
						while (j < N-1){
							printf ("0 ");
							j++;
						}
					}
				else{
					printf ("0 ");
				}
			}
			else{
				for (k = 0; k < N; k++)
					printf ("0 ");	
				j=N;
			}
		}
		printf ("\n");
	}	
}
