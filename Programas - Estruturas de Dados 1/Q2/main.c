//#include <stdio.h>
//#include <stdlib.h>
#include "conjunto.c"


void main(){
	/*	CLEAN VERSION	*/
	
	
	
	/*	VARIATIONS VERSION	*/
	
/**/MainN* l1=CreateEmptyList();	//		a)	Criar uma lista vazia.
	
/**/InsertElement(l1,111);			//		b)	Inserir um elemento no conjunto.
	InsRemElementsTest1(l1);		/*		Insert:	1) First;	2) Last	(OK);	3) Random;	4)In order;*/
/**/RemoveLastElement(l1);			//		c)	Remover um elemento do conjunto.

/**/CheckNumber(l1,333);			//		d)	Testar se um número pertence ao conjunto.
	CheckNumber(l1,444);			//		d)	Testar se um número pertence ao conjunto.
	
/**/SmallestValue(l1);				//		e)	Menor valor do conjunto.
	// BiggestValue(l1);			//		e)	Menor valor do conjunto.
	
	MainN* l2=CreateEmptyList();
	InsertElementsTest2(l2);
	MainN* l3=CreateEmptyList();
/**/Concatenate(l1,l2,l3);				//		f)	União de dois conjuntos.
/**/CheckEquality(l1,l2);			//		g)	Testar se os dois conjuntos são iguais.

	MainN* l4=CreateEmptyList();
	InsRemElementsTest1(l4);
	ShowList(l4);
	
	MainN* l5=CreateEmptyList();
	InsRemElementsTest1(l5);
	ShowList(l5);
	CheckEquality(l4,l5);
	RemoveLastElement(l4);
	InsertElement(l4,888);
	ShowList(l4);
	
	CheckEquality(l4,l5);
/**/CheckEmpty(l1);					//		h)	Testar se o conjunto é vazio.
	MainN* l6=CreateEmptyList();
/**/CheckEmpty(l6);	
	Clean(l1);
	Clean(l2);
	Clean(l3);
	Clean(l4);
	Clean(l5);
	Clean(l6);

}
