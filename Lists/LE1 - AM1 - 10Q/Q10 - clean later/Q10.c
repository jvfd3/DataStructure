#include <stdio.h>
#include <stdlib.h>

int C(int n, int k){
    if (k==0 || n==k){
        return 1;
	} else if (n>k && k>0) {
		return C(n-1,k)+C(n-1,k-1);
	}      
}

int main() {
	int n=49;
	int k=6;
	
//	printf("Por favor, insira o numero de combinacoes:");
//	scanf("%d",&k);
//	printf("\nPor favor, insira o numero de objetos:");
//	scanf("%d",&n);
	
	int c=C(n,k);
	printf("\nO numero de combinacoes possiveis %d de %d:%d",n,k,c);
}
