#include <stdio.h>
#include <stdlib.h>
/*

Considerando os conceitos de eficiência de algoritmos realize as seguintes tarefas:
5. Implemente os algoritmos de Soma de Matrizes nxn (quadradas) e Mulplicação de
matrizes nxn (quadradas). Os dados das matrizes de entrada podem ser preenchidos
de forma aleatória ou usando alguma regra de geradora.

*/

int main(){
	printf("Matriz A:\n");
	int a[3][3];
	int i, j, k;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			a[i][j]= rand()%2;
		}
	}
	
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	printf("Matriz 	B:\n");
	int b[3][3];
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			b[i][j]= rand()%2;
		}
	}
	
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	int c[3][3];
	
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("Matriz da soma:\n");
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	int d[3][3];
	int somatory;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			somatory=0;
			for (k=0;k<3;k++){
				somatory+=a[i][k]*b[k][j];
			}
			d[i][j]=somatory;
		}
	}
	
	
	printf("Matriz da Multiplicacao:\n");
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
		
}
