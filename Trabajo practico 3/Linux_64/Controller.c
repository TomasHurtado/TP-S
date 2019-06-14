#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    parser_EmployeeFromText(pFile , pArrayListEmployee);
    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE* pfile=fopen(path,"rb");
    if(pfile!=NULL)
    {
        ret=parser_EmployeeFromBinary(pfile,pArrayListEmployee);
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int id;
    char nombre[128];
    int sueldo;
    int horas;
    int ret=-1;
    pEmp= employee_new();
    id=employee_generarId();
    utn_getName("Ingrese nombre","Error",0,128,2,nombre);
    utn_getUnsignedInt("Ingrese sueldo","Error",0,1000,0,900000,2,&sueldo);
    utn_getUnsignedInt("Ingrese horas","Error",0,1000,0,900000,2,&horas);

    if(pEmp!=NULL && !employee_setId(pEmp,id) && !employee_setNombre(pEmp,nombre) && !employee_setSueldo(pEmp,sueldo) && !employee_setHorasTrabajadas(pEmp,horas))
    {

            ll_add(pArrayListEmployee,pEmp);
            ret=0;

    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int idaEditar;
    char nombre[128];
    int sueldo;
    int horas;
    int opcion;
    Employee *pEmp;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),0,30000,1,&id);
        idaEditar=employee_searchId(pArrayListEmployee,id);
        if(idaEditar==-1)
        {
            printf("\nError");
        }
        else
        {
            do
            {
                pEmp=ll_get(pArrayListEmployee,idaEditar);

                utn_getUnsignedInt("\nModificar: \n1) Nombre \n2) Horas trabajadas \n3) Sueldo \n4)salir","\nError",1,10000,1,100000,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("\nIngrese nombre: ","\nError",1,128,1,nombre);
                        employee_setNombre(pEmp,nombre);
                        break;
                    case 2:
                        utn_getUnsignedInt("\nIngresde horas: ","\nError",1,sizeof(int),0,30000,1,&horas);
                        employee_setHorasTrabajadas(pEmp,horas);
                        break;
                    case 3:
                        utn_getUnsignedInt("\nIngrese sueldo: ","\nError",1,sizeof(int),0,30000,1,&sueldo);
                        employee_setSueldo(pEmp,sueldo);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
 int retorno=-1;
    int id;
    int idaEliminar;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID a eliminar: ","\nError",1,6,0,30000,1,&id);
        idaEliminar=employee_searchId(pArrayListEmployee,id);
        if(idaEliminar==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEmployee,idaEliminar);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int id;
    int sueldo;
    int horas;
    char nombre[128];
    int size;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&id);
            employee_getNombre(pEmp,nombre);
            employee_getSueldo(pEmp,&sueldo);
            employee_getHorasTrabajadas(pEmp,&horas);
            if(pEmp!=NULL)
            {
                printf("Id: %d,Nombre: %s,Horas trabajadas: %d,Sueldo: %d\n",id,nombre,horas,sueldo);
            }
        }
    }
   return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if (pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_comparaNombre,1);
        retorno=0;
    }
    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int size;
    int i;
    char nombre[1024];
    int sueldo;
    int id;
    int hstrabajada;
    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {
        fprintf(pfile,"id,nombre,horasTrabajadas,sueldo\n");
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);

            employee_getId(pEmp,&id);
            employee_getNombre(pEmp,nombre);
            employee_getSueldo(pEmp,&sueldo);
            employee_getHorasTrabajadas(pEmp,&hstrabajada);

            //fprintf(pfile,"%d,%s,%d,%d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
            fprintf(pfile,"%d,%s,%d,%d\n",id,nombre,hstrabajada,sueldo);

        }
        fclose(pfile);
    }



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int size;
    int i;

    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {

        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);


            fwrite(pEmp,sizeof(Employee),1,pfile);


        }
        fclose(pfile);
    }

    return 1;
}
