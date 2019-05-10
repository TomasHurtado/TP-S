#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleados.h"


#define QTY_TIPO 1000

int main()
{
    int opcion;
    int contadorIdempleados=0;
    Empleado arrayEmpleado[QTY_TIPO];


    empleados_Inicializar(arrayEmpleado,QTY_TIPO);


    do
    {
        utn_getUnsignedInt("\nEmpleadoes\n1) Alta \n2) Modificar \n3) Baja \n4)informe \n5)Salir\n",
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                empleados_alta(arrayEmpleado,QTY_TIPO,&contadorIdempleados);
                break;
            case 2: //Modificar
                empleados_modificar(arrayEmpleado,QTY_TIPO);
                break;

            case 3: //Baja
                empleados_baja(arrayEmpleado,QTY_TIPO);
                break;

            case 4://Listar
                empleados_ordenarPorString(arrayEmpleado,QTY_TIPO);
                empleados_listar(arrayEmpleado,QTY_TIPO);
                break;

            case 5://Informe
                break;
            default:
                printf("\nOpcion no valida");

        }
    }
    while(opcion!=5);
    return 0;
}
