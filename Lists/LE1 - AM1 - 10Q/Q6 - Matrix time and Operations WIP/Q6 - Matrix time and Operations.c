#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	clock_t fullTimer;
	double fullTimeTaken;
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
//	printf("\n");
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

void printTimer				(clock_t time){
    printf("Time taken: %.9f ms.\n\n", (double)time*1000/CLOCKS_PER_SEC);
}

void everything(){
	clock_t time;
	int size=3;
	
	time = clock();
	printf("Matrix A:\n");
	int a[size][size];
	createMatrix	(size,a);		//	Creating Matrix A
	printMatrix		(size,a);		//	Printing Matrix A
	printTimer		(clock()-time);
	
	time = clock();
	printf("Matrix 	B:\n");
	int b[size][size];
	createMatrix(size,b);		//	Creating Matrix B
	printMatrix(size,b);		//	Printing Matrix B
	printTimer		(clock()-time);

	time = clock();
	printf("Sum Matrix:\n");
	int c[size][size];
	matrixSum(size,a,b,c);		//	Adding Matrixes A and B to C
	printMatrix(size,c);		//	Printing Sum Matrix
	printTimer		(clock()-time);
		
	time = clock();
	printf("Multiplication Matrix:\n");
	int d[size][size];
	matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	printMatrix(size,d);				//	Printing Multiplication Matrix
	printTimer		(clock()-time);
}

int main(){
	clock_t time=clock();
	everything();
	printTimer(clock()-time);
	
}
