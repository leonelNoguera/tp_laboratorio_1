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
 * Pide el nombre de la persona, su edad y su DNI para guardar la información.
 * @param Recibe el vector de la estructura.
 * @param Recibe la longitud del vector.
 */
void agregarPersona(EPersona[], int);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro. LLama a la función "ingresarDniDeLaPersona" para obtener el DNI.
 * @param Recibe el vector de la estructura.
 * @param Recibe la longitud del vector.
 */
void borrarPersonaPorDni(EPersona[], int);
/**
 * Obtiene el índice del primer espacio libre del vector EPersona.
 * @param Recibe el vector de la estructura.
 * @return Retorna el índice del primer espacio libre del vector, retorna -1 si no hay espacio disponible.
 */
int obtenerEspacioDisponible(EPersona[]);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param Recibe el vector de la estructura.
 * @param Recibe el número de DNI que se desea buscar.
 * @param Recibe la longitud del vector.
 * @return Retorna el indice en donde se encuentra el elemento que coincide con el DNI, retorna -1 si no fue hallado.
 */
int buscarPersonaPorDni(EPersona[], int, int);
void mostrarListaOrdenadaPorNombre(EPersona[], int);
void mostrarGraficoDeBarras(EPersona[]);
int estadoDeLaEstructuraPersona(EPersona[]);
/**
 * Pide que se ingrese la edad y la verifica. No sale de la función hasta que se haya ingresado un número válido.
 * @return Retorna el número validado.
 */
int ingresarEdadDeLaPersona();
/**
 * Pide que se ingrese el DNI y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * @return Retorna el número validado.
 */
int ingresarDniDeLaPersona();

#endif // FUNCIONES_H_INCLUDED
