#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Mostrar peliculas del archivo binario\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula();
                break;
            case 2:
                borrarPelicula();
                break;
            case 3:
                modificarPelicula();
                break;
            case 4:
                generarWeb();
                break;
            case 5:
                mostrarPeliculas();
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
