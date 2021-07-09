#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

// #include <tadfile.c>

/*  Q8 - Somar polinomios

Escreva um programa que some polinomios.
Cada polinomio deve ser representado como uma lista encadeada.
O primeiro no na lista representa o termo de maior grau, enquanto que o ultimo
representa o termo de menor grau. Cada no contem tres campos:
i) coeficiente do termo;
ii) expoente do termo;
iii) o ponteiro ao seguinte termo.

Os polinomios podem ser adicionados utilizando um processo de intercalacao.
As duas listas sao combinadas por intercalacao, alem de realizar uma operacao
de soma quando os exponentes forem iguais.  Observe o exemplo da Figura.

(IMAGEM)

Regras para a adicao:
i)    Se os expoentes sao iguais, os coeficientes sao somados e o resultado inserido;
ii)   Se os expoentes sao diferentes, o termo com maior expoente devera ser inserido,
enquanto o menor aguarda para ser comparado com outro termo. 
iii)  Se o resultado da adicao e 0, o termo deve ser eliminado do polinomio soma.
iv)   Se um polinomio termina antes o outro, os termos restantes do polinomio maior serao adicionados no polinomio soma.

Os dados do polinomio (coeficientes e potencias) podem ser lidos de um arquivo ou ingressados do teclado.
Imprima os dois polinomios de entrada e o polinomio soma.

*/

int main () {
    
}
