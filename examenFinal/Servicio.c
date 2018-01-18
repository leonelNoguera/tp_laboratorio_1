#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/Servicio.h"

int compareServicio(void* pServicioA,void* pServicioB)
{
    char codigoDeProductoA[51];
    getApellido(pServicioA, codigoDeProductoA);

    char codigoDeProductoB[51];
    getApellido(pServicioB, codigoDeProductoB);

    if(strcmp(codigoDeProductoA, codigoDeProductoB) > 0)
    {
        return 1;
    }
    if(strcmp(codigoDeProductoA, codigoDeProductoB) < 0)
    {
        return -1;
    }
    return 0;
}

void printServicio(Servicio* p)
{
    if(p != NULL)
    {
        printf("id: %d - id del cliente: %d - codigo de producto: %s - fecha de ingreso: %s - costo de reparacion: %f\n", p->id, p->id_cliente, p->codigoDeProducto, p->fechaDeIngreso, p->costoDeReparacion);
    }
    else
    {
        printf("    Error: p = NULL\n");
    }
}

/*Servicio* newServicioParam(int id, int id_cliente, char codigoDeProducto[], char fechaDeIngreso[], float costoDeReparacion, int estado)
{
    Servicio* returnAux = NULL;
    Servicio* pServicio = malloc(sizeof(Servicio));

    if(pServicio != NULL)
    {
        setIdServicio(pServicio, id);
        setId_cliente(pServicio, id_cliente);
        setCodigoDeProducto(pServicio, codigoDeProducto);
        setFechaDeIngreso(pServicio, fechaDeIngreso);
        setCostoDeReparacion(pServicio, costoDeReparacion);

        returnAux = pServicio;
    }

    return returnAux;
}*/

Servicio* newServicio()
{
    Servicio* returnAux = NULL;
    Servicio* pServicio = malloc(sizeof(Servicio));

    if(pServicio != NULL)
    {
        setEstado(servicio, 1); // El estado es 1 cuando el servicio está pendiente.
        returnAux = pServicio;
    }

    return returnAux;
}

void setIdServicio(Servicio* servicio, int id)
{
    servicio->id = id;
}
void setId_cliente(Servicio* servicio, int id_cliente)
{
    servicio->id_cliente = id_cliente;
}
void setCodigoDeProducto(Servicio* servicio, char codigoDeProducto[])
{
    strcpy(servicio->codigoDeProducto, codigoDeProducto);
}
void setFechaDeIngreso(Servicio* servicio, char fechaDeIngreso[])
{
    strcpy(servicio->fechaDeIngreso, fechaDeIngreso);
}
void setCostoDeReparacion(Servicio* servicio, float costoDeReparacion)
{
    servicio->costoDeReparacion = costoDeReparacion;
}
void setEstado(Servicio* servicio, int estado)
{
    if(estado == 1 || estado == 0)
    {
        servicio->estado = estado;
    }
    else
    {
        printf("    Error: El estado %d no es valido, debe ser 0 o 1.\n");
    }
}

int getIdServicio(Servicio* servicio)
{
    return servicio->id;
}
int getId_cliente(Servicio* servicio)
{
    return servicio->id_cliente;
}
void getCodigoDeProducto(Servicio* servicio, char codigoDeProducto[])
{
    strcpy(codigoDeProducto, servicio->codigoDeProducto);
}
void getFechaDeIngreso(Servicio* servicio, char fechaDeIngreso[])
{
    strcpy(fechaDeIngreso, servicio->fechaDeIngreso);
}
float getCostoDeReparacion(Servicio* servicio)
{
    return servicio->costoDeReparacion;
}
int getEstado(Servicio* servicio)
{
    return servicio->estado;
}