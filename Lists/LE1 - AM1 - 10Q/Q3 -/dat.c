#include<stdio.h>
#include<stdlib.h>
#include <String.h>
#include "dat.h"


char converterString(int dia,int mes,int ano){
	char date	[10]="";
	char day	[2];
	char month	[2];
	char year	[4];
	
	sprintf(day, 	"%d", dia);
	sprintf(month, 	"%d", mes);
	sprintf(year, 	"%d", ano);
	
	strcpy(date, day);
	strcpy(date, "/");
	strcpy(date, month);
	strcpy(date, "/");
	strcpy(date, year);
	
	return *date;
}






struct data
{
	int dia;
	int mes;
    int ano;
};

Data* criaData(int dia, int mes,int ano)
{
	Data* dataDef = (Data*)malloc(sizeof(Data));
	if(dataDef == NULL)
	{
		printf("Memoria insuficiente\n");
		exit(1);
	}
	dataDef->dia = dia;
	dataDef->mes = mes;
    dataDef->ano = ano;
	return dataDef;
}

Data* novaData(Data* dataDef, int dias)
{
	Data* newData = (Data*)malloc(sizeof(Data));
	if(newData == NULL)
	{
		printf("Memoria insuficiente\n");
		exit(1);
	}
	int num,mes,ano;
	num=dataDef->dia;
	mes=dataDef->mes;
    ano=dataDef->ano;
	newData->dia = num;
	newData->mes = mes;
    newData->ano = ano;
	return newData;
}




void liberarData(Data* dataDef){
	free(dataDef);
}

void liberarNovaData(Data* newData){
	free(newData);
}
