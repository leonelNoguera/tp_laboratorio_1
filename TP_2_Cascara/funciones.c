/*funciones.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
#include "funciones.h"
void agregarPersona(EPersona personas[], int cantidadDePersonas)
{
    char nombre[50];

    printf("Ingrese el nombre de la persona: ");
    fflush(stdin);
    scanf("%s",&nombre);

    int edad = ingresarEdadDeLaPersona();
    int dni = ingresarDniDeLaPersona();
    if(estadoDeLaEstructuraPersona(personas, cantidadDePersonas) != 2)
    {
        if(obtenerEspacioDisponible(personas, cantidadDePersonas) != -1)
        {
            int indice;
            if(buscarPersonaPorDni(personas, dni, cantidadDePersonas) == -1)
            {
                indice = obtenerEspacioDisponible(personas, cantidadDePersonas);
                strcpy(personas[indice].nombre, nombre);
                personas[indice].edad = edad;
                personas[indice].dni = dni;
                personas[indice].estado = 1;
            }
            else
            {
                printf("    Error: La persona ya est%c registrada con ese DNI\n", 160);
            }
        }
    }
    else
    {
        if(estadoDeLaEstructuraPersona(personas, cantidadDePersonas) == 2)
        {
            printf("    Error: No hay espacios disponibles.\n");
        }
        else
        {
            strcpy(personas[0].nombre, nombre);
            personas[0].edad = edad;
            personas[0].dni = dni;
            personas[0].estado = 1;
        }
    }
}

int obtenerEspacioDisponible(EPersona personas[], int cantidadDePersonas)
{
    int indiceDelEspacioDisponible = 0;
    if(estadoDeLaEstructuraPersona(personas, cantidadDePersonas))
    {
        int i;
        for(i=0; i<cantidadDePersonas; i++)
        {
            if(personas[i].estado == 0)
            {
                indiceDelEspacioDisponible = i;
                break;
            }
            else
            {
                indiceDelEspacioDisponible = -1;
            }
        }
    }
    return indiceDelEspacioDisponible;
}

int buscarPersonaPorDni(EPersona personas[], int dni, int cantidadDePersonas)
{
    int resultado = -1;
    int i;
    for(i=0; i<cantidadDePersonas; i++)
    {
        if(personas[i].dni == dni)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}
void borrarPersonaPorDni(EPersona personas[], int cantidadDePersonas)
{
    int dni = ingresarDniDeLaPersona();
    if(buscarPersonaPorDni(personas, dni, cantidadDePersonas) != -1)
    {
        int indice = buscarPersonaPorDni(personas, dni, cantidadDePersonas);
        if(personas[indice].estado != 0)
        {
            personas[indice].estado = 0;
        }
        else
        {
            printf("    Error: La persona se elimin%c previamente.\n", 162);
        }
    }
    else
    {
        printf("    Error: No se encontr%c la persona.\n", 162);
    }
    printf("\n");
}

void mostrarListaOrdenadaPorNombre(EPersona personas[], int cantidadDePersonas)
{
    if(estadoDeLaEstructuraPersona(personas, cantidadDePersonas))
    {
        EPersona personasOrdenadasPorNombres[40] = {};
        EPersona personasAux = {};

        int i;
        int j;

        for(i=0; i<cantidadDePersonas; i++)
        {
            if(personas[i].estado)
            {
                personasOrdenadasPorNombres[i] = personas[i];
            }
            else
            {
                personasOrdenadasPorNombres[i].estado = 0;
            }
        }


        for(j=0; j<cantidadDePersonas; j++)
        {
            for(i=j; i<cantidadDePersonas; i++)
            {
                if(personas[i].estado)
                {
                    if(strcmp(personasOrdenadasPorNombres[j].nombre, personasOrdenadasPorNombres[i].nombre) > 0)
                    {
                        personasAux = personasOrdenadasPorNombres[j];
                        personasOrdenadasPorNombres[j] = personasOrdenadasPorNombres[i];
                        personasOrdenadasPorNombres[i] = personasAux;
                    }
                }
            }
        }

        printf(" | Nombre --- DNI --- Edad |\n");
        for(i=0; i<cantidadDePersonas; i++)
        {
            if(personas[i].estado)
            {
                printf(" | %s - %d - %d\n", personasOrdenadasPorNombres[i].nombre, personasOrdenadasPorNombres[i].dni, personasOrdenadasPorNombres[i].edad);
            }
        }
    }
    else
    {
        printf("    Error: La estructura de datos est%c vac%ca.\n", 160, 161);
    }
    printf("\n");
}

void mostrarGraficoDeBarras(EPersona personas[], int cantidadDePersonas)
{
    if(estadoDeLaEstructuraPersona(personas, cantidadDePersonas))
    {
        int cantidadEnIntervaloUno = 0;
        int cantidadEnIntervaloDos = 0;
        int cantidadEnIntervaloTres = 0;
        int valorDeIntervaloMayor = 0;

        int i;

        for(i=0; i<cantidadDePersonas; i++)
        {
            if(personas[i].estado)
            {
                if(personas[i].edad <= 18)
                {
                    cantidadEnIntervaloUno++;
                }
                if((personas[i].edad > 18) && (personas[i].edad <= 35))
                {
                    cantidadEnIntervaloDos++;
                }
                if(personas[i].edad > 35)
                {
                    cantidadEnIntervaloTres++;
                }
            }
        }

        if(cantidadEnIntervaloUno > cantidadEnIntervaloDos)
        {
            if(cantidadEnIntervaloUno > cantidadEnIntervaloTres)
            {
                valorDeIntervaloMayor = cantidadEnIntervaloUno;
            }
        }

        if(cantidadEnIntervaloDos > cantidadEnIntervaloUno)
        {
            if(cantidadEnIntervaloDos > cantidadEnIntervaloTres)
            {
                valorDeIntervaloMayor = cantidadEnIntervaloDos;
            }
        }

        if(cantidadEnIntervaloTres > cantidadEnIntervaloUno)
        {
            if(cantidadEnIntervaloTres > cantidadEnIntervaloDos)
            {
                valorDeIntervaloMayor = cantidadEnIntervaloTres;
            }
        }

        if((cantidadEnIntervaloUno == cantidadEnIntervaloDos) && (cantidadEnIntervaloUno == cantidadEnIntervaloTres))
        {
            valorDeIntervaloMayor = cantidadEnIntervaloUno;
        }

        int matrizIntervalos[3][valorDeIntervaloMayor];

        for(i=valorDeIntervaloMayor-1; i>-1; i--)
        {
            matrizIntervalos[0][i] = cantidadEnIntervaloUno--;
            matrizIntervalos[1][i] = cantidadEnIntervaloDos--;
            matrizIntervalos[2][i] = cantidadEnIntervaloTres--;
        }

        for(i=0; i<valorDeIntervaloMayor; i++)
        {
            if(matrizIntervalos[0][i] > 0)
            {
                printf(" *");
            }
            else
            {
                printf("  ");
            }
            if(matrizIntervalos[1][i] > 0)
            {
                printf("    *");
            }
            else
            {
                printf("     ");
            }
            if(matrizIntervalos[2][i] > 0)
            {
                printf("    *\n");
            }
            else
            {
                printf("     \n");
            }
        }
        printf("-------------\n<=18 19-35 >35\n");
    }
    else
    {
        printf("    Error: La estructura de datos est%c vac%ca.\n", 160, 161);
    }
    printf("\n");
}

int estadoDeLaEstructuraPersona(EPersona personas[], int cantidadDePersonas)
{
    // 0 -- vacio , 1 -- alguno seteado, 2 -- lleno
    int estadoDeLaEstructura = 0;
    int contadorElementosSeteados = 0;
    int i;
    for(i=0; i<cantidadDePersonas; i++)
    {
        if(personas[i].estado)
        {
            estadoDeLaEstructura = 1;
            contadorElementosSeteados++;
        }
        if(contadorElementosSeteados == cantidadDePersonas)
        {
            estadoDeLaEstructura = 2;
        }
    }
    return estadoDeLaEstructura;
}

int ingresarEdadDeLaPersona()
{
    int edad;
    char edadIngresada[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la edad de la persona: ");
        fflush(stdin);
        scanf("%s",&edadIngresada);
        edad = atoi(edadIngresada);

        if(!(edad <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: N%cmero no v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    return edad;
}

int ingresarDniDeLaPersona()
{
    int dni;
    char dniIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el DNI de la persona: ");
        fflush(stdin);
        scanf("%s",&dniIngresado);

        dni = atoi(dniIngresado);

        if(!(dni <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: No es un n%cmero v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    printf("\n");
    return dni;
}
