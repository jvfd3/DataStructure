//#include <stdio.h>
//#include <stdlib.h>
#include "conjunto.c"
void main(){
	/*	CLEAN VERSION	*/
	MainN* list1=CreateEmptyList();		//		a)	Criar um conjunto vazio.
	InsertElement(list1,111);			//		b)	Inserir um elemento no conjunto.
	InsertElement(list1,222);
	InsertElement(list1,333);
	RemoveLastElement(list1);			//		c)	Remover um elemento no conjunto.
	CheckNumber(list1,222);				//		d)	Testar se um numero pertence ao conjunto.
	SmallestValue(list1);				//		e)	Menor valor do conjunto.
	MainN* list2=CreateEmptyList();	
	InsertElement(list2,999);
	InsertElement(list2,888);
	MainN* list3=CreateEmptyList();	
	Concatenate(list1,list2,list3);		//		f)	Uniao de dois conjuntos.
	CheckEquality(list1,list2);			//		g)	Testar se os dois conjuntos sao iguais.
	CheckEmpty(list1);					//		h)	Testar se o conjunto e vazio.
	
	/*	VARIATIONS VERSION	*/
// 		variations();
}
