#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*	//Time example
	clock_t fullTimer, sumTimer, multiplicationTimer;
	double fullTimeTaken, sumTimeTaken, multiplicationTimeTaken;
    fullTimer = clock();
    fun();
    fullTimer = clock() - fullTimer;
    fullTimeTaken = ((double)fullTimer)/CLOCKS_PER_SEC; // in seconds
    printf("Sum took %f seconds to execute.\n", time_taken);
*/

/*
	Considerando os conceitos de eficiência de algoritmos realize as seguintes tarefas:
	6.	Implemente código para medir o desempenho desses algoritmos, considerando:
		i)	O tempo de execução de cada algoritmo em milissegundos;
		ii)	O número de operações realizadas (somas + multiplicações) por cada algoritmo.
*/

void createMatrix			(int size, int m[size][size]){
	int i, j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			m[i][j]= rand()%2;
		}
	}
}
void printMatrix			(int size, int m[size][size]){
	int i, j;

	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void matrixSum				(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i, j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void matrixMultiplication	(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i, j, k;
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
	
	printf("Matrix A:\n");
	int a[size][size];
	createMatrix(size,a);	//	Creating Matrix A
	printMatrix(size,a);		//	Printing Matrix A
	
	printf("Matrix 	B:\n");
	int b[size][size];
	createMatrix(size,b);	//	Creating Matrix B
	printMatrix(size,b);		//	Printing Matrix B

	printf("Sum Matrix:\n");
	int c[size][size];
	matrixSum(size,a,b,c);	//	Adding Matrixes A and B to C
	printMatrix(size,c);		//	Printing Sum Matrix
		
	printf("Multiplication Matrix:\n");
	int d[size][size];
	matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	printMatrix(size,d);				//	Printing Multiplication Matrix
		
}
