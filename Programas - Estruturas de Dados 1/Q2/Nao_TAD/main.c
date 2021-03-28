//#include <stdio.h>
//#include <stdlib.h>
#include "conjunto.c"


void main(){
	MainN* l1=CreateEmptyList();	//		a)	Criar uma lista vazia.
	
	InsertElement(l1,111);			//		b)	Inserir um elemento no conjunto.
//	InsertRemoveElementsTest1(l1);			/*		Insert:	1) First;	2) Last	(OK);	3) Random;	4)In order;*/
	RemoveLastElement(l1);
			
	CheckNumber(l1,333);			//		d)	Testar se um número pertence ao conjunto.
	CheckNumber(l1,444);			//		d)	Testar se um número pertence ao conjunto.
	SmallestValue(l1);				//		e)	Menor valor do conjunto.
	// BiggestValue(l1);			//		e)	Menor valor do conjunto.
	MainN* l2=CreateEmptyList();	//		a)	Criar uma lista vazia.
	InsertElement(l2,111);			//		b)	Inserir um elemento no conjunto.
	InsertElementsTest(l2);
	MainN* l3=CreateEmptyList();
	Concatenate(l1,l2,l3);				//		f)	União de dois conjuntos.
//	CheckEquality(l1,l2);			//		g)	Testar se os dois conjuntos são iguais.
//	CheckEmpty(l1);					//		h)	Testar se o conjunto é vazio.
//	Clean(l1);
//	Clean(l2);

}
