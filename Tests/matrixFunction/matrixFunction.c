#include <stdlib.h>
#include <stdio.h>

void printMatrix(int size, int a[size][size]){
	printf("%d\n",a);
	int i,j;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void changeMatrix(int size, int a[size][size]){
	int i,j,aux=size*size;
	
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			a[i][j]=aux;
			aux--;
		}
	}
}

int main(){
		
	int size=4;
	int m[size][size];
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
	printMatrix(size,m);
	printf("\n<");
	printf("Printing Function2>\n");
	changeMatrix(size,m);
	printf("\n<");
	printf("Printing Function3>\n");
	printMatrix(size,m);
	printf("\n<");
}
