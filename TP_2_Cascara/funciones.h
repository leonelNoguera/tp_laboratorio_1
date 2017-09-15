/*funciones.h
Autor: Marcelo Leonel Noguera
08/09/2017*/
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
void agregarPersona(EPersona[], char[], int, int);
void borrarPersonaPorNombre(EPersona[], char[]);
void borrarPersonaPorDni(EPersona[], int);
int obtenerEspacioDisponible(EPersona[]);
int buscarPersonaPorNombre(EPersona[], char[]);
int buscarPersonaPorDni(EPersona[], int);
void mostrarListaOrdenadaPorNombre(EPersona[]);
void mostrarGraficoDeBarras(EPersona[]);
int estadoDeLaEstructuraPersona(EPersona[]);

#endif // FUNCIONES_H_INCLUDED
