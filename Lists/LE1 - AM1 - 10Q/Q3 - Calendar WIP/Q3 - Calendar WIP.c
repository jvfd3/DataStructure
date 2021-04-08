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

//int isValid(int d, int m, int a){
//	int intValid=1;
//	
//	if(a<0 || m<0 || m>12 || d<0 || d>31){
//		intValid=0;
//	}
//	if (){
//		intValid=0;
//	}
//	
//	if (m==2){
//		
//	} else if (m<8){
//		
//	}
//	
//	return intValid;
//}
char *insertZero(int n){
//	char zero[1]="0";
	if (n<10){
//		return zero;
		return "0";
	} else {
		return "";
	}
}

char *toString(int d, int m, int a){
	char stringD[2], stringM[2], stringA[4];
	char data[10]="";
//	char *data="";
	
	printf("Inteiros:\t%d/%d/%d\n",d,m,a);
	
	sprintf(stringD,     "%d", d);
    sprintf(stringM,     "%d", m);
    sprintf(stringA,     "%d", a);
//    TODO: COLOCAR 0 CASO MES<10
	printf("Strings:\t%s/%s/%s\n",stringD,stringM,stringA);
	
    strcat(data, insertZero(d));
    strcat(data, stringD);
    strcat(data, "/");
    strcat(data, insertZero(m));
    strcat(data, stringM);
    strcat(data, "/");
    strcat(data, stringA);
    
    printf("String:\t\t%s\n",data);
//	printf("%d\n", data);
//	return "test";
	return data;
}

//		a.	Uma função que recebe como parâmetro o dia, o mês, e o ano;
//		verifica se a data for válida e converte ela em uma string no formato DD/MM/AAAA.
void a(int d, int m, int a){
	
//	if(isValid(d,m,a)){
//		printf("%s", toString(d, m, a));
//	}
	const char* returnedString = toString(d, m, a);
	printf("returned String:\t%s\n", returnedString);
	
}
		
int main () {
	
	a(05,06,2021);

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
