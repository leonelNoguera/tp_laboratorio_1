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

struct persona
    {
        char nombre[50];
        int edad;
        int estado;
        int dni;
    };
struct persona personas[20] = {};
int i;

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona personas[20] = {};

    for(i=0; i<20; i++)
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
                agregarPersona(personas, "Pedro", 17, 40343654);
                agregarPersona(personas, "Juio", 18, 40343654);
                agregarPersona(personas, "Ricardo", 14, 40343654);
                agregarPersona(personas, "Colvy", 12, 40343654);
                agregarPersona(personas, "Gustavo", 16, 40343654);

                agregarPersona(personas, "Tomas", 19, 40343654);
                agregarPersona(personas, "Denis", 20, 40343654);
                agregarPersona(personas, "Raul", 28, 40343654);
                agregarPersona(personas, "Mateo", 35, 40343654);
                agregarPersona(personas, "Omar", 22, 40343654);
                agregarPersona(personas, "Guillermo", 34, 40343654);
                agregarPersona(personas, "Cecilia", 20, 40343654);

                agregarPersona(personas, "Monica", 40, 40343654);
                agregarPersona(personas, "Pamela", 42, 40343654);
                agregarPersona(personas, "Rebeca", 44, 40343654);
                agregarPersona(personas, "Jesica", 70, 40343654);
                agregarPersona(personas, "Sabrina", 36, 40343654);
                agregarPersona(personas, "Nancy", 37, 40343654);
                agregarPersona(personas, "Jimena", 38, 40343654);
                agregarPersona(personas, "Ana", 50, 40343654);
                break;
            case 2:
                borrarPersonaPorNombre(personas, "Mateo");
                //borrarPersonaPorDni(personas, n);
                break;
            case 3:
                mostrarListaOrdenadaPorNombre(personas);
                break;
            case 4:
                mostrarGraficoDeBarras(personas);
                break;
            case 5:
                seguir = 'n';
                break;
            //mostrarListaOrdenadaPorNombre(personas);
        }
    }

    return 0;
}



