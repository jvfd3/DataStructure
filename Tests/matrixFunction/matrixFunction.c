#include <stdlib.h>
#include <stdio.h>

void printMatrix1(int m){
	printf("%d",m);
}

int main(){
		
	int size=4;
	int m[size][size];
	int n[4][4];
	int i,j,aux=0;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			m[i][j]=aux;
			aux++;
		}
	}
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	
	printf("Printing Function1>\n");
	printMatrix1(m);
	printMatrix1(&m);
	printMatrix1(n);
	printMatrix1(&n);
	printf("\n<");
	printf("Printing Function>\n");
	printMatrix2(m);
	printMatrix2(&m);
	printMatrix2(n);
	printMatrix2(&n);
	printf("\n<");
}
