/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);// obtiene un nodo
int ll_set(LinkedList* this, int index,void* pElement);// modifica el puntero del nodo seleccionado
int ll_remove(LinkedList* this,int index);// se dirige al nodo anterior del que queremos eliminar y apunta al nodo siguiente al que queremos eliminar, si queremos eliminar el nodo 15, apunta del 14 al 16
int ll_clear(LinkedList* this);// se dirige al nodo anterior del que queremos eliminar y apunta al nodo siguiente al que queremos eliminar, si queremos eliminar el nodo 15, apunta del 14 al 16
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);// devuelve el indice de un nodo
int ll_isEmpty(LinkedList* this); // retorna verdadero o falso si esta vacio
int ll_push(LinkedList* this, int index, void* pElement);// inversa del remove, inserta un nodo entre dos nodos ya existentes
void* ll_pop(LinkedList* this,int index); // remove mejorado, elimina un nodo pero me devuelve el puntero que contiene, al mismo tiempo que retira el nodo de la linked list, obtengo los datos que almacenaba
int ll_contains(LinkedList* this, void* pElement);//retorna si el elemento esta o no esta, verdadero o falso, solo si existe o no, no devuelve el indice ni nada como indexOf, recibe un nodo
int ll_containsAll(LinkedList* this,LinkedList* this2);// recibe dos listas, y retorna verdadero o falso si los elementos de la segunda lista se encuentra contenida en la primer lista, o vice versa
LinkedList* ll_subList(LinkedList* this,int from,int to);// slicing, truncamos la lista con un desde y hasta y nos quedamos con un pedazo, devuelve una nueva lista que contiene solo los elementos desde y hasta
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

//int ll_sort(LinkedList* this,
  //          int (*pFunc)(void* ,void*), // punhtero a funcion, meter el nombre de la funcion entre parentesis y agregar un * antes del nombre, el parentesis es para no confundir el puntero a funcion con un puntero a int
    //         int order);//ordenamos de forma ascendente y descendente

// aca decidimos bajo que criterio ordenamos, nombre, edad,apellido,sarasa (el if, strcmp)
// retorna -1,0 o 1 para decidir si ordena(swap) o no
//int criterioOrden(void* thisA, void* thisB);

// ejemplo de llamado a sort utilizando puntero a la funcion
 //ll_sort(listaEmpleados,
  //       criterioOrden,
    //     1);

