#include <stdio.h>
#include<math.h>
/*
	Um dos métodos para calcular a raiz quadrada de um número é o método de Newton. A fórmula para o método de newton é mostrada a seguir:
 
Onde: num: é o número cuja raiz quadrada queremos calcular; 
ans: é uma aproximação inicial da raiz quadrada;
tol: é a tolerância permitida para a raiz quadrada.
Implemente um algoritmo recursivo que utilize o método de Newton para calcular a raiz quadrada de um número. Verifique o seu algoritmo nos seguintes casos: squareRoot(5,2,0.01); squareRoot(4,2,0.01)

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
