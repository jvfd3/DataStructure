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

	7.
		Realize experimentos para pelo menos três tamanhos de n.
		Na escolha dos tamanhos considere que o tamanho deve ser grande
		o suficiente para permitir a medição de tempo, mas não tanto que possa estourar a memória.
		Explore isso.
		Construa uma tabela resumindo os seus resultados.


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


void table (int size, int timeSum, int timeMult){
	printf("( %d,\t%d,\t%d\t)\n", size, timeSum, timeMult);

}


void Q7(int size){
	clock_t time;
	
	int a[size][size], b[size][size], c[size][size], d[size][size], e[size][size];
//	printf("Matrix A\n");
	createMatrix	(size,a);		//	Creating Matrix A
//	printMatrix		(size,a);		//	Printing Matrix A
	
//	printf("Matrix B\n");
	createMatrix(size,b);		//	Creating Matrix B
//	printMatrix(size,b);		//	Printing Matrix B

//	printf("Sum Matrix\n");
	time = clock();
//	int OperacoesSoma =
	matrixSum(size,a,b,c);		//	Adding Matrixes A and B to C
	double timeSum = printTimer		(clock()-time);
//	printMatrix(size,c);		//	Printing Sum Matrix
		
//	printf("Multiplication Matrix\n");
	time = clock();
//	int OperacoesMultiplicacao =
	matrixMultiplication(size,a,b,d);	//	Multiplicating Matrixes A and B to D
	double timeMult = printTimer		(clock()-time);
//	printMatrix(size,d);				//	Printing Multiplication Matrix
	
	table (size, timeSum, timeMult);
}

int main(){
	
	int size;
	printf("( tamanho,\ttempo soma,\ttempo Mult\t)\n");
	
		Q7 (1);
	for (size=2; size<=10;size++){
		Q7 (size);
	}
	for (size=50; size<=310;size+=50){
		Q7 (size);
	}
	
	for (size=310; size<=330;size++){
		Q7 (size);
	}
}
