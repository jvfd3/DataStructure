#include <stdio.h>
#include <math.h>
#include "Cilindro.h"


struct cilindro{
    float r; //raio
    float h; //altura
    float a; //area
    float vol; //volume
};

Cilindro* volume(float r, float h){
	
	Cilindro* v = (Cilindro *) malloc (sizeof(Cilindro));
	if (v != NULL){
		v -> vol = 3.14 * (r * r) * h; // formula para encontrar o volume do cilindro
}
	return v;
}


Cilindro* areatotal(float r, float h,float a){
	
	Cilindro* at = (Cilindro *) malloc (sizeof(Cilindro)); // area total
	if (at != NULL){
		at -> a = (2 * 3.14) * (r * r) + (2 * 3.14) * r * h; // formula para encontrar a área do cilindro
}
	return at;
}


