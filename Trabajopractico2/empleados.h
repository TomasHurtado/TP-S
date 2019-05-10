#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char name[TEXT_SIZE];
    char lastname[TEXT_SIZE];
    float salary;
    int sector;
}Empleado;


#endif // EMPLEADOS_H_INCLUDED

int empleados_Inicializar(Empleado array[], int size);
int empleados_buscarEmpty(Empleado array[], int size, int* posicion);
int empleados_buscarID(Empleado array[], int size, int valorBuscado, int* posicion);
int empleados_alta(Empleado array[], int size, int* contadorID);
int empleados_baja(Empleado array[], int sizeArray);
int empleados_modificar(Empleado array[], int sizeArray);
int empleados_ordenarPorString(Empleado array[],int size);
int empleados_listar(Empleado array[], int size);
int empleados_promedio(Empleado array[],int size);
