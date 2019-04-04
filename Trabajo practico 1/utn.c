#include <stdio.h>
#include <stdlib.h>

float utn_pedir_primerNumero(float* numerouno,char msg[])
{
    float primernumero;


    printf(msg);
    scanf("%f",&primernumero);
    return primernumero;
}


float utn_pedir_segundoNumero(float* numerodos,char mng[])
{
    float segundonumero;


    printf(mng);
    scanf("%f",&segundonumero);
    return segundonumero;
}
