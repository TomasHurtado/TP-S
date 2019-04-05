#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/**
*\brief Recibe un conjunto de caracteres y valida si es un numero
*\param Numero char corresponde al conjunto de caracteres a validar
*\return Devuelve un 1 si es un numero o 0 si es otro caracter
*/
int validar_numero(char numero[]);
/**
*\brief Recibe dos numeros y calcula la suma entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la suma
*/
int sumar(int numerouno,int numerodos);
/**
*\brief Recibe dos numeros y calcula la resta entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la resta
*/
int restas(int numerouno,int numerodos);
/**
*\brief Recibe dos numeros y calcula la divicion entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la divicion
*/

float divicion(float numerouno,float numerodos);
/**
*\brief Recibe dos numeros y calcula la multiplicacion entre ellos
*\param Int numerouno es el primer operador ingresado solicitado
*\param Int numerodos es el segundo operador ingresado solicitado
*\return Retorna el resultado de la multiplicacion
*/
int multiplacion(int numerouno,int numerodos);
/**
*\brief Recibe un numero y calcula su factorial
*\param Int numero es el numero a sacar el factorial
*\return Retorna el resultado del numero que se saca el factorial
*/
int factorial(int numero);



#endif // UTN_H_INCLUDED
