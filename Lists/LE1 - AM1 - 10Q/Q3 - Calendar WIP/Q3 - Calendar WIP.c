#include <stdio.h>
#include <stdlib.h>
#include <String.h>

/*
	3.
		Especifique um TAD que seja capaz de armazenar uma data composta por dia, m�s e ano e implemente o seguinte conjunto de opera��es para manipular esse tipo Data:
		a.	Uma fun��o que recebe como par�metro o dia, o m�s, e o ano; verifica se a data for v�lida e converte ela em uma string no formato DD/MM/AAAA.
		b.	Uma fun��o que recebe como par�metro uma data de tipo string (formato DD/MM/AAAA) e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
		c.	Uma fun��o que recebe como par�metro uma estrutura do tipo Data e um n�mero de dias, e retorna a estrutura modificada com soma da data original mais o n�mero de dias recebido.
		Teste o TAD com uma aplica��o.

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

int isValid(int d, int m, int a){
	return 1;
}

const char* toString(int d, int m, int a){
	char stringD[2], stringM[2], stringA[8];
	char data[10]="";
	int i;
	
//	printf("%d/%d/%d\n",d,m,a);
	sprintf(stringD,     "%d", d);
    sprintf(stringM,     "%d", m);
    sprintf(stringA,     "%d", a);
    
//	printf("%s/%s/%s\n",stringD,stringM,stringA);
    strcat(data, stringD);
    strcat(data, "/");
    strcat(data, stringM);
    strcat(data, "/");
    strcat(data, stringA);
    
//    printf("%s",date);
//	printf("%d", data);
	return data;
}

void a(int d, int m, int a){
//		a.	Uma fun��o que recebe como par�metro o dia, o m�s, e o ano;
//		verifica se a data for v�lida e converte ela em uma string no formato DD/MM/AAAA.
	printf("%s", toString(d, m, a));
//	toString(d, m, a);
}
//void b(string stringData, d* data){
//		b.	Uma fun��o que recebe como par�metro uma data de tipo string (formato DD/MM/AAAA)
//		e uma estrutura do tipo Data. Armazena os dados da string na estrutura.
//}
void c(){	
//		c.	Uma fun��o que recebe como par�metro uma estrutura do tipo Data e um n�mero de dias,
//		e retorna a estrutura modificada comsoma da data original mais o n�mero de dias recebido.
}
		
int main () {
//	d* data=CreateStruct();
//	setStruct(data,31,12,2021);
	
	a(31,12,2021);
//	b();
//	c();
}
