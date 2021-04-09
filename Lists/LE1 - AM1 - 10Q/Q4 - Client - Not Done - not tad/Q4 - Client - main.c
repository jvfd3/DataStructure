#include <stdlib.h>
#include <stdio.h>
#include <String.h>
/*
	4.	Os dados relativos aos clientes de uma empresa estao armazenados em um arquivo.
	Para cada cliente sao registrados um 
	
	codigo, nome, o endereco, o telefone,
	a data em que fez sua primeira compra na empresa,
	a data da última compra e o valor da ultima compra.
	
	Especifique o TAD Clientes para armazenar os dados dos clientes e
	as operacoes necessarias para
	inserir,
	consultar e
	excluir
	esses dados.
	Implemente uma aplicacao que utilize o tipo Clientes.
*/

	typedef struct cliente {
		char *codigo;
		char *nome;
		char *endereco;
		char *telefone;
		char *dataPrimeiraCompra;
		char *dataUltimaCompra;
		char *valorUltimaCompra;	
	} Cliente;
	
	typedef struct clientElement{
		struct client *c;
		struct Clientes *next;
	} ClientElement;
	
	typedef struct mainClientList{
		int listLength;
		ClientElement* first;
		ClientElement* last;
	} Clientes;


Clientes* 	CreateEmptyClientesList(){
	Clientes* pointer = (Clientes*) malloc (sizeof(Clientes));
	pointer->first=NULL;
	pointer->last=NULL;
	pointer->listLength=0;
	printf("A new list was created at pointer: (%X)\n", pointer);
	return pointer;
}



/*

void 	ShowList			(Clientes* mainPointer){							//		mostrar lista
	int loopCounter;
	N* nodePointer=pointer->first;
	printf("(");
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		
		printf("%d", nodePointer->intValue);
		if(loopCounter!=(mainPointer->listLength-1)){
			printf("/");
		}
		nodePointer=nodePointer->next;
	}
	printf(")\n");
}
void 	ShowListPointers	(Clientes* mainPointer){						//		mostrar ponteiros da lista
	int loopCounter;
	N* nodePointer=mainPointer->first;
		
	printf("\n{\n");
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		printf("\t(%X,next: %X)", nodePointer, nodePointer->next);
		if(loopCounter!=(mainPointer->listLength-1)){
			printf(",\n");
		}
		nodePointer=nodePointer->next;
	}
	printf("\n}\n");
}


*/
void	CreateEmptyCliente		(Clientes* mainPointer){
	
	
	ClientElement* ElementPointer = (ClientElement*) malloc (sizeof(ClientElement));
	ClientElement* ClientePointer = (Cliente*) malloc (sizeof(Cliente));
	pointer->first=NULL;
	pointer->last=NULL;
	pointer->listLength=0;
	printf("A new list was created at pointer: (%X)\n", pointer);
	return pointer;
	}
	/**/
	
	int isANewValue=1;
	int loopCounter;
	ClientElement* nodePointer=mainPointer->first;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		if(nodePointer->intValue==dataToInsert){
			isANewValue=0;
		}
		nodePointer=nodePointer->next;
	}
	if(isANewValue){
		struct Node* NewElem = (N*) malloc (sizeof(N));
		NewElem->intValue=dataToInsert;
		NewElem->next=NULL;
		if (mainPointer->listLength==0){
			mainPointer->listLength=1;
			mainPointer->first=NewElem;
			mainPointer->last=NewElem;
		}
		else{
			mainPointer->listLength++;
			mainPointer->last->next=NewElem;
			mainPointer->last=NewElem;
		}
		printf("Inserted element %d. List:\t", dataToInsert);
		ShowList(mainPointer);
	//	ShowListPointers(mainPointer);
			
	} else {
		printf("The value %d already exists.\n", dataToInsert);
	}
}

int main(){
	Clientes* list1=CreateEmptyClientesList();
	CreateEmptyCliente(list1);
	InsertElement(list1,222);
}
