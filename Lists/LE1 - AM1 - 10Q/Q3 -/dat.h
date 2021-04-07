typedef struct data Data;


char converterString(int dia,int mes,int ano);

Data* criaData(int dia, int mes,int ano);

Data* novaData(Data* dataDef,int dias);

void liberarData(Data* dataDef);
void liberarNovaData(Data* newData);
