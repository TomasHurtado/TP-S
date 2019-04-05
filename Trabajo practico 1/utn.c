#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "utn.h"

/**
*\brief Recibe un conjunto de caracteres y valida si es un numero
*\param Numero char corresponde al conjunto de caracteres a validar
*\return Devuelve un 1 si es un numero o 0 si es otro caracter
*/

int validar_numero(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            printf("Error solo numeros\n");
            return 0;
        }
    }
    return 1;
}

/**
*\brief Recibe dos numeros y calcula la suma entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la suma
*/

int sumar(int numerouno,int numerodos)
{
    int suma;
    suma=numerouno+numerodos;
    return suma;
}

/**
*\brief Recibe dos numeros y calcula la resta entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la resta
*/

int restas(int numerouno,int numerodos)
{
    int resta;
    resta=numerouno-numerodos;
    return(resta);
}

/**
*\brief Recibe dos numeros y calcula la divicion entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la divicion
*/

float divicion(float numerouno,float numerodos)
{
    float dividir;
    if(numerouno==0 || numerodos==0)
    {
        return -1;
    }else
    {
        dividir=numerouno/numerodos;
        return(dividir);
    }
}

/**
*\brief Recibe dos numeros y calcula la multiplicacion entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la multiplicacion
*/

int multiplacion(int numerouno,int numerodos)
{
    int multiplo;
    multiplo=numerouno*numerodos;
    return(multiplo);
}

/**
*\brief Recibe un numero y calcula su factorial
*\param Int numero es el numero a sacar el factorial
*\return Retorna el resultado del numero que se saca el factorial
*/
int factorial(int numero)
{
    int c;
    int fact=1;
    for (c = 1; c <= numero; c++)
    {
    fact = fact * c;
    }
    return(fact);
}




