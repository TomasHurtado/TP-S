#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (nuevoNodo) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nuevoNodo = NULL;
    int i;
    if(nodeIndex>=0 && nodeIndex<ll_len(this) && this!=NULL)
    {
        nuevoNodo=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
            nuevoNodo=nuevoNodo->pNextNode;

        }

    }
    return nuevoNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = (Node*) malloc(sizeof(Node));
    Node* nodoAnterior;
    int len;
    len=ll_len(this);
    if (this!=NULL && nodeIndex>=0 && nodeIndex<=len && nuevoNodo!=NULL)
    {

        if (nodeIndex==0)
        {
            nuevoNodo->pElement=pElement;
            nuevoNodo->pNextNode=this->pFirstNode;
            this->pFirstNode=nuevoNodo;
            this->size++;
            returnAux=0;
        }
        if(nodeIndex>0)
        {
            nodoAnterior = getNode(this,nodeIndex-1);
            nuevoNodo->pNextNode=nodoAnterior->pNextNode;
            nuevoNodo->pElement=pElement;
            nodoAnterior->pNextNode=nuevoNodo;
            this->size++;
            returnAux=0;
        }

        if(nodeIndex==ll_len(this))
        {
            nodoAnterior = getNode(this,nodeIndex-1);
            nuevoNodo->pNextNode=NULL;
            nuevoNodo->pElement=pElement;
            nodoAnterior->pNextNode=nuevoNodo;
            this->size++;
            returnAux=0;

        }
    }
    else
    {
        free(nuevoNodo);
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    index=ll_len(this);

    if(addNode(this,index,pElement)==0)
    {
        returnAux=0;
    }



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo;
    nodo= getNode(this,index);
    if(nodo!=NULL && index>=0 && index<= ll_len(this))
    {
        returnAux=nodo->pElement;

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodomodif;
    nodomodif=getNode(this,index);
    if(nodomodif!=NULL && index>=0 && index<ll_len(this))
    {
        nodomodif->pElement=pElement;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoborrar;
    Node* nodoAnterior;
    nodoborrar=getNode(this,index);

    if(nodoborrar!=NULL && index>=0 && index<ll_len(this))
    {
        if (index==0)
        {

            nodoborrar->pNextNode=this->pFirstNode;
            this->pFirstNode=nodoborrar;

        }
        if(index>0)
        {
            nodoAnterior = getNode(this,index-1);
            nodoAnterior->pNextNode=nodoborrar->pNextNode;

        }

        this->size--;
        returnAux=0;
    }
    free(nodoborrar);
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;


    for(i=0;i<ll_len(this);i++)
    {
        if(ll_remove(this,i)==0)
        {
            returnAux=0;
        }
    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);


        returnAux=0;
        free(this);
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)//for+get if comparo
{
    int returnAux = -1;
    Node* nodobuscar;
    int i;
    for(i=0;i<ll_len(this);i++)
    {
        nodobuscar=getNode(this,i);
        if(nodobuscar->pElement==pElement)
        {
            returnAux=i;
            break;
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)//if zize
{
    int returnAux = -1;
    int len;
    len=ll_len(this);
    if(this!=NULL)
    {

        if(len==0 )
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }


    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)//add
{
    int returnAux = -1;
    if(index>=0 && index<=ll_len(this) && this!= NULL)
    {
        if(ll_add(this,pElement)==0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)//get + remove
{
    void* returnAux = NULL;
    Node* nodoAeliminar;
    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        nodoAeliminar=ll_get(this,index);

        returnAux=nodoAeliminar;
        ll_remove(this,index);

        if(ll_remove(this,index)==0)
        {
        this->size--;
        }

    }



    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)//indexoff>=0
{
    int returnAux = -1;
    int i=0;
    if(this!=NULL)
    {
        for(i=0;i<=ll_len(this);i++)
        {
            if(ll_indexOf(this,pElement)!=-1)
            {
                returnAux=1;
            }
            else
            {
                returnAux=0;
            }

        }
    }



    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)//for get una lista comparo con un if los elementos
{
    int returnAux = -1;
    int i;
    int j;
    Node* lista1;
    Node* lista2;
    if(this2!=NULL && this!=NULL)
    {
        for(i=0;i<=ll_len(this);i++)
        {
            lista1=ll_get(this,i);
           for(j=0;j<=ll_len(this2);j++)
           {
               lista1=ll_get(this,i);
               lista2=ll_get(this2,j);
               if(ll_len(this)==ll_len(this2))
               {
                   if(lista2==lista1)
                   {
                       returnAux=1;
                   }
               }
               else
                   {
                       returnAux=0;
                   }
           }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)//newllist + for get add
{
    LinkedList* cloneArray = NULL;
    int i;
    Node *lista;
    if (this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if (cloneArray!=NULL)
        {
            lista=this->pFirstNode;
            for(i=from;i<to;i++)
            {


                    addNode(cloneArray,i,lista->pElement);

                lista=lista->pNextNode;
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)//sublist completo de 0 a zize
{
    LinkedList* cloneArray = NULL;

    cloneArray=ll_subList(this,0,ll_len(this));


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)//
{
   /* int returnAux =-1;
    void* swap;
    Node* nodoSigiente;
    Node* nodoAcomparar;
    int flag=-1;
    int i;

    if(this!=NULL && (order==1 || order==0) && ll_len(this)>2 && (*pFunc)!=NULL)
    {
        while(flag==1)
        {

            for(i=0;i<ll_len(this);i++)
            {
                nodoAcomparar=ll_get(this,i);
                nodoSigiente=ll_get(this,i+1);
                if(order==1 && pFunc(nodoAcomparar,nodoSigiente)>0)
                {


                    swap=nodoSigiente;
                    ll_set(this,i+1,nodoAcomparar);
                    ll_set(this,i,swap);
                    flag=0;

                }

                if(order==0 && pFunc(nodoAcomparar,nodoSigiente)<0)
                {
                    swap=nodoSigiente;
                    ll_set(this,i+1,nodoAcomparar);
                    ll_set(this ,i,swap);
                    flag=0;
                }


            }

        }
        returnAux=0;

    }

    return returnAux;
    */
int returnAux =-1;
    int i;
    int flagNoEstaOrdenado=1;
    int lenLista=ll_len(this);
    Node *pNodeA;
    Node *pNodeB;
    void *pAuxElement;
    if (this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
        if(lenLista>=2)
        {
            while(flagNoEstaOrdenado==1)
            {
                flagNoEstaOrdenado=0;
                pNodeA=this->pFirstNode->pNextNode;
                pNodeB=this->pFirstNode;
                for(i=1;i<lenLista;i++)
                {
                    if (order==0 && pFunc(pNodeA->pElement,pNodeB->pElement)>0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    if(order==1 && pFunc(pNodeA->pElement,pNodeB->pElement)<0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    pNodeA=pNodeA->pNextNode;
                    pNodeB=pNodeB->pNextNode;
                }
            }
            returnAux=0;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;

}

//if(function get i get j==1)
//1 true 0falso
/*
map recorre la lista le pasan elemento a elemento a la funcion q le pasan x parametreo
reduce lo mismo pero si la funcion retorna true se borra
filter crear lista nueva recorro vieja con la funcion parametro si da true add a la lista nueva*/

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int ret=-1;
    int i;
    void* element;

    if(this!=NULL && (*pFunc)!=NULL)
    {
        for(i=0;i<=ll_len(this);i++)
        {

            element=ll_get(this,i);
            if(pFunc(element)!=-1)
            {
                ret=0;
            }else
            {
               return=1;
            }

        }

    }

    return ret;
}



int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
    int ret=-1;
    int i;
    Node* element;

    if(this!=NULL && (*pFunc)!=NULL)
    {
        for(i=0;i<=ll_len(this);i++)
        {

            element=ll_get(this,i);
            if(pFunc(element)==1)
            {
                ll_remove(this,i);
                ret=0;
            }else
            {
               ret=1;
            }

        }

    }

    return ret;
}

int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this!=NULL && (*pFunc()!=NULL))
    {
        cloneArray=ll_newLinkedList();

    }


}




