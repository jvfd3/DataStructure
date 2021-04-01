/*
	Q18
	Fa�a um algoritmo para uma fun��o recursiva que calcule o
	valor da s�rie S descrita para um valor n maior do que zero,
	a ser fornecido como par�metro:
	S=2+5/2+10/3+...+(1+n^2)/n
*/

#include <stdio.h>
int		filterInput			(){
	int num;
	do{
		printf("\nType a positive Integer:\t");
		scanf("%d", &num);
	} while (num<0);
	return num;
}
float 	serie				(int n){
	if (n>0){
		return ((1.0/n+n) + serie(n-1));
	} else {
		return 0;
	}
}

int main(){
	printf("%.3f", serie(filterInput()));
}
