#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	8.
		Responda se os seus resultados 
		corroboram as funções O() teóricas
		de cada algoritmo.
*/



void 	createMatrix			(int size, int a[size][size]){
	int i,j;
	
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			a[i][j]= rand()%2;
		}
	}
}
void 	printMatrix				(int size, int a[size][size]){
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
int 	matrixSum 				(int size, int a[size][size], int b[size][size], int c[size][size]){
	int i,j,OperacoesSoma=0;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			c[i][j]=a[i][j]+b[i][j];
			OperacoesSoma++;
		}
	}
	return OperacoesSoma;
}
int 	matrixMultiplication	(int size, int a[size][size], int b[size][size], int c[size][size]){
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
double	printTimer				(clock_t time){
	double timeTaken= (double)time*1000/CLOCKS_PER_SEC;
//    printf("Time taken: %.2f ms.\n\n", timeTaken);
    return timeTaken;
}
void table (int size, int timeSum, int operationsSum, int timeMult, int operationsMult){
	printf("%d,%d,%d,%d,%d\n", size, timeSum, operationsSum, timeMult, operationsMult);

}


void Q8(int size){
	clock_t time;
	
	int a[size][size], b[size][size], c[size][size], d[size][size], e[size][size];
	createMatrix	(size,a);
	createMatrix(size,b);
	
	time = clock();
	int operationsSum = matrixSum(size,a,b,c);
	double timeSum = printTimer		(clock()-time);
		
	time = clock();
	int operationsMult = matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	double timeMult = printTimer		(clock()-time);
	
	table (size, timeSum, operationsSum, timeMult, operationsMult);
}

int main(){
	
	int size;
	printf("\t soma\t Multiplicacao\n");
	printf("tamanho, tempo, operacoes, tempo, operacoes\n");
	
	for (size=1; size<=400;size++){
		Q8 (size);
	}
}
