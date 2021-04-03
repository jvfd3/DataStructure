#include <stdio.h>
#include<math.h>
/*
	Um dos m�todos para calcular a raiz quadrada de um n�mero � o m�todo de Newton. A f�rmula para o m�todo de newton � mostrada a seguir:
 
Onde: num: � o n�mero cuja raiz quadrada queremos calcular; 
ans: � uma aproxima��o inicial da raiz quadrada;
tol: � a toler�ncia permitida para a raiz quadrada.
Implemente um algoritmo recursivo que utilize o m�todo de Newton para calcular a raiz quadrada de um n�mero. Verifique o seu algoritmo nos seguintes casos: squareRoot(5,2,0.01); squareRoot(4,2,0.01)

*/
float squareRoot(float num, float ans, float tol){
	if (fabs(ans*ans-num)<=tol) {
		return ans;
	} else {
	    return squareRoot(num,(ans*ans+num)/(2*ans),tol);
	}
}

int main(){
    printf("Raiz quadrada de 5 eh:%.4f\n",squareRoot(5.0,2.0,0.01));
    printf("Raiz quadrada de 4 eh:%.4f\n",squareRoot(4.0,2.0,0.01));
}
