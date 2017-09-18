#include "funciones.h"
/*funciones.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
void agregarPersona(EPersona personas[], int cantidadDePersonas)
{
    char nombre[50];

    printf("Ingrese el nombre de la persona: ");
    fflush(stdin);
    scanf("%s",&nombre);

    int edad = ingresarEdadDeLaPersona();
    int dni = ingresarDniDeLaPersona();
    if(estadoDeLaEstructuraPersona(personas) != 2)
    {
        if(obtenerEspacioDisponible(personas) != -1)
        {
            int indice;
            if(buscarPersonaPorDni(personas, dni, cantidadDePersonas) == -1)
            {
                indice = obtenerEspacioDisponible(personas);
                strcpy(personas[indice].nombre, nombre);
                personas[indice].edad = edad;
                personas[indice].dni = dni;
                personas[indice].estado = 1;
            }
            else
            {
                printf("    Error: La persona ya está registrada con ese DNI\n");
            }
        }
    }
    else
    {
        if(estadoDeLaEstructuraPersona(personas) == 2)
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

int obtenerEspacioDisponible(EPersona personas[])
{
    int indiceDelEspacioDisponible;
    if(estadoDeLaEstructuraPersona(personas))
    {
        int i;
        for(i=0; i<20; i++)
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
    else
    {
       indiceDelEspacioDisponible = 0;
    }
    return indiceDelEspacioDisponible;
}

int buscarPersonaPorDni(EPersona personas[], int dni, int cantidadDePersonas)
{
    int resultado = -1;
    int i;
    for(i=0; i<20; i++)
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
            printf("    Error: La persona se eliminó previamente.\n");
        }
    }
    else
    {
        printf("    Error: No se encontró la persona.\n");
    }
}

void mostrarListaOrdenadaPorNombre(EPersona personas[], int cantidadDePersonas)
{
    if(estadoDeLaEstructuraPersona(personas))
    {
        EPersona personasOrdenadasPorNombres[20] = {};
        EPersona personasAux = {};

        int i;
        int j;

        for(i=0; i<20; i++)
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


        for(j=0; j<20; j++)
        {
            for(i=j; i<20; i++)
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
        for(i=0; i<20; i++)
        {
            if(personas[i].estado)
            {
                printf(" | %s - %d - %d\n", personasOrdenadasPorNombres[i].nombre, personasOrdenadasPorNombres[i].dni, personasOrdenadasPorNombres[i].edad);
            }
        }
    }
    else
    {
        printf("    Error: La estructura de datos está vacía.\n");
    }
}

void mostrarGraficoDeBarras(EPersona personas[])
{
    if(estadoDeLaEstructuraPersona(personas))
    {
        int cantidadEnIntervaloUno = 0;
        int cantidadEnIntervaloDos = 0;
        int cantidadEnIntervaloTres = 0;
        int valorDeIntervaloMayor = 0;

        int i;

        for(i=0; i<20; i++)
        {
            if(personas[i].estado)
            {
                if(personas[i].edad < 18)
                {
                    cantidadEnIntervaloUno++;
                }
                if((personas[i].edad > 18) && (personas[i].edad < 36))
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
        printf("-------------\n<18 19-35 >35\n");
    }
    else
    {
        printf("    Error: La estructura de datos está vacía.\n");
    }
}

int estadoDeLaEstructuraPersona(EPersona personas[])
{
    // 0 -- vacio , 1 -- alguno seteado, 2 -- lleno
    int estadoDeLaEstructura = 0;
    int contadorElementosSeteados = 0;
    int i;
    for(i=0; i<20; i++)
    {
        if(personas[i].estado)
        {
            estadoDeLaEstructura = 1;
            contadorElementosSeteados++;
        }
        if(contadorElementosSeteados == 20)
        {
            estadoDeLaEstructura = 2;
        }
    }
    return estadoDeLaEstructura;
}

int ingresarEdadDeLaPersona()
{
    int edad;
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la edad de la persona: ");
        fflush(stdin);
        scanf("%d",&edad);

        if(!(edad < 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: Número no válido.\n");
            flag = 0;
        }
    }
    return edad;
}

int ingresarDniDeLaPersona()
{
    int dni;
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el DNI de la persona: ");
        fflush(stdin);
        scanf("%d",&dni);

        if(!(dni <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: Número no válido.\n");
            flag = 0;
        }
    }
    return dni;
}