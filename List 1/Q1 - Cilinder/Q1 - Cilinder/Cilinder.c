#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Cilinder.h"
// colocar o volume e área dentro do struct?
struct cilindro {
	int x,y;
	float raio, altura;
};

Cilindro* cil_cria (int x, int y, float alt, float r){
	Cilindro* c = (Cilindro*) malloc ( sizeof (Cilindro) );
	if(c != NULL){
		c->x=x;
		c->y=y;
		c->altura = alt;
//		scanf("%f",&(c->altura));
		c->raio   = r;
	}
	return c;
}
/* Criamos um ponteiro do tipo struct, alocamos a memória correspondente, e caso essa operação teve sucesso, atribuímos os respectivos valores.
*/
/*
float cil_altura (Cilindro* c){
	return c -> altura;
}

float cil_raio (Cilindro* c){
	return c -> raio;
}
*/

float cil_volume(Cilindro* c){
	return 3.14*c->raio*c->raio*c->altura;
}


float cil_area(Cilindro* c){
	return 6.28*c->raio*(c->raio+c->altura);
}


void cil_libera (Cilindro* c){
	free(c);
}


void mostra_dados_cil(Cilindro* c, int n){
	printf("Cilindro %d\n",n);
	printf("(x,y)=(%d,%d)\n", c->x, c->y);
	printf("Altura:\t %.3f\t", c->altura);
	printf("Raio:  \t %.3f\t", c->raio);
//	printf("Altura:\t %.3f\t", cil_altura	(c));
//	printf("Raio:  \t %.3f\t", cil_raio		(c));
	printf("Volume:\t %.3f\t", cil_volume	(c));
	printf("Area:  \t %.3f\n", cil_area		(c));
}

