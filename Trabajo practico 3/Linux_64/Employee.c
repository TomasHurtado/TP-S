#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
static int idgen=0;


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

int employee_generarId(void)
{
    return idgen++;
}

void employee_iniciarId(int val)
{
    idgen= val;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* emp=employee_new();
    if(emp!=NULL)
    {
        employee_setIdchar(emp,idStr);
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadaschars(emp,horasTrabajadasStr);
        employee_setSueldochar(emp,sueldo);

    }


    return emp;
}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = -1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


int employee_setIdchar(Employee* this,char* id)
{
    int val;
    int retorno = -1;
    if(this != NULL &&  isValidnumeric(id))

    {
        val=atoi(id);
        this->id = val;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadaschars(Employee* this,char* horasTrabajadas)
{
    int val;
    int retorno = -1;
    if(this != NULL && isValidnumeric(horasTrabajadas))
    {
        val=atoi(horasTrabajadas);
        this->horasTrabajadas = val;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldochar(Employee* this,char* sueldo)
{
    int val;
    int retorno = -1;
    if(this != NULL && isValidNumber(sueldo))
    {
        val=atoi(sueldo);
        this->sueldo = val;
        retorno = 0;
    }
    return retorno;
}

int employee_comparaNombre(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Employee*)this)->nombre,((Employee*)that)->nombre);
    if (comparacion<0)
    {
        retorno=1;
    }
    else if (comparacion>0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int employee_searchId(LinkedList* pArrayListEmployee, int id)
{
    int retorno=-1;
    int len;
    int i;
    int auxId;
    if (pArrayListEmployee!=NULL && id>=0 && ll_len(pArrayListEmployee)>=0)
    {
        len=ll_len(pArrayListEmployee);
        for (i=0;i<len;i++)
        {
            employee_getId(ll_get(pArrayListEmployee,i),&auxId);
            if (id==auxId)
            {
                retorno=i;
                break;
            }
        }

    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}
