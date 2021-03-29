#include "Cilinder.h"
/*
	1.	Desenvolva e implemente um TAD que represente um cilindro.
	Inclua as funções de inicializações necessárias e as operações que retornem a
	sua altura e o raio, a sua área e o seu volume. Para cada função, explique brevemente
	a ideia adotada.  Teste o TAD com exemplos. Teste o TAD com uma aplicação.
*/
int main(){
	
	Cilinder *c1, *c2;
	c1= CreateCilinder();
	c2= CreateCilinder();
	
	SetDataToCilinder(c1,1,1,10,5);
	SetDataToCilinder(c2,2,2,5,10);

	ShowCilinderData(c1,1);
	ShowCilinderData(c2,2);

	FreeCilinder(c1);
	FreeCilinder(c2);	
}
