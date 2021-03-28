#include <stdio.h>
#include <stdlib.h>

void func(int b){
	
	
}

int main(){
	int a[3][3];
	int i=0, j=0;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			a[i][j]= rand()%50;
		}
	}
	
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	int b[3][3];
	func(&b);
	
	
}
