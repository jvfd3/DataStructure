#include "Cilinder.h"
/*
	1.	Desenvolva e implemente um TAD que represente um cilindro.
	Inclua as funções de inicializações necessárias e as operações que retornem a
	sua altura e o raio, a sua área e o seu volume. Para cada função, explique brevemente
	a ideia adotada.  Teste o TAD com exemplos. Teste o TAD com uma aplicação.
*/
int main(){
	
	Cilindro *c1, *c2;
	c1= cil_cria(1,1,10,5);
	c2= cil_cria(2,2,5,10);

	mostra_dados_cil(c1,1);
	mostra_dados_cil(c2,2);

	cil_libera(c1);
	cil_libera(c2);	
}
