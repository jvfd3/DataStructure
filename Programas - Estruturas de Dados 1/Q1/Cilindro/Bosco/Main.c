#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Cilindro.h"



int main()
{
    float r, h, a;

    Cilindro *v , *at;

        printf("Digite o raio do cilindro: ");
        scanf("%f", &r);

        printf("Digite a altura do cilindro: ");
        scanf("%f", &h);


    v = volume(r,h);// Chamando a função que calcula o volume
        printf("\nO Volume: %.2f ", v);


    at = areatotal(r,h,a); // Chamando a função que calcula a area
        printf("\nA Area total: %.2f", &at);

    system("pause");
    return 0;

}
