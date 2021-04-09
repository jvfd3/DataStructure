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
	char* stringData;
	int dia;
	int mes;
	int ano;
}da;

da* CreateStruct (){
	da* data = (da*) malloc ( sizeof (da) );
	if(data != NULL){
		return data;
	}
	return NULL;
}

void setStruct(int d, int m, int a, char* sData, da* structData){
	structData->stringData=sData;
	structData->dia=d;
	structData->mes=m;
	structData->ano=a;
}

void printStruct(da* s){
	printf("(%X) = (%d,%d,%d) = (%s)\n", s, s->dia,s->mes,s->ano, s->stringData);
}

void cpyStruct(da* s1, da* s2){
	s1->dia=s2->dia;
	s1->mes=s2->mes;
	s1->ano=s2->ano;
	s1->stringData=s2->stringData;
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

char* a(int d, int m, int a){
//	OK	a.	Uma função que recebe como parâmetro o dia, o mês, e o ano;
//	OK	verifica se a data for válida e
//	OK	converte ela em uma string no formato DD/MM/AAAA.

	if (isValid(d,m,a)) {
		char* data=toString(d,m,a);
//		printf("%s\n",data);
		return data;
	} else {
		printf("Data invalida: (%d/%d/%d)\n",d,m,a);
	}
}

char* substring(char *destination, const char *source, int beg, int n){
//	FONT: https://www.techiedelight.com/implement-substring-function-c
    while (n > 0)
    {
        *destination = *(source + beg);
        destination++;
        source++;
        n--;
    }
    *destination = '\0';
    return destination;
}

void segmentaString(int* d, int* m, int* a, char* sData){
	char dia[2];
	char mes[2];
	char ano[4];
	substring(dia, sData, 0, 2);
	substring(mes, sData, 3, 2);
	substring(ano, sData, 6, 4);

//	printf("%s = %s,%s,%s\n", sData,dia,mes,ano);
	
	*d=atoi(dia);
	*m=atoi(mes);
	*a=atoi(ano);
	
//	printf("%s = %d,%d,%d\n", sData,d,m,a);
	
}

void b(char* sData, da* structData){
	//	OK	Uma funcao que recebe como parametro uma data de tipo string (formato DD/MM/AAAA) e uma estrutura do tipo Data.
	//	OK	Armazena os dados da string na estrutura.
	
	int d,m,a;
	
	segmentaString(&d, &m, &a, sData);
//	printf("%s = %d,%d,%d\n", sData,d,m,a);

	setStruct(d, m, a, sData, structData);
//	printStruct(structData);
	
}

void simpleSumValidation(da* data, int dias){
	int d,m,a;
	
	d=data->dia;
	m=data->mes;
	a=data->ano;
	
	d+=dias;
	
	while (d > 31){
		d-=31;
		m++;
		while(m==13 ){
			m-=12;
			a++;
		}
	}
	
	data->dia=d;
	data->mes=m;
	data->ano=a;
	
	data->stringData=toString(data->dia,data->mes,data->ano);
	
}

int checkMax(int m, int a){
	int max;
	
	if (m==2){
		if (isBissexto(a)){
			max=29;
		} else {
			max=28;
		}		
	} else if (m>0 && m<8){
		if (m%2){	
			max=30;
		} else {
			max=31;
		}
	} else if (m>7 && m<13){
		if (m%2){
			max=31;
		} else {
			max=30;
		}
	}
	
	return max;
}

void advancedSumValidation(da* data, int dias){		//STILL NOT WORKING PROPERLY, BUT CLOSE ENOUGH
	int d,m,a;
	
	d=data->dia;
	m=data->mes;
	a=data->ano;
	
	int max=checkMax(m,a);
	
	d+=dias;
//	int cont=0;
	
//		printf("max/d/m/a\n");
	while (d >= max){
//		cont++;
//		printf("%d/%d/%d/%d\n",max,d,m,a);
		d-=max-1;
		m++;
		max=checkMax(m,a);
		while(m==13 ){
			m-=12;
			a++;
		}
	}
	
//	printf("%d\n",cont);
	
	data->dia=d;
	data->mes=m;
	data->ano=a;
	
	data->stringData=toString(data->dia,data->mes,data->ano);
}


da* c(da* sData, int d){	
//	OK	c.	Uma função que recebe como parâmetro uma estrutura do tipo Data e um número de dias,
//		e retorna a estrutura modificada com soma da data original mais o número de dias recebido.
	da* newData = CreateStruct();
	
	cpyStruct(newData,sData);
	
//	printStruct(sData);
//	printStruct(newData);
	
//	simpleSumValidation(newData,d);
	advancedSumValidation(newData,d);

	return newData;
}

int main () {
	char* stringData=a(30,12,2000);
	da* structData=CreateStruct();
	b(stringData,structData);
	da* structNewData = c(structData,55);
	printStruct(structNewData);
	structNewData = c(structData,56);
	printStruct(structNewData);
}

