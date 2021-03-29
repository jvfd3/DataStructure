#include <stdlib.h>
#include "Point.h"

int main(){
	Ponto *p=pto_cria(10,21);
	Ponto *q=pto_cria(7,25);
	printf("Distancia entre pontos: %f\n",pto_distancia(p,q));
	pto_libera(p);
	pto_libera(q);	
}
