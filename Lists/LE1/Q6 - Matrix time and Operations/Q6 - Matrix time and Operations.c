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

int main(){
	

	
	int size=3;
	printf("Matrix A:\n");
	int a[size][size];
	int i, j, k;
//	Creating Matrix A
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			a[i][j]= rand()%2;
		}
	}
	
//	Printing Matrix A
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
//	Creating Matrix B
	printf("Matrix 	B:\n");
	int b[size][size];
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			b[i][j]= rand()%2;
		}
	}
	
//	Printing Matrix B
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	int c[size][size];
	
//	Creating Sum Matrix
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	
//	Printing Sum Matrix
	printf("Sum Matrix:\n");
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
//	Creating Matrix Multiplication
	int d[size][size];
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			d[i][j]=0;
			for (k=0;k<size;k++){
				d[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	
//	Printing Multiplication Matrix
	printf("Multiplication Matrix:\n");
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
		
}
