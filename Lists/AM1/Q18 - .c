#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
*/

int filterInput(){
	int num;
	do{
		printf("\nType a positive Integer:\t");
		scanf("%d", &num);
	} while (num<0);
	return num;
}
float serie(int n){
	if (n>0){
		printf("%d",n);
		return ((1.0+n*n/n) + serie(n-1));
	}else{
		return 0;
	}
}

int main(){
//	int num = -1;
//	num=filterInput();
//	float SerieResult=serie(num);
//	printf("%.3f", SerieResult);

	
	int i=3;
	int j=2;
	float k=i/j;
	printf("II: %f\n",k);

	float x=3;
	int y=2;
	float z=x/y;
	printf("FI: %f\n",z);

	int a=3;
	float b=2;
	float c=a/b;
	printf("IF: %f\n",c);
	
	float u=3;
	float v=2;
	float w=u/v;
	printf("FF: %f",w);
}
