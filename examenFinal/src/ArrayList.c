#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void** pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = (void**) malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }
    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if((this != NULL) && (pElement != NULL))
    {
        if(this->reservedSize == this->size)
        {
            if(!resizeUp(this))
            {
                this->pElements[this->size] = pElement;
                this->size++;
                returnAux = 0;
            }
        }
        else
        {
            this->pElements[this->size] = pElement;
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        free(this);
        this = NULL;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Return the length of the ArrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if((this != NULL) && (index > -1) && (index < this->size) && (this->pElements[index] != NULL))
    {
        returnAux = this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if((this != NULL) && (pElement != NULL))
    {
        returnAux = 0;
        int i;
        for(i = 0; i < this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if((this != NULL) && (index > -1) && (index < this->size) && (pElement != NULL))
    {
        this->pElements[index] = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this, int index)
{
    int returnAux = -1;

    if((this != NULL) && (index > -1) && (index < this->size))
    {
        contract(this, index);
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        int i = 1;
        for(i = 0; this->size > 0; i++)
        {
            this->pElements[i] = NULL;
            this->size--;
        }
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    if(this != NULL)
    {
        returnAux = al_newArrayList();
        int i;
        for(i = 0; i < this->size; i++)
        {
            al_add(returnAux, this->pElements[i]);
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    /*si el indice es igual al size se utiliza add()*/

    if((this != NULL) && (pElement != NULL) && (index >= 0) && (index <= this->size))
    {
        if(index == this->size)
        {
            if(!al_add(this, pElement))
            {
                returnAux = 0;
            }
        }
        else
        {
            expand(this, index);
            al_set(this, index, pElement);
            returnAux = 0;
        }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if((this != NULL) && (pElement != NULL))
    {
        int i;
        for(i = 0; i < this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;
        if(this->size)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    /*Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
    de la lista. Verificando que el puntero pList sea distinto de NULL y que index sea positivo e
    inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
    retorna el elemento.*/
    void* returnAux = NULL;

    if((this != NULL) && (index >= 0) && (index < this->size))
    {
        returnAux = al_get(this, index);
        if(returnAux != NULL)
        {
            al_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    ArrayList* subThis;

    if((this != NULL))
    {
        if((from >= 0) && (to <= this->size) && (to >= 0) && (to >= from))
        {
            subThis = al_newArrayList();
            if(subThis != NULL)
            {
                int i;
                for(i = from; i < to; i++)
                {
                    if(!al_add(subThis, this->pElements[i]))
                    {
                        returnAux = subThis;
                    }
                    else
                    {
                        returnAux = NULL;
                    }
                }
            }
        }
    }

    return returnAux;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;

    if((this != NULL) && (this2 != NULL))
    {
        if(this->size == this2->size)
        {
            int i;
            for(i = 0; i < this->size; i++)
            {
                returnAux = al_contains(this, this2->pElements[i]);
            }
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;

    if((this != NULL) && (pFunc != NULL))
    {
        if(order == 1)
        {
            //UP
            int i;
            for(i = 0; i < (this->size - 1); i++)
            {
                if(pFunc(this->pElements[i], this->pElements[i+1]) == 1)
                {
                    void* pElementAux = al_get(this, i+1);
                    al_set(this, i+1, this->pElements[i]);
                    al_set(this, i, pElementAux);
                    i = -1;
                }
            }

            returnAux = 0;
        }
        else
        {
            if(!order)
            {
                //DOWN
                int i;
                for(i = 0; i < (this->size - 1); i++)
                {
                    if(pFunc(this->pElements[i], this->pElements[i+1]) == -1)
                    {
                        void* pElementAux = al_get(this, i);
                        al_set(this, i, this->pElements[i+1]);
                        al_set(this, i+1, pElementAux);
                        i = -1;
                    }
                }

                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** lista;

    if(this != NULL)
    {
        lista = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize + AL_INCREMENT));
        if(lista != NULL)
        {
            this->pElements = lista;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    if((this != NULL) && (index >= 0) && (index < this->size))
    {
        this->size++;
        if(this->reservedSize == this->size)
        {
            if(!resizeUp(this))
            {
                int i;
                for(i = (this->size - 1); i > index; i--)
                {
                    if(al_set(this, i, this->pElements[i-1]) != -1)
                    {
                        returnAux = 0;
                    }
                    else
                    {
                        returnAux = -1;
                    }
                }
            }
        }
        else
        {
            int i;
            for(i = (this->size - 1); i > index; i--)
            {
                if(al_set(this, i, this->pElements[i-1]) != -1)
                {
                    returnAux = 0;
                }
                else
                {
                    returnAux = -1;
                }
            }
        }
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    if((this != NULL) && (index >= 0) && (index < this->size))
    {
        int i;
        for(i = index; i < (this->size - 1); i++)
        {
            if(al_set(this, i, this->pElements[i+1]) != -1)
            {
                returnAux = 0;
            }
            else
            {
                returnAux = -1;
            }
        }
        this->size--;
    }

    return returnAux;
}
