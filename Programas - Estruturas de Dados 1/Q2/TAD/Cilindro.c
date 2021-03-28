#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Cilindro.h"
// colocar o volume e �rea dentro do struct?
struct cilindro {
	float altura;
	float raio;
};

Cilindro* cil_cria (float alt, float r){
	Cilindro* c = (Cilindro*) malloc ( sizeof (Cilindro) );
	if(c != NULL){
		c -> altura = alt;
//		scanf("%f",&(c->altura));
		c -> raio   = r;
	}
	return c;
}
/* Criamos um ponteiro do tipo struct, alocamos a mem�ria correspondente, e caso essa opera��o teve sucesso, atribu�mos os respectivos valores.
*/

float cil_altura (Cilindro* c){
	return c -> altura;
}

float cil_raio (Cilindro* c){
	return c -> raio;
}

float cil_volume(Cilindro* c){
	return 3.14*c->raio*c->raio*c->altura;
}


float cil_area(Cilindro* c){
	return 6.28*c->raio*(c->raio+c->altura);
}
/*
Nas fun��es anteriores acessamos os elementos de interesse e retornamos o resultado das manipula��es num�ricas.
*/

// utilizado para limpar os valores guardados no endere�o enviado
void cil_libera (Cilindro* c){
	free(c);
}


void mostra_dados_cil(Cilindro* c, int n){
	printf("Cilindro %d\n",n);	
	printf("Altura:\t %.3f\t", cil_altura	(c));
	printf("Raio:  \t %.3f\t", cil_raio		(c));
	printf("Volume:\t %.3f\t", cil_volume	(c));
	printf("Area:  \t %.3f\n", cil_area		(c));
}

