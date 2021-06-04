#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

// #include <PilhaJV.h>
// #include "B:\HDExterno\UENF\4Periodo\Estruturas de Dados\GitHub_Repository\DataStructure\Lists\LE2\Questões\1-4 Pilha\PilhaJV.h"

/*  Q2 - Palindromo

Um palindromo eh uma string que pode ser lida para frente e para tras com o mesmo resultado.
Por exemplo, as seguintes frases sao palindromos:

A base do teto desaba.
A diva em Argel alegra-me a vida.
Adias a data da saida.
Socorram-me, subi no onibus em Marrocos.

Observe que nos palindromos se deve ignorar o espacamento, a pontuacao, e as diferencas entre letras maiusculas e minusculas.
Escreva uma funcao para testar se uma string eh um palindromo usando uma pilha. A ideia eh armazenar os caracteres da string
na pilha e recuperar eles formando uma nova string. Depois comparar a nova string com a string original. Teste a sua funcao
com os exemplos mostrados acima.

*/

void insertStrings    (char teto, char argel, char adias, char marrocos) {
  
}

void cleanString      (char original, char limpa) {

}

void invertString     (char limpa, char invertida) {

}

void palindromeCheck  (char limpa, char invertida) {

}

int main () {
  int size=50;
  char stringOriginal[size], stringLimpa[size], stringInvertida[size];
  char teto[size], argel[size], adias[size], marrocos[size];

    /*
      Precisaremos de funcoes para
      Filtrar (espacos, pontuacao, maiúscula, (acentuação))
      Inserir caracteres na pilha
      remover caracteres da pilha em uma outra string
      comparar duas strings e retorne booleano (strcmp)

    */
  
  insertStrings   (teto, argel, adias, marrocos);   //Create all strings that are going to be tested
  cleanString     (stringOriginal, stringLimpa);    //Clean all non-
  invertString    (stringLimpa, stringInvertida);
  palindromeCheck (stringLimpa, stringInvertida);
}
