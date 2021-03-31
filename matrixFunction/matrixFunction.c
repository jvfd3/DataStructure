#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int x;
	int y[2];
	int z[2][2];
	int z1[3][3];
	printf("(x:%d,y:%d,z:%d,z1:%d)",sizeof(x),sizeof(y),sizeof(z),sizeof(z1));
	
	printf("(x:%d,y:%d,z:%d,z1:%d)",sizeof(&x),sizeof(&y),sizeof(&z),sizeof(&z1));
	
	
//	int size=4;
//	int m[size][size];
//	int i,j,aux=0;
//	for (i=0;i<size;i++){
//		for (j=0;j<size;j++){
//			m[i][j]=aux;
//			aux++;
//		}
//	}
//	for (i=0;i<size;i++){
//		for (j=0;j<size;j++){
//			printf("%d\t",m[i][j]);
//		}
//		printf("\n");
//	}
	
	
}
