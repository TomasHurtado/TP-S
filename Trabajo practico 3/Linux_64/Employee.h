#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
int employee_generarId(void);
void employee_iniciarId(int val);

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdchar(Employee* this,char* id);


int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadaschars(Employee* this,char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setSueldochar(Employee* this,char* sueldo);

int employee_comparaNombre(void *this,void *that);
int employee_searchId(LinkedList* pArrayListEmployee, int id);


#endif // employee_H_INCLUDED

