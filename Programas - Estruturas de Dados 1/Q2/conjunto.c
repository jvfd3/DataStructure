#include <stdio.h>
#include <stdlib.h>

/*

	2.	Desenvolva e implemente um TAD que represente um conjunto de inteiros.
	Para isso, utilize um vetor de inteiros. O TAD devera conter as seguintes funcoes:
		a)	Criar um conjunto vazio.
		b)	Inserir um elemento no conjunto.
		c)	Remover um elemento no conjunto.
		d)	Testar se um numero pertence ao conjunto.
		e)	Menor valor do conjunto.
		f)	Uniao de dois conjuntos.
		g)	Testar se os dois conjuntos sao iguais.
		h)	Testar se o conjunto e vazio.
	Para cada funcao, explique brevemente a ideia adotada. Teste o TAD com uma aplicacao.

*/

typedef struct Node{
	int intValue;
	struct Node* next;
}N;
typedef struct MainNode{
	int listLength;
	N* first;
	N* last;
}MainN;

void RunList(MainN* mainPointer){
	int loopCounter;
	N* nodePointer=mainPointer->first;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		
		nodePointer=nodePointer->next;
	}
}

MainN* 	CreateEmptyList(){												//		a)	Criar uma lista vazia.
	MainN* pointer = (MainN*) malloc (sizeof(MainN));
	pointer->first=NULL;
	pointer->last=NULL;
	pointer->listLength=0;
	printf("A new list was created at pointer: (%d)\n", pointer);
	return pointer;
}
void 	ShowList			(MainN* pointer){							//		mostrar lista
	int loopCounter;
	N* nodePointer=pointer->first;
	printf("(");
	for(loopCounter=0;loopCounter<pointer->listLength;loopCounter++){
		
		printf("%d", nodePointer->intValue);
		if(loopCounter!=(pointer->listLength-1)){
			printf("/");
		}
		nodePointer=nodePointer->next;
	}
	printf(")\n");
}
void 	ShowListPointers	(MainN* mainPointer){						//		mostrar ponteiros da lista
	int loopCounter;
	N* nodePointer=mainPointer->first;
		
	printf("\n{\n");
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		printf("\t(%d,next: %d)", nodePointer, nodePointer->next);
		if(loopCounter!=(mainPointer->listLength-1)){
			printf(",\n");
		}
		nodePointer=nodePointer->next;
	}
	printf("\n}\n");
}
void	InsertElement		(MainN* mainPointer, int numberToInsert){	//		b)	Inserir um elemento no conjunto.
	
	int isANewValue=1;
	int loopCounter;
	N* nodePointer=mainPointer->first;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		if(nodePointer->intValue==numberToInsert){
			isANewValue=0;
		}
		nodePointer=nodePointer->next;
	}
	if(isANewValue){
		struct Node* NewElem = (N*) malloc (sizeof(N));
		NewElem->intValue=numberToInsert;
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
		printf("Inserted element %d. List:\t", numberToInsert);
		ShowList(mainPointer);
	//	ShowListPointers(mainPointer);
			
	} else {
		printf("The value %d already exists.\n", numberToInsert);
	}
}
void	InsertElementsTest1	(MainN* mainPointer){						//		b)	Inserir elementos no conjunto.
	InsertElement(mainPointer,222);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,333);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,333);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,444);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,555);			//		b)	Inserir um elemento no conjunto.
}
void	InsertElementsTest2	(MainN* mainPointer){						//		b)	Inserir elementos no conjunto.
	InsertElement(mainPointer,999);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,888);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,777);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,666);			//		b)	Inserir um elemento no conjunto.
	InsertElement(mainPointer,555);			//		b)	Inserir um elemento no conjunto.
}
void	RemoveLastElement	(MainN* mainPointer){						//		c)	Remover um elemento do conjunto.
	
	if(mainPointer->listLength>0){
		
		printf("Removed  element %d. List:\t", mainPointer->last->intValue);
		free(mainPointer->last);
		mainPointer->listLength--;
		
		int loopCounter;
		N* nodePointer=mainPointer->first;
		
		for (loopCounter=1;loopCounter<mainPointer->listLength;loopCounter++){
			nodePointer=nodePointer->next;
		}
		nodePointer->next=NULL;
		mainPointer->last=nodePointer;
				
		ShowList(mainPointer);
	//	ShowListPointers(mainPointer);
	} else {
		printf("Nothing to be removed.\n");
	}
}
void	InsRemElementsTest1	(MainN* mainPointer){
	InsertElement(mainPointer,111);
	InsertElement(mainPointer,222);
	InsertElement(mainPointer,333);
	InsertElement(mainPointer,444);
	RemoveLastElement(mainPointer);			//		c)	Remover um elemento no conjunto.
	RemoveLastElement(mainPointer);			//		c)	Remover um elemento no conjunto.
	InsertElement(mainPointer,222);
	InsertElement(mainPointer,333);
	InsertElement(mainPointer,444);
	InsertElement(mainPointer,555);
}
void	RemoveElementsTest	(MainN* mainPointer){						//		c)	Remover  elementos do conjunto.
	RemoveLastElement(mainPointer);			//		c)	Remover um elemento no conjunto.
	RemoveLastElement(mainPointer);			//		c)	Remover um elemento no conjunto.
	RemoveLastElement(mainPointer);			//		c)	Remover um elemento no conjunto.
}
void	CheckNumberIndex	(MainN* mainPointer, int numberToCheck, int checkCounter){	//		d)	Testar se um numero pertence ao conjunto.
	int loopCounter;
	N* nodePointer=mainPointer->first;
	printf("Found on index%s ", checkCounter>1?"es":"  ");
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		if(nodePointer->intValue==numberToCheck){	
			printf("%d,", loopCounter);
		}
		nodePointer=nodePointer->next;
	}
	printf("\n");
}
void	CheckNumber			(MainN* mainPointer, int numberToCheck){	//		d)	Testar se um numero pertence ao conjunto.
	int loopCounter, checkCounter=0;
	N* nodePointer=mainPointer->first;
	
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		if(nodePointer->intValue==numberToCheck){
			checkCounter+=1;
		}
		nodePointer=nodePointer->next;
	}
	
//	if (checkCounter>0){
//		printf("Found %d in the list.\n", numberToCheck);
//	}
	if (checkCounter == 0){
		printf("%d was not found in the list.\n", numberToCheck);
	} else if (checkCounter>0){
		printf("%d was found %d time%s in the list. ", numberToCheck, checkCounter, checkCounter>1?"s":" ");	//little trick to use in case of plural
		CheckNumberIndex(mainPointer,numberToCheck,checkCounter);
	} else {
		printf("How was it smaller than zero? Go check your code again!\n");
	}
}
void	SmallestValue		(MainN* mainPointer){						//		e)	Menor valor do conjunto.
	N* nodePointer=mainPointer->first;
	int loopCounter, smallest=nodePointer->intValue ;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		//smallest=nodePointer->intValue<smallest?nodePointer->intValue:smallest;		//Ternary operator Comparison
		
		if(nodePointer->intValue<smallest){
			smallest=nodePointer->intValue;
		}
		
		nodePointer=nodePointer->next;
	}
	printf("Smallest value from list: %d\n", smallest);
}
void	BiggestValue		(MainN* mainPointer){						//		e.1)	Maior valor do conjunto.
	N* nodePointer=mainPointer->first;
	int loopCounter, biggest=nodePointer->intValue ;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		//smallest=nodePointer->intValue<smallest?nodePointer->intValue:smallest;		//Ternary operator Comparison
		
		if(nodePointer->intValue>biggest){
			biggest=nodePointer->intValue;
		}
		
		nodePointer=nodePointer->next;
	}
	printf("Biggest  value from list: %d\n", biggest);
}
void	Concatenate			(MainN* mainPointer1, MainN* mainPointer2, MainN* mainPointer3){		//		f)	Uniao de dois conjuntos.
	
	int loopCounter;
	N* nodePointer;
	
	nodePointer=mainPointer1->first;
	for(loopCounter=0;loopCounter<mainPointer1->listLength;loopCounter++){
		InsertElement(mainPointer3, nodePointer->intValue);
		nodePointer=nodePointer->next;
	}
	
	nodePointer=mainPointer2->first;
	for(loopCounter=0;loopCounter<mainPointer2->listLength;loopCounter++){
		InsertElement(mainPointer3, nodePointer->intValue);
		nodePointer=nodePointer->next;
	}
}
void	CheckEquality		(MainN* mainPointer1, MainN* mainPointer2){	//		g)	Testar se os dois conjuntos sao iguais.
	
	if (mainPointer1->listLength==mainPointer2->listLength){
		
		int loopCounter1, loopCounter2;
		N* nodePointer1=mainPointer1->first;
		N* nodePointer2=mainPointer2->first;
		for(loopCounter1=0;loopCounter1<mainPointer1->listLength;loopCounter1++){
			for(loopCounter2=0;loopCounter2<mainPointer1->listLength;loopCounter2++){
				
				nodePointer2=nodePointer2->next;
			}
			nodePointer1=nodePointer1->next;
		}	
	} else {
		printf("Lists are not equal. Different lengths: (list1Length, list2Length)=(%d, %d)\n", mainPointer1->listLength, mainPointer2->listLength);
	}
}
void	CheckEmpty			(MainN* mainPointer){						//		h)	Testar se o conjunto e vazio.
}
void	Clean				(MainN* mainPointer){
}
