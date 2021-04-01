#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	clock_t fullTimer, sumTimer, multiplicationTimer;
	double fullTimeTaken, sumTimeTaken, multiplicationTimeTaken;
    fullTimer = clock();
    fun();
    fullTimer = clock() - fullTimer;
    fullTimeTaken = ((double)fullTimer)/CLOCKS_PER_SEC; // in seconds
    printf("Sum took %f seconds to execute.\n", time_taken);
*/


/*
	Considerando os conceitos de efici�ncia de algoritmos realize as seguintes tarefas:
	6.	Implemente c�digo para medir o desempenho desses algoritmos, considerando:
		i)	O tempo de execu��o de cada algoritmo em milissegundos;
		ii)	O n�mero de opera��es realizadas (somas + multiplica��es) por cada algoritmo.
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
void printTimer				(clock_t time){
    printf("Time taken: %.4f ms.\n", (double)time*1000/CLOCKS_PER_SEC);
}

int main(){

	clock_t time;
	time = clock();
	int size=3;
	double timeTaken;
	
	
	printf("Matrix A:\n");
	int a[size][size];
	createMatrix(size,a);		//	Creating Matrix A
	printMatrix(size,a);		//	Printing Matrix A
	printTimer(clock()-time);
//	
//   
//	double timeTaken = ((double)(clock()-time))/CLOCKS_PER_SEC;
//    printf("%f\n", timeTaken);
	
	printf("Matrix 	B:\n");
	int b[size][size];
	createMatrix(size,b);		//	Creating Matrix B
	printMatrix(size,b);		//	Printing Matrix B

	printf("Sum Matrix:\n");
	int c[size][size];
	matrixSum(size,a,b,c);		//	Adding Matrixes A and B to C
	printMatrix(size,c);		//	Printing Sum Matrix
		
	printf("Multiplication Matrix:\n");
	int d[size][size];
	matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	printMatrix(size,d);				//	Printing Multiplication Matrix
	
	printTimer(clock()-time);
	printTimer1(clock()-time);
	time=clock()-time;
    timeTaken = ((double)time)/CLOCKS_PER_SEC;
    printf("main Sum %f.\n", timeTaken*1000);
}
