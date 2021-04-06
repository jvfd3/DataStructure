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

MainN* 	CreateEmptyList(){												//		a)	Criar uma lista vazia.
	MainN* pointer = (MainN*) malloc (sizeof(MainN));
	pointer->first=NULL;
	pointer->last=NULL;
	pointer->listLength=0;
	printf("A new list was created at pointer: (%X)\n", pointer);
	return pointer;
}
void 	ShowList			(MainN* mainPointer){						//		mostrar lista
	int loopCounter;
	N* nodePointer=mainPointer->first;
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
void 	ShowListPointers	(MainN* mainPointer){						//		mostrar ponteiros da lista
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
		
//		printf("Removed  element %d. List:\t", mainPointer->last->intValue);
		free(mainPointer->last);
		mainPointer->listLength--;
		
		int loopCounter;
		N* nodePointer=mainPointer->first;
		
		for (loopCounter=1;loopCounter<mainPointer->listLength;loopCounter++){
			nodePointer=nodePointer->next;
		}
		nodePointer->next=NULL;
		mainPointer->last=nodePointer;
				
//		ShowList(mainPointer);
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
void	CheckNumberIndex	(MainN* mainPointer, int numberToCheck){	//		d)	Testar se um numero pertence ao conjunto.
	int loopCounter;
	N* nodePointer=mainPointer->first;
	printf("Found on index ");
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		if(nodePointer->intValue==numberToCheck){	
			printf("%d\n", loopCounter);
		}
		nodePointer=nodePointer->next;
	}
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
		printf("%d was found in the list. ", numberToCheck);
		CheckNumberIndex(mainPointer, numberToCheck);
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
		
		int loopCounter1, loopCounter2, hasSameElement1=0, hasSameElement2=0;
		N* nodePointer1;
		N* nodePointer2;
		
		nodePointer1=mainPointer1->first;
		nodePointer2=mainPointer2->first;
		
		for(loopCounter1=1;loopCounter1<=mainPointer1->listLength;loopCounter1++){
			for(loopCounter2=1;loopCounter2<=mainPointer2->listLength;loopCounter2++){
//				printf("(Leng1,Leng2)=(%d,%d)\t",mainPointer1->listLength,mainPointer2->listLength);
//				printf("(L2,L1)=(%d,%d)=(%d,%d)\n", loopCounter2, loopCounter1, nodePointer2->intValue, nodePointer1->intValue);
				if(nodePointer1->intValue==nodePointer2->intValue){
					hasSameElement1+=1;
					break;
				}
				nodePointer2=nodePointer2->next;
			}
			if(hasSameElement1==loopCounter1){
//				printf("Element %d of list () matches with element on list ().\n", nodePointer1->intValue, nodePointer1, nodePointer2);
			} else {
				printf("Element %d on list () doesn't has a match on list ().\n", nodePointer1->intValue, nodePointer1, nodePointer2);
			}
			nodePointer2=mainPointer2->first;
			nodePointer1=nodePointer1->next;
		}
		
//		printf("\n\nEnd of first for pairs.\n\n");
		
		nodePointer1=mainPointer1->first;
		nodePointer2=mainPointer2->first;
		for(loopCounter2=1;loopCounter2<=mainPointer2->listLength;loopCounter2++){
			for(loopCounter1=1;loopCounter1<=mainPointer1->listLength;loopCounter1++){
//				printf("(Leng1,Leng2)=(%d,%d)\t",mainPointer1->listLength,mainPointer2->listLength);
//				printf("(L2,L1)=(%d,%d)=(%d,%d)\n", loopCounter2, loopCounter1, nodePointer2->intValue, nodePointer1->intValue);
				if(nodePointer1->intValue==nodePointer2->intValue){
					hasSameElement2+=1;
					break;
				}
				nodePointer1=nodePointer1->next;
			}
			if(hasSameElement2==loopCounter2){
//				printf("Element %d of list () matches with element on list ().\n", nodePointer2->intValue, nodePointer2, nodePointer1);
			} else {
				printf("Element %d on list () doesn't has a match on list ().\n", nodePointer2->intValue, nodePointer2, nodePointer1);
			}
			nodePointer1=mainPointer1->first;
			nodePointer2=nodePointer2->next;
		}
		
		if((hasSameElement1==hasSameElement2)&&((hasSameElement1>0)&&(hasSameElement2>0))){
			printf("Lists are equal.\n");
		} else{
			printf("Lists are not equal.\n");
		}
	} else {
		printf("Lists are not equal. Different lengths: (list1Length, list2Length)=(%d, %d)\n", mainPointer1->listLength, mainPointer2->listLength);
	}
//	printf("end of equality.\n");
}
void	CheckEmpty			(MainN* mainPointer){						//		h)	Testar se o conjunto e vazio.
	if (mainPointer->listLength==0){
		printf("Contains zero elements (%d), ",mainPointer->listLength);
		if (mainPointer->first==NULL){
			printf("No First (%X), ", mainPointer->first);
			if (mainPointer->last==NULL){
				printf("No Last (%X), ",mainPointer->last);
				printf("So the list (%X) is empty. \n", mainPointer);
			} else {
				printf("List (%X) has a last element (%X), so it's not empty.\n", mainPointer, mainPointer->last);
			}
		} else {
			printf("List (%X) has a first element (%X), so it's not empty.\n", mainPointer, mainPointer->first);
		}	
	} else {
		printf("List (%X) has length (%d), so it's not empty.\n", mainPointer, mainPointer->listLength);
	}	
}
void	Clean				(MainN* mainPointer){
	
	printf("Cleaning list %X.\n", mainPointer);
	int loopCounter;
	N* nodePointer=mainPointer->first;
	N* lastNodePointer;
	for(loopCounter=1;loopCounter<mainPointer->listLength;loopCounter++){
//		printf("(%d,%d)\n",loopCounter,nodePointer->intValue);
		lastNodePointer=nodePointer;
		nodePointer=nodePointer->next;
		free(lastNodePointer);
	}
	free(mainPointer);
	free(nodePointer);
	free(lastNodePointer);
	printf("Cleaned.\n");
}

void RunList(MainN* mainPointer){
	int loopCounter;
	N* nodePointer=mainPointer->first;
	for(loopCounter=0;loopCounter<mainPointer->listLength;loopCounter++){
		
		nodePointer=nodePointer->next;
	}
}

void Variations(){
	MainN* l1=CreateEmptyList();		//		a)	Criar uma lista vazia.
	InsertElement(l1,111);				//		b)	Inserir um elemento no conjunto.
	InsRemElementsTest1(l1);			//		Insert:	1) First;	2) Last	(OK);	3) Random;	4)In order;
	RemoveLastElement(l1);				//		c)	Remover um elemento do conjunto.
	CheckNumber(l1,333);				//		d)	Testar se um número pertence ao conjunto.
	CheckNumber(l1,444);				//		d)	Testar se um número pertence ao conjunto.
	SmallestValue(l1);					//		e)	Menor valor do conjunto.
	// BiggestValue(l1);				//		e)	Menor valor do conjunto.
	MainN* l2=CreateEmptyList();
	InsertElementsTest2(l2);
	MainN* l3=CreateEmptyList();
	Concatenate(l1,l2,l3);				//		f)	União de dois conjuntos.
	CheckEquality(l1,l2);				//		g)	Testar se os dois conjuntos são iguais.
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
	CheckEmpty(l1);					//		h)	Testar se o conjunto é vazio.
	MainN* l6=CreateEmptyList();
	CheckEmpty(l6);	
	Clean(l1);
	Clean(l2);
	Clean(l3);
	Clean(l4);
	Clean(l5);
	Clean(l6);
}
