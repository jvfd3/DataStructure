#include <stdio.h>
#include <stdlib.h>
/*
	Considerando os conceitos de eficiência de algoritmos realize as seguintes tarefas:
	5. Implemente os algoritmos de Soma de Matrizes nxn (quadradas) e Mulplicação de
	matrizes nxn (quadradas). Os dados das matrizes de entrada podem ser preenchidos
	de forma aleatória ou usando alguma regra de geradora.
*/


void createMatrix			(int size, int a[size][size]){
	int i,j;
	
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			a[i][j]= rand()%2;
		}
	}
}
void printMatrix			(int size, int a[size][size]){
	//	Printing Matrix
	int i,j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void matrixSum 				(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i,j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void matrixMultiplication 	(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i,j,k;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=0;
			for (k=0;k<size;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

int main(){	
	int size=3;
	int a[size][size], b[size][size], c[size][size], d[size][size], e[size][size];

	createMatrix			(size,a);
	printf("Matriz A:\n");
	printMatrix				(size,a);
	createMatrix			(size,b);
	printf("Matriz B:\n");
	printMatrix				(size,b);
	matrixSum				(size,a,b,c);
	printf("Matriz A+B:\n");
	printMatrix				(size,c);
	matrixMultiplication	(size,a,b,d);
	printf("Matriz A*B:\n");
	printMatrix				(size,d);	
	
		
}
