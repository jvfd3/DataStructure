#include <stdlib.h>
#include <stdio.h>

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
	
	
}
