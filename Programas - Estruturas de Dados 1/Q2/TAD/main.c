#include "Cilindro.c"
/*

	2.	Desenvolva e implemente um TAD que represente um conjunto de inteiros.
	Para isso, utilize um vetor de inteiros. O TAD deverá conter as seguintes funções:
		a)	Criar um conjunto vazio.
		b)	Inserir um elemento no conjunto.
		c)	Remover um elemento no conjunto.
		d)	Testar se um número pertence ao conjunto.
		e)	Menor valor do conjunto.
		f)	União de dois conjuntos.
		g)	Testar se os dois conjuntos são iguais.
		h)	Testar se o conjunto é vazio.
	Para cada função, explique brevemente a ideia adotada. Teste o TAD com uma aplicação.

*/
int main(){
	
	Cilindro *c1, *c2;
	c1= cil_cria(10,5);
	c2= cil_cria(5,10);

	mostra_dados_cil(c1,1);
	mostra_dados_cil(c2,2);

	cil_libera(c1);
	cil_libera(c2);	
}
