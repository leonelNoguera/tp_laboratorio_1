/*main.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
/*Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo
Ejemplo:
*
* *
* * *
* * *
* * *
* * *
<18 19-35 >35
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
19 y 35, y 5 personas con edades mayores a 35.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "funciones.c"
#include "generadorDeDatos.h"
#include "generadorDeDatos.c"

int cantidadDePersonas = 20;
int i;

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona personas[cantidadDePersonas];

    for(i=0; i<cantidadDePersonas; i++)
    {
        personas[i].estado = 0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                /*agregarPersona(personas, "Pedro", generarEdadAleatoria(10, 40), 40139077, cantidadDePersonas);
                agregarPersona(personas, "Julio", generarEdadAleatoria(10, 40), 40139077, cantidadDePersonas);
                agregarPersona(personas, "Ricardo", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Colvy", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Gustavo", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Tomas", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Denis", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Raul", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Omar", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Omar", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Guillermo", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Cecilia", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Monica", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Pamela", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Rebeca", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Jesica", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Sabrina", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Nancy", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Jimena", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);
                agregarPersona(personas, "Ana", generarEdadAleatoria(10, 40), generarDniAleatorio(), cantidadDePersonas);*/
                agregarPersona(personas, cantidadDePersonas);
                break;
            case 2:
                for(i=0; i<10; i++)
                {
                    borrarPersonaPorDni(personas, cantidadDePersonas);
                }
                break;
            case 3:
                mostrarListaOrdenadaPorNombre(personas, cantidadDePersonas);
                break;
            case 4:
                mostrarGraficoDeBarras(personas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
