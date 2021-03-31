#include <stdlib.h>
#include <stdio.h>

void printVector1(int a[4]){
	printf("%d\n",a);
}
void printVector2(int size,int b[size]){
	printf("%d\n",b);
}

int main(){
		
	int size=4;
	int m[size];
	int n[4];
	int i;
	for (i=0;i<size;i++){
		m[i]=i;
		n[i]=i;
	}
	for (i=0;i<size;i++){
		printf("%d\t",m[i]);
		printf("%d\t",n[i]);
	}
	
	printf("\nPrinting Function1>\n");
	printVector1(m);
	printVector1(n);
//	printVector1(&m);
//	printVector1(&n);
	printf("\n<\n");
	printf("Printing Function2>\n");
	printVector2(size,m);
	printVector2(size,n);
//	printVector2(&m);
//	printVector2(&n);
	printf("\n<");
}
