#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Registro.h"

void printRegistro(Registro* p)
{
    if(p != NULL)
    {
        printf("id: %d - id de empleado: %d - codigo de trabajo: %d - cantidad de horas: %d - precio unitario: %f\n", p->id, p->id_empleado, p->codigoDeTrabajo, p->cantidadDeHoras, p->precioUnitario);
    }
    else
    {
        printf("    Error: p = NULL\n");
    }
}

/** \brief Set this Registro the values recived as parameters
 *
 * \param id int
 *
 */
Registro* newRegistroParam(int id, int id_empleado, int codigoDeTrabajo, int cantidadDeHoras, float precioUnitario)
{
    Registro* returnAux = NULL;
    Registro* pRegistro = malloc(sizeof(Registro));

    if(pRegistro != NULL)
    {
        pRegistro->id = id;
        pRegistro->id_empleado = id_empleado;
        pRegistro->codigoDeTrabajo = codigoDeTrabajo;
        pRegistro->cantidadDeHoras = cantidadDeHoras;
        pRegistro->precioUnitario = precioUnitario;

        returnAux = pRegistro;
    }

    return returnAux;
}

Registro* newRegistro()
{
    Registro* returnAux = NULL;
    Registro* pRegistro = malloc(sizeof(Registro));

    if(pRegistro != NULL)
    {
        returnAux = pRegistro;
    }

    return returnAux;
}

void setIdRegistro(Registro* registro, int id)
{
    registro->id = id;
}
void setId_empleado(Registro* registro, int id_empleado)
{
    registro->id_empleado = id_empleado;
}
void setCodigoDeTrabajo(Registro* registro, int codigoDeTrabajo)
{
    registro->codigoDeTrabajo = codigoDeTrabajo;
}
void setCantidadDeHoras(Registro* registro, int cantidadDeHoras)
{
    registro->cantidadDeHoras = cantidadDeHoras;
}
void setPrecioUnitario(Registro* registro, float precioUnitario)
{
    registro->precioUnitario = precioUnitario;
}

int getIdRegistro(Registro* registro)
{
    return registro->id;
}
int getId_empleado(Registro* registro)
{
    return registro->id_empleado;
}
int getCodigoDeTrabajo(Registro* registro)
{
    return registro->codigoDeTrabajo;
}
int getCantidadDeHoras(Registro* registro)
{
    return registro->cantidadDeHoras;
}
float getPrecioUnitario(Registro* registro)
{
    return registro->precioUnitario;
}
