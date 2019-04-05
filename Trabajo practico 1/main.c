#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "utn.h"

int main()
{   int numIngresado;
    int numeroa=0;
    int numerob=0;
    char numero[100];
    int nume=0;
    int sum=0;
    int resta=0;
    int multi=0;
    float divi=0;
    int fact=0;
    int facto=0;

    while(numIngresado!=10)
    {
        do
        {
        printf("\n1. Ingresar 1er operando A=%d",numeroa);
        printf("\n2. Ingresar 2do operando B=%d",numerob);
        printf("\n3. Calcular todas las operaciones");
        printf("\n4. Informar resultados");
        printf("\n5. Salir\n");
        scanf("%s",numero);
        nume=validar_numero(numero);
        }
         while(nume==0);
                {
                    numIngresado=atoi(numero);
                }

        switch(numIngresado)
        {
            case 1:
                do
                {
                    printf("\ningrese primer operador\n ");
                    scanf("%s",numero);
                    nume=validar_numero(numero);
                }
                while(nume==0);
                {
                    numeroa=atoi(numero);
                }

                break;
            case 2:
                 do
                {
                    printf("\ningrese segundo operador\n ");
                    scanf("%s",numero);
                    nume=validar_numero(numero);
                }
                while(nume==0);
                {
                    numerob=atoi(numero);
                }
                break;
            case 3:
                printf("\n1)Calcular la suma\n");
                printf("\n2)Calcular la resta\n");
                printf("\n3)Calcular la division\n");
                printf("\n4)Calcular la multiplicacion\n");
                printf("\n5)Calcular el factorial\n");
                scanf("%d",&numIngresado);

                switch(numIngresado)
                {
                    case 1:
                        sum=sumar(numeroa,numerob);
                        break;
                    case 2:
                        resta=restas(numeroa,numerob);
                        break;
                    case 3:
                        divi=divicion(numeroa,numerob);
                        break;
                    case 4:
                        multi=multiplacion(numeroa,numerob);
                        break;
                    case 5:
                        facto=factorial(numeroa);
                        fact=factorial(numerob);
                        break;
                }
                break;
            case 4:
                printf("\n1)Resultado de la suma es: \n%d",sum);
                printf("\n2)Resultado de la resta es: \n%d",resta);
                if(divi==-1)
                {
                  printf("\n3)No se puede dividir por cero\n");
                }
                else
                {
                 printf("\n3)Resultado de la division es: \n%.2f",divi);
                }
                printf("\n4)Resultado de la multiplicacion es: \n%d",multi);
                printf("\n5)Factorial de %d = %d\n", numeroa,facto);
                printf("\n5)Factorial de %d = %d\n", numerob,fact);
                break;
            case 5:
                numIngresado=10;
                break;
        }
    }
    return 0;


}

