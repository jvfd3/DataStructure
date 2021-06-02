#include <stdio.h>
#include <math.h>
/*
	Um dos m�todos para calcular a raiz quadrada de um n�mero � o m�todo de Newton. A f�rmula para o m�todo de newton � mostrada a seguir:
 
		SquareRoot (num, ans, tol){ 
			if (|ans*ans-num|<= tol) {
				return ans;
			} else {
				return squareRoot (num,(ans*ans+num)/(2*ans),tol);
			}
		}
 
Onde:
	num: � o n�mero cuja raiz quadrada queremos calcular; 
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

void printMatrix(float num){
	printf("Raiz quadrada de %.2f:\n",num);
	float newton=squareRoot(num,2.0,0.00001);
	float commonSqrt=sqrt(num);
	printf("Metodo de Newton:\t%.8f\n",newton);
	printf("Sqrt:\t\t\t%.8f\n",commonSqrt);
	printf("Diferenca:\t\t%.8f\n\n",newton-commonSqrt);
}

int main(){
	// QUESTAO 9
	printf("Raiz quadrada de 4:\t%.8f\n",squareRoot(4,2,0.01));
	printf("Raiz quadrada de 5:\t%.8f\n",squareRoot(5,2,0.01));
		
	// JV
//	int i, qtd=9;
//	for (i=4;i<qtd;i++){
//		printMatrix(i);
//	}
}
