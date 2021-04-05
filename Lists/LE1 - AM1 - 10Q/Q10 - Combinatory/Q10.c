#include <stdio.h>
/*

	10
	A combina��o de n objetos tomados k de cada vez,
	pode ser calculada de maneira recursiva usando a seguinte formula de recorr�ncia:
 
	C(n, k){
	    if ((k==0) || (n==k)){
	        return 1;
		} else if (n>k && k>0) {
			return C(n-1,k)+C(n-1,k-1);
		}      
	}

	Esta f�rmula pode ser usada para calcular o n�mero de combina��es poss�veis, k de n objetos.
	Implemente um algoritmo recursivo para calcular a combina��o de n objetos tomados k de cada vez.
	Verifique o seu algoritmo, para C(49,6) que corresponde a um total de 13.983.816 combina��es diferentes.


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
	// QUEST�O
	
	printf("C(49,6)= %d\n",C(49,6));
	
	//	JV
		
//	int n=49, k=6;
//	printf("\nO numero de combinacoes possiveis %d de %d:%d",n,k,C(n,k));
//	printf("\nO numero de combinacoes possiveis %d de %d:%d",n,k,branchLessC(n,k));
}
