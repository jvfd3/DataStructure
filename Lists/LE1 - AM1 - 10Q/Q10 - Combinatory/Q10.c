#include <stdio.h>
/*

	10
	A combinação de n objetos tomados k de cada vez,
	pode ser calculada de maneira recursiva usando a seguinte formula de recorrência:
 
	C(n, k){
	    if ((k==0) || (n==k)){
	        return 1;
		} else if (n>k && k>0) {
			return C(n-1,k)+C(n-1,k-1);
		}      
	}

	Esta fórmula pode ser usada para calcular o número de combinações possíveis, k de n objetos.
	Implemente um algoritmo recursivo para calcular a combinação de n objetos tomados k de cada vez.
	Verifique o seu algoritmo, para C(49,6) que corresponde a um total de 13.983.816 combinações diferentes.


*/
int C(int n, int k){
    if (k==0 || n==k){
        return 1;
	} else if (n>k && k>0) {
		return C(n-1,k)+C(n-1,k-1);
	}      
}

int branchLessC(int n, int k){
	return (k==0 || n==k) + (n>k && k>0)*(C(n-1,k)+C(n-1,k-1));    
}

int main() {
	// QUESTÃO
	
	printf("C(49,6)= %d\n",C(49,6));
	
	//	JV
		
//	int n=49, k=6;
//	printf("\nO numero de combinacoes possiveis %d de %d:%d",n,k,C(n,k));
//	printf("\nO numero de combinacoes possiveis %d de %d:%d",n,k,branchLessC(n,k));
}
