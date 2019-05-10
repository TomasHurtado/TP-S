#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleados.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array empleados Array of empleados
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int empleados_Inicializar(Empleado array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int empleados_buscarEmpty(Empleado array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int empleados_buscarID(Empleado array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int empleados_alta(Empleado array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(empleados_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            utn_getName("nombre\n: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
            utn_getTexto("apellido\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lastname);
            utn_getFloat("salario:\n ","\nError",1,100000,1,1000000000,1,&array[posicion].salary);
            utn_getUnsignedInt("\nsector: ","\nError",1,sizeof(int),1,1000,1,&array[posicion].sector);
            printf("\n Posicion: %d\n ID: %d\n name: %s\n lastname: %s \nsalary: %.3f\n sector: %d\n",
                   posicion, array[posicion].idUnico,array[posicion].name,array[posicion].lastname,array[posicion].salary,array[posicion].sector);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra un elemento del array por ID
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int empleados_baja(Empleado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(empleados_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].sector=0;
            array[posicion].salary=0;
            strcpy(array[posicion].name,"");
            strcpy(array[posicion].lastname,"");
            retorno=0;
        }
    }
    return retorno;
}






/** \brief Busca un elemento por ID y modifica sus campos
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int empleados_modificar(Empleado array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(empleados_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
               printf("\n Posicion: %d\n ID: %d\n name: %s\n lastname: %s \nsalary: %f\n sector: %d\n",
                   posicion, array[posicion].idUnico,array[posicion].name,array[posicion].lastname,array[posicion].salary,array[posicion].sector);
                utn_getUnsignedInt("\nModificar: 1nombre 2apellido 3salario 4sector 5salir","\nError",1,sizeof(int),1,12,1,&opcion);
                switch(opcion)
                {
                    case 1:
                         utn_getName("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].name);
                    case 2:
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,array[posicion].lastname);
                        break;
                    case 3:
                         utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].salary);
                        break;
                    case 4:
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].sector);
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=5);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo nombre los elementos de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int empleados_ordenarPorString(Empleado array[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;
    float bufferFloat;
    char bufferLongString[TEXT_SIZE];

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].name);
            bufferId=array[i].idUnico;
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].sector;
            bufferFloat=array[i].salary;
            strcpy(bufferLongString,array[i].lastname);


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].name)<0)
            {
                strcpy(array[j + 1].name,array[j].name);
                array[j + 1].idUnico=array[j].idUnico;
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].sector=array[j].sector;
                array[j + 1].salary=array[j].salary;
                strcpy(array[j + 1].lastname,array[j].lastname);
                j--;
            }
            strcpy(array[j + 1].name,bufferString);
            array[j + 1].idUnico=bufferId;
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].sector=bufferInt;
            array[j + 1].salary=bufferFloat;
            strcpy(array[j + 1].lastname,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int empleados_listar(Empleado array[], int size)                      //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n sector: %d\n salary: %2.f\n name: %s\n lastname: %s",
                       array[i].idUnico,array[i].sector,array[i].salary,array[i].name,array[i].lastname);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief saca promedio de un array
*\param array empleados Array de empleados
*\param size int Tamaño del array
*\return int Return (-1) si Error -(0) si se promedia exitosamente
*/
int empleados_promedio(Empleado array[],int size)
{
    float acumulador=0;
    int contador=0;
    int i;
    float promedio=0;
    int ret=-1;
    for(i=0;i<size;i++)
    {
        acumulador=acumulador+array[i].salary;
        contador++;
        ret=0;
    }
    promedio=acumulador/contador;
    printf("el total de los salarios es %3.f y el promedio es %3.f y los empleados con salario superior al promedio es %d",acumulador,promedio,contador);
    return ret;
}
