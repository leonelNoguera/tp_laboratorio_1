#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Empleado.h"

int compareEmpleado(void* pEmpleadoA,void* pEmpleadoB)
{
    if(((Empleado*)pEmpleadoA)->dni > ((Empleado*)pEmpleadoB)->dni)
    {
        return 1;
    }
    if(((Empleado*)pEmpleadoA)->dni < ((Empleado*)pEmpleadoB)->dni)
    {
        return -1;
    }
    return 0;
}

void printEmpleado(Empleado* p)
{
    if(p != NULL)
    {
        printf("ID: %d - DNI:%d\n",p->id,p->dni);
    }
    else
    {
        printf("    Error: p = NULL\n");
    }
}

Empleado* newEmpleadoParam(int id, char nombre[], char apellido[], int dni)
{
    Empleado* returnAux = NULL;
    Empleado* pEmpleado = malloc(sizeof(Empleado));

    if(pEmpleado != NULL)
    {
        setIdEmpleado(pEmpleado, id);
        setNombre(pEmpleado, nombre);
        setApellido(pEmpleado, apellido);
        setDni(pEmpleado, dni);
        returnAux = pEmpleado;
    }

    return returnAux;
}

Empleado* newEmpleado()
{
    Empleado* returnAux = NULL;
    Empleado* pEmpleado = malloc(sizeof(Empleado));

    if(pEmpleado != NULL)
    {
        returnAux = pEmpleado;
    }

    return returnAux;
}


void setIdEmpleado(Empleado* empleado, int id)
{
    empleado->id = id;
}

void setNombre(Empleado* empleado, char nombre[])
{
    strcpy(empleado->nombre, nombre);
}

void setApellido(Empleado* empleado, char apellido[])
{
    strcpy(empleado->apellido, apellido);
}

void setDni(Empleado* empleado, int dni)
{
    empleado->dni = dni;
}


int getIdEmpleado(Empleado* empleado)
{
    return empleado->id;
}

void getNombre(Empleado* empleado, char nombre[])
{
    strcpy(nombre, empleado->nombre);
}

void getApellido(Empleado* empleado, char apellido[])
{
    strcpy(apellido, empleado->apellido);
}

int getDni(Empleado* empleado)
{
    return empleado->dni;
}
