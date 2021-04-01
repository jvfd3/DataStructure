#include <stdio.h>
#include <stdlib.h>
/*
	Considerando os conceitos de eficiência de algoritmos realize as seguintes tarefas:
	5. Implemente os algoritmos de Soma de Matrizes nxn (quadradas) e Mulplicação de
	matrizes nxn (quadradas). Os dados das matrizes de entrada podem ser preenchidos
	de forma aleatória ou usando alguma regra de geradora.
*/

int main(){
	printf("Matrix A:\n");
	int a[3][3];
	int i, j, k;
//	Creating Matrix A
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			a[i][j]= rand()%2;
		}
	}
	
//	Printing Matrix A
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
//	Creating Matrix B
	printf("Matrix 	B:\n");
	int b[3][3];
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			b[i][j]= rand()%2;
		}
	}
	
//	Printing Matrix B
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	int c[3][3];
	
//	Creating Sum Matrix
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	
//	Printing Sum Matrix
	printf("Sum Matrix:\n");
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
//	Creating Matrix Multiplication
	int d[3][3];
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			d[i][j]=0;
			for (k=0;k<3;k++){
				d[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	
//	Printing Multiplication Matrix
	printf("Multiplication Matrix:\n");
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
		
}
