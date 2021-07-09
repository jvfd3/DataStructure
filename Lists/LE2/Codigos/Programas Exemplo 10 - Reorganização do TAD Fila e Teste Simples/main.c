#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "TAD Fila.h"

int main(int argc, char *argv[]) {
	
	// Definições locais
	int *p;
	int  feito = false;
	QUEUE* fila_inteiros;

	// Cria uma fila e aloca memoria aos dados 
	fila_inteiros = createQueue();

	// Preenche a fila 
	while (!feito)
	{
	    p = (int*) malloc (sizeof(int));
	    printf ("Ingresse um numero: <0> para terminar: ");
	    scanf("%d", p);
	    if ( *p == 0 ) //|| fullQueue(fila_inteiros)) // EOF igual a ctrl+Z
	       feito = true;
	    else
	       enqueue(fila_inteiros, p);
	} // while 

//	Imprime os números da fila 
	printf ("\n\n A lista de numeros da fila:\n");
	while (!emptyQueue(fila_inteiros))
	   {
	    dequeue(fila_inteiros, (void*)&p);
	    printf ("%3d\n", *p);
	    free (p);
	   } // while 

//	Destroi Fila
	destroyQueue(fila_inteiros);

	return 0;
}
