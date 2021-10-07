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
	Considerando os conceitos de efici�ncia de algoritmos realize as seguintes tarefas:
	6.	Implemente c�digo para medir o desempenho desses algoritmos, considerando:
		i)	O tempo de execu��o de cada algoritmo em milissegundos;
		ii)	O n�mero de opera��es realizadas (somas + multiplica��es) por cada algoritmo.
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
int matrixSum 				(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i,j,OperacoesSoma=0;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
			OperacoesSoma++;
		}
	}
	return OperacoesSoma;
}
int matrixMultiplication 	(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i,j,k, OperacoesMultiplicacao=0;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=0;
			for (k=0;k<size;k++){
				c[i][j]+=a[i][k]*b[k][j];
				OperacoesMultiplicacao+=2;
			}
		}
	}
	return OperacoesMultiplicacao;
}

double printTimer				(clock_t time){
	double timeTaken= (double)time*1000/CLOCKS_PER_SEC;
//    printf("Time taken: %.2f ms.\n\n", timeTaken);
    return timeTaken;
}

void Q6i(int size, double timeSum, double timeMult){
	printf("\ti) Tempo de execucao de cada algoritmo em milissegundos:\n");
	printf("\tPara matrizes quadradas de tamanho %d\n",size);
	printf("\tSoma: \t\t%.2f ms\n\tMultiplicacao:\t%.2f ms\n\n", timeSum, timeMult);
}

void Q6ii(int size, int OS, int OM){
	printf("\tii) Numero de operacoes realizadas (somas + multiplicacoes) por cada algoritmo:\n");
	printf("\tPara matrizes quadradas de tamanho %d\n",size);
	printf("\tSoma: \t\t%d Operacoes\n\tMultiplicacao:\t%d Operacoes\n", OS, OM);
}
void Q6 (int size, int timeSum, int timeMult, int OS, int OM){
	printf("\n6) Implemente codigo para medir o desempenho desses algoritmos, considerando:\n");
	Q6i		(size, timeSum, timeMult);
	Q6ii	(size, OS, OM);
}

int main(){
	
	clock_t time;
	int size=300;
	
	printf("Matrix A\n");
	int a[size][size];
	createMatrix	(size,a);		//	Creating Matrix A
//	printMatrix		(size,a);		//	Printing Matrix A
	
	printf("Matrix B\n");
	int b[size][size];
	createMatrix(size,b);		//	Creating Matrix B
//	printMatrix(size,b);		//	Printing Matrix B

	time = clock();
	printf("Sum Matrix\n");
	int c[size][size];
	int OperacoesSoma = matrixSum(size,a,b,c);		//	Adding Matrixes A and B to C
	double timeSum = printTimer		(clock()-time);
//	printMatrix(size,c);		//	Printing Sum Matrix
		
	time = clock();
	printf("Multiplication Matrix\n");
	int d[size][size];
	int OperacoesMultiplicacao = matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	double timeMult = printTimer		(clock()-time);
//	printMatrix(size,d);				//	Printing Multiplication Matrix
	
	Q6 (size, timeSum, timeMult, OperacoesSoma,OperacoesMultiplicacao);
}
