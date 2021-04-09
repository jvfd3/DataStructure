#include <stdio.h>
#include <stdlib.h>
#include <String.h>

/*
	3.
		Especifique um TAD que seja capaz de armazenar uma data composta por dia, mes e ano e implemente o seguinte conjunto de operações para manipular esse tipo Data:
		a.	Uma funcao que recebe como parametro o dia, o mes, e o ano; verifica se a data for valida e converte ela em uma string no formato DD/MM/AAAA.
		b.	Uma funcao que recebe como parametro uma data de tipo string (formato DD/MM/AAAA) e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
		c.	Uma funcao que recebe como parametro uma estrutura do tipo Data e um numero de dias, e retorna a estrutura modificada com soma da data original mais o numero de dias recebido.
		Teste o TAD com uma aplicacao.

*/

typedef struct  dat{
	int dia;
	int mes;
	int ano;
}d;


d* CreateStruct (){
	d* data = (d*) malloc ( sizeof (d) );
	if(data != NULL){
		return data;
	}
	return NULL;
}

void setStruct(d* data, int d, int m, int a){
	data->dia=d;
	data->mes=m;
	data->ano=a;
}

int isBissexto(int a){
	return (( a % 4 == 0 && a % 100 != 0 ) || a % 400 == 0 );
}

int isValid (int d, int m, int a){
	int intValid=1;
	
	if(a<0 || a>9999 || m<0 || m>12 || d<0 || d>31){
		intValid=0;
	} else {
		if (m==2){
			if (isBissexto(a)){
				if (d>29){
					intValid=0;
//					printf("dia>29/02/bissexto\n");
				}
			} else {
				if (d>28){
					intValid=0;
//					printf("dia>28/02/nao-bissexto\n");
				}
			}		
		} else if (m>0 && m<8){
			if (!(m%2) && d>30){	
				intValid=0;
//				printf ("dia>30/impares entre 1 e 7/ano\n");
			}
		} else if (m>7 && m<13){
			if (m%2 && d>30){
				intValid=0;
//				printf("dia>30/pares entre 8 e 12/ano\n");
			}
		}
	}
	
	
	return intValid;
}

char* toString(int d, int m, int a){
	char stringD[2], stringM[2], stringA[4];
	char data[10]="";
	
	
	sprintf(stringD,     "%d", d);
    sprintf(stringM,     "%d", m);
    sprintf(stringA,     "%d", a);
	
	if (d<10){
    	strcat(data, "0");
	}
    strcat(data, stringD);
    strcat(data, "/");
	if (m<10){
    	strcat(data, "0");
	}
    strcat(data, stringM);
    strcat(data, "/");
    int qtdZeroAno=0;
    if (a<10){
    	qtdZeroAno=3;
	} else if (a<100){
		qtdZeroAno=2;
	} else if (a<1000) {
		qtdZeroAno=1;
	}
	int i;
	for (i=0;i<qtdZeroAno;i++){
	    strcat(data, "0");
	}
    strcat(data, stringA);
    
	char* stringPointer = malloc(sizeof(data));
	if(stringPointer != NULL) {
		strcpy(stringPointer, data);
		return stringPointer;
	} else { 
	  printf("malloc failed\n");
	}
}

void testingValidity(){
	int dia,mes,ano;
	for(ano=0;ano<101;ano++){
		for(mes=1;mes<13;mes++){
			for(dia=1;dia<32;dia++){
				if (!isValid(dia,mes,ano)){
					printf("%d/%d/%d\n",dia,mes,ano);
				}
			}
		}	
	}
}

//	OK	a.	Uma função que recebe como parâmetro o dia, o mês, e o ano;
//	OK	verifica se a data for válida e
//	WIP	converte ela em uma string no formato DD/MM/AAAA.
void a(int d, int m, int a){
	int i;
//	if (isValid(d,m,a)) {
//		printf("valido\n");
//	} else {
//		printf("invalido\n");
//	}
	char* data=toString(d,m,a);
	printf("1) %s\n",data);
}
		
int main () {		

	a(9,12,20);
}



//	setStruct(data,31,12,2021);
//	d* data=CreateStruct();

//	b();
//	c();




//void b(string stringData, d* data){
//		b.	Uma função que recebe como parâmetro uma data de tipo string (formato DD/MM/AAAA)
//		e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
//}
//void c(){	
//		c.	Uma função que recebe como parâmetro uma estrutura do tipo Data e um número de dias,
//		e retorna a estrutura modificada comsoma da data original mais o número de dias recebido.
//}
