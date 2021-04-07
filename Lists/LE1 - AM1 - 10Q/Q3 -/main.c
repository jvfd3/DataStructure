#include<stdio.h>
#include<stdlib.h>
#include <String.h>
#include "dat.h"

int main()
{
    int dia,mes,ano,dias;
    char *data;

    printf("Por favor, informe a data:");
    scanf("%d",&dia);
    
    printf("Por favor, informe o mes:");
    scanf("%d",&mes);

    printf("Por favor, informe o ano:");
    scanf("%d",&ano);

    printf("Por favor, informe a quantidade de dias a ser adicionado:");
    scanf("%d",&dias);


    data=converterString(dia,mes,ano);
    printf("%s",data);
    Data* dataDef=criaData(dia,mes,ano);
    Data* newData=novaData(dataDef,dias);

    liberarData(dataDef);
    liberarNovaData(newData);
    return 0;
}
