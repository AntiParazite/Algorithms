#include<stdio.h>
#include<limits.h>
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int S[100][100];
int MatrixChainMultiplication(int p[], int n){
 	int m[n][n];   
    int i, j, k, L, q;  
    for (i = 1; i < n; i++) 
        m[i][i] = 0; 
    for (L = 2; L < n; L++) { 
        for (i = 1; i < n - L + 1; i++) { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) { 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]){ 
                    m[i][j] = q; 
                	S[i][j] = k;
				}
            } 
        } 
    }   
    return m[1][n - 1]; 
} 


void PrintOptimalparens(int i, int j){
	if (i == j)
		printf("A%d", i);
	else{
		printf("(");
		PrintOptimalparens(i, S[i][j]);
		printf("*");
		PrintOptimalparens(S[i][j] + 1, j);
		printf(")");
	}
}
 
int main(void){
    int i, n;
	printf("Enter number of matrices\n");
    scanf("%d",&n);
    n++;
    int d[n]; 
    for(i = 0; i <n; i++){
        printf("Enter d%d : ",i);
        scanf("%d",&d[i]);
    }
    printf("Minimum number of multiplications is %d ", MatrixChainMultiplication(d,sizeof(d)/sizeof(d[0])));
 	PrintOptimalparens(0, n-2);
    return 0;
}
