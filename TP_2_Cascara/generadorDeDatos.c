/*generadorDeDatos.c
Autor: Marcelo Leonel Noguera
15/09/2017*/
#include "generadorDeDatos.h"
#include <stdlib.h>
int generarDniAleatorio()
{
	int dni;
	do
	{
		dni = rand()/(RAND_MAX/100000000);
	}
	while (!dni);

	return dni;
}
int generarEdadAleatoria(int edadInicio, int edadFin)
{
	int edad;
	do
	{
		edad = rand()/(RAND_MAX/100);
	}
	while ((edad < edadInicio) || (edad > edadFin));

	return edad;
}

