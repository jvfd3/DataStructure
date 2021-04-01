#include <stdio.h>

/*
	Q18
	Faça um algoritmo para uma função recursiva que calcule o
	valor da série S descrita para um valor n maior do que zero,
	a ser fornecido como parâmetro:
	S=2+5/2+10/3+...+(1+n^2)/n
	S=(2/1)+(5/2)+(10/3)+...+(1+n^2)/n
	S=(1+1^2/1)+(1+2^2/2)+(1+3^2/3)+...+(1+n^2)/n
	S=(1/1+1)+(1/2+2)+(1/3+3)+...+(1/n)+n
	Ex. n=3:
		
	S=(1/1+1)+(1/2+2)+(1/3+3)
	S=(0)+(1/1+1)+(1/2+2)+(1/3+3)
	S=0+1+1+2+3+1/2+1/3
	S=7,5+1/3
	S=7,8333...
	
	0->0
	1->2
	2->4.5
	3->7.833
	4->12.0833
*/

int		filterInput			(){
	int num;
	do{
		printf("\nType a positive Integer:\t");
		scanf("%d", &num);
	} while (num<0);
	return num;
}
//float	serie				(int n){
//	if (n>0){
//		return (1.0/n+n+serie(n-1));
//	} else {
//		return 0;
//	}
//}

float	verboseSerie				(int n){
	float x;
	printf(".");
	if (n>0){
		x=verboseSerie(n-1);
		printf("((1+%d)/%d)+",n*n,n);
		return (1.0/n+n+x);
	} else {
		printf("=");
		return 0;
	}
}

//void 	fixedResultsLoop	(){
//	int i;
//	for (i=0;i<50;i++){
//		printf("(%d,\t%.4f)\n", i, serie(i));
//	}
//}

int main(){
//	printf("%.3f", serie(filterInput()));
	printf("a");
	int n=filterInput();
	int temp= verboseSerie(n);
	printf("b");
//	fixedResultsLoop();
}
