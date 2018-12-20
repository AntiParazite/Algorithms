#include<stdio.h>
#include<math.h>
#define N 25

float inverse[N][N];
float matrix[N][N];
float cofactor_b[N][N], cofactor_fac[N][N];
float transpose_b[N][N];
 
/*For calculating Determinant of the Matrix */
float determinant(float determinant_a[N][N], float k){
	float s = 1, det = 0, determinant_b[N][N];
	int i, j, m, n, c;
	if (k == 1){
	return (determinant_a[0][0]);
	}
	else{
		det = 0;
		for (c = 0; c < k; c++){
			m = 0;
			n = 0;
			for (i = 0;i < k; i++){
				for (j = 0 ;j < k; j++){
					determinant_b[i][j] = 0;
					if (i != 0 && j != c){
						determinant_b[m][n] = determinant_a[i][j];
						if (n < (k - 2))
							n++;
						else{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (determinant_a[0][c] * determinant(determinant_b, k - 1));
			s = -1 * s;
		}
	}
	
	return (det);
}

void transpose(float transpose_fac[N][N], int r){
	int i, j;
	float d;
	
	for (i = 0;i < r; i++){
		for (j = 0;j < r; j++){
			transpose_b[i][j] = transpose_fac[j][i];
		}
	}
	d = determinant(matrix, r);
	for (i = 0;i < r; i++){
		for (j = 0;j < r; j++){
			inverse[i][j] = transpose_b[i][j] / d;
		}
	}
}

void cofactor(int f){
	int p, q, m, n, i, j;
	for (q = 0;q < f; q++){
		for (p = 0;p < f; p++){
			m = 0;
			n = 0;
			for (i = 0;i < f; i++){
				for (j = 0;j < f; j++){
					if (i != q && j != p){
						cofactor_b[m][n] = matrix[i][j];
						if (n < (f - 2))
							n++;
						else{
							n = 0;
							m++;
						}
					}
				}
			}
			cofactor_fac[q][p] = pow(-1, q + p) * determinant(cofactor_b, f - 1);
		}
	}
	transpose(cofactor_fac, f);
}

void print_inverse_matrix(int n){	
	printf("\n\n\nThe inverse of Matrix is : \n");
	for (int i = 0;i < n; i++){
		for (int j = 0;j < n; j++){
			printf("\t%.2f", inverse[i][j]);
		}
		printf("\n");
	}
}

void print_matrix(int n){	
	printf("\n\n\nThe matrix is : \n");
	for (int i = 0;i < n; i++){
		for (int j = 0;j < n; j++){
			printf("\t%.2f", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	float d;
	int n, i, j;	
	printf("Enter the order of the Matrix. ");
	scanf("%d", &n);
	printf("Enter the elements of %dX%d Matrix : \n", n, n);
	for ( i = 0;i < n; i++){
		for (j = 0;j < n; j++){
			scanf("%f", &matrix[i][j]);
		}
	}
	print_matrix(n);
	d = determinant(matrix,n);
	if (d == 0)
		printf("\nInverse of Entered Matrix is not possible\n");
	else
		cofactor(n);
	print_inverse_matrix(n);
	return 0;
}
