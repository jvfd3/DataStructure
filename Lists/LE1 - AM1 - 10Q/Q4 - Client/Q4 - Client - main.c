#include <stdlib.h>
#include <stdio.h>
#include <String.h>
/*
	4.	Os dados relativos aos clientes de uma empresa est�o armazenados em um arquivo.
	Para cada cliente s�o registrados um 
	
	c�digo, nome, o endere�o, o telefone,
	a data em que fez sua primeira compra na empresa,
	a data da �ltima compra e o valor da �ltima compra.
	
	Especifique o TAD Clientes para armazenar
	os dados dos clientes e as opera��es necess�rias
	para inserir, consultar e excluir esses dados.
	Implemente uma aplica��o que utilize o tipo Clientes.
*/


typedef struct Clientes{
	struct client *c;
	struct ClientList *next;
}ClientList;

typedef struct MainClientes{
	int listLength;
	ClientList* first;
	ClientList* last;
}MainClientList;

typedef struct Cliente {
	char *codigo;
	char *nome;
	char *endereco;
	char *telefone;
	char *dataPrimeiraCompra;
	char *dataUltimaCompra;
	char *valorUltimaCompra;	
}Client;


int main(){
	
}
