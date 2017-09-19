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
void agregarPersona(EPersona[], int);
void borrarPersonaPorDni(EPersona[], int);
int obtenerEspacioDisponible(EPersona[]);
int buscarPersonaPorDni(EPersona[], int, int);
void mostrarListaOrdenadaPorNombre(EPersona[], int);
void mostrarGraficoDeBarras(EPersona[]);
int estadoDeLaEstructuraPersona(EPersona[]);
int ingresarEdadDeLaPersona();
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int ingresarDniDeLaPersona();

#endif // FUNCIONES_H_INCLUDED
