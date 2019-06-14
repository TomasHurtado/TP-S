#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int id;
    int maxId=-1;
    int retorno=-1;
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            if(pEmpleado != NULL)
            {
                if(ll_add(pArrayListEmployee,pEmpleado))
                {
                    employee_getId(pEmpleado,&id);
                    if (id>maxId)
                    {
                        maxId=id;
                    }
                    retorno=0;

                }
            }
              employee_iniciarId(maxId+1);
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pempleado;

    do{
        pempleado= employee_new();

        if(pempleado!= NULL && fread(pempleado,sizeof(Employee),1,pFile)==1)
        {
            ll_add(pArrayListEmployee,pempleado);
        }
        else
        {
            employee_delete(pempleado);
        }

    }while(!feof(pFile));

    return 1;
}

