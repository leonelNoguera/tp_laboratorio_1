/*funciones.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
#include "funciones.h"

void agregarPelicula()
{
    char titulo[40];
    char genero[20];
    char descripcion[200];
    char linkImagen[200];

    pedirTitulo(titulo);

    if(buscarPeliculaPorTitulo(titulo) == -1)
    {
        pedirGenero(genero);
        pedirDescripcion(descripcion);
        pedirLink(linkImagen);

        int puntaje = pedirPuntaje();
        int duracion = pedirDuracion();

        guardarPeliculaEnArchivo(titulo, genero, descripcion, linkImagen, puntaje, duracion);
    }
    else
    {
        printf("    Error: Ya hay una pelicula con ese titulo\n");
    }
}

void borrarPelicula()
{
    FILE * pArchivo;
    FILE * pArchivoAux;
    EMovie pelicula;
    int contador = 0;
    int encontro = 0;

    pArchivo = fopen("peliculas.bin","rb");
    pArchivoAux = fopen("peliculasAux.bin","wb");

    if((pArchivo != NULL) || (pArchivoAux != NULL))
    {
        if(mostrarPeliculas())
        {
            int id = ingresarIdPelicula();
            while(fread(&pelicula,sizeof(EMovie),1,pArchivo))
            {
                if(contador == id)
                {
                    encontro = 1;
                }
                else
                {
                    fwrite(&pelicula,sizeof(EMovie),1,pArchivoAux);
                }
                contador++;
            }
            if(!encontro)
            {
                printf("    Error: No se encuentra ese ID.\n");
            }
            else
            {
                printf("Eliminado.\n");
            }
            fclose(pArchivo);
            fclose(pArchivoAux);
            if((pArchivo != NULL) || (pArchivoAux != NULL))
            {
                pArchivo = fopen("peliculas.bin","wb");
                pArchivoAux = fopen("peliculasAux.bin","rb");
                while(fread(&pelicula,sizeof(EMovie),1,pArchivoAux))
                {
                    fwrite(&pelicula,sizeof(EMovie),1,pArchivo);
                }
            }
            else
            {
                printf("    Error: No se pudo abrir el archivo.\n");
            }
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
    fclose(pArchivoAux);
}

void modificarPelicula()
{
    FILE * pArchivo;
    FILE * pArchivoAux;
    EMovie pelicula;
    int contador = 0;
    int encontro = 0;

    char titulo[40];
    char genero[20];
    char descripcion[200];
    char linkImagen[200];

    pArchivo = fopen("peliculas.bin","rb");
    pArchivoAux = fopen("peliculasAux.bin","wb");

    if((pArchivo != NULL) || (pArchivoAux != NULL))
    {
        if(mostrarPeliculas())
        {
            int id = ingresarIdPelicula();
            while(fread(&pelicula,sizeof(EMovie),1,pArchivo))
            {
                if(contador == id)
                {
                    pedirTitulo(titulo);

                    if((buscarPeliculaPorTitulo(titulo) == -1) || (buscarPeliculaPorTitulo(titulo) == id))
                    {
                        pedirGenero(genero);
                        pedirDescripcion(descripcion);
                        pedirLink(linkImagen);
                        int puntaje = pedirPuntaje();
                        int duracion = pedirDuracion();

                        strcpy(pelicula.titulo, titulo);
                        strcpy(pelicula.genero, genero);
                        strcpy(pelicula.descripcion, descripcion);
                        strcpy(pelicula.linkImagen, linkImagen);
                        pelicula.puntaje = puntaje;
                        pelicula.duracion = duracion;

                        fwrite(&pelicula,sizeof(EMovie),1,pArchivoAux);

                        printf("Modificado.\n");
                    }
                    else
                    {
                        printf("    Error: Ya hay una pelicula con ese titulo\n");
                    }
                    encontro = 1;
                }
                else
                {
                    fwrite(&pelicula,sizeof(EMovie),1,pArchivoAux);
                }
                contador++;
            }
            if(!encontro)
            {
                printf("    Error: No se encuentra ese ID.\n");
            }
            fclose(pArchivo);
            fclose(pArchivoAux);

            pArchivo = fopen("peliculas.bin","wb");
            pArchivoAux = fopen("peliculasAux.bin","rb");

            if((pArchivo != NULL) || (pArchivoAux != NULL))
            {
                while(fread(&pelicula,sizeof(EMovie),1,pArchivoAux))
                {
                    fwrite(&pelicula,sizeof(EMovie),1,pArchivo);
                }
            }
            else
            {
                printf("    Error: No se pudo abrir el archivo.\n");
            }
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }

    fclose(pArchivo);
    fclose(pArchivoAux);
}

int ingresarIdPelicula()
{
    int id;
    char idIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID de la pelicula: ");
        //fflush(stdin);
        scanf("%s",&idIngresado);

        id = atoi(idIngresado);

        if(!(id < 0))
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
    return id;
}

int mostrarPeliculas()
{
    EMovie pelicula;
    int id = 0;
    FILE * pArchivo;
    int flag = 0;
    pArchivo = fopen("peliculas.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&pelicula,sizeof(EMovie),1,pArchivo))
        {
            if(!flag)
            {
                printf(" | ID - TIULO - GENERO - DESCRIPCION - LINK DE LA IMAGEN - PUNTAJE - DURACION |\n");
            }
            printf(" | %d - %.10s - %s - %.11s - %.17s - %d - %d\n", id, pelicula.titulo, pelicula.genero, pelicula.descripcion, pelicula.linkImagen, pelicula.puntaje, pelicula.duracion);
            flag = 1;
            id++;
        }
        if(!flag)
        {
            printf("    Error: No hay peliculas registradas.\n");
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
    return flag;
}

void guardarPeliculaEnArchivo(char titulo[], char genero[], char descripcion[], char linkImagen[], int puntaje, int duracion)
{
    EMovie pelicula;
    FILE * pArchivo;

    strcpy(pelicula.titulo, titulo);
    strcpy(pelicula.genero, genero);
    strcpy(pelicula.descripcion, descripcion);
    strcpy(pelicula.linkImagen, linkImagen);
    pelicula.puntaje = puntaje;
    pelicula.duracion = duracion;

    pArchivo = fopen("peliculas.bin","ab");
    if(pArchivo != NULL)
    {
        fwrite(&pelicula,sizeof(EMovie),1,pArchivo);
        printf("Guardado.\n");
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}

int addMovieToWeb(EMovie pelicula)
{
    int guardado = 0;
    FILE * pArchivoWeb;
    pArchivoWeb = fopen("template/index.html","a");
    if(pArchivoWeb != NULL)
    {
        fprintf(pArchivoWeb, "\t\t\t<article class=\'col-md-4 article-intro\'>\n\t\t\t\t<a href=\'#\'>\n\t\t\t\t\t<img class=\'img-responsive img-rounded\' src=\'%s\' alt=\'\'>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href=\'#\'>%s</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>%s</li>\n\t\t\t\t\t<li>Puntaje: %d</li>\n\t\t\t\t\t<li>Duración: %d</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>%s</p>\n\t\t\t</article>\n", pelicula.linkImagen, pelicula.titulo, pelicula.genero, pelicula.puntaje, pelicula.duracion, pelicula.descripcion);
        guardado = 1;
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivoWeb);
    return guardado;
}

void generarWeb()
{
    FILE * pArchivo;
    FILE * pArchivoWeb;
    EMovie pelicula;
    int flag = 0;

    pArchivoWeb = fopen("template/index.html","w");

    if(pArchivoWeb != NULL)
    {
        fprintf(pArchivoWeb, "<!DOCTYPE html>\n<html lang=\'en\'>\n<head>\n\t<meta charset=\'utf-8\'>\t<meta http-equiv=\'X-UA-Compatible\' content=\'IE=edge\'>\t<meta name=\'viewport\' content=\'width=device-width, initial-scale=1\'>\n\t<title>Lista peliculas</title>\n\t<link href=\'css/bootstrap.min.css\' rel=\'stylesheet\'>\n\t<link href=\'css/custom.css\' rel=\'stylesheet\'>\n</head>\n<body>\n\t<div class=\'container\'>\n\t\t<div class=\'row\'>\n");
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivoWeb);

    pArchivo = fopen("peliculas.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&pelicula,sizeof(EMovie),1,pArchivo))
        {
            flag = addMovieToWeb(pelicula);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);

    pArchivoWeb = fopen("template/index.html","a");
    if(pArchivo != NULL)
    {
        fprintf(pArchivoWeb, "\t\t</div>\n\t</div>\n\t<script src=\'js/jquery-1.11.3.min.js\'></script>\n\t<script src=\'js/bootstrap.min.js\'></script>\n\t<script src=\'js/ie10-viewport-bug-workaround.js\'></script>\n\t<script src=\'js/holder.min.js\'></script>\n</body>\n</html>");
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivoWeb);

    if(!flag)
    {
        printf("    Aviso: No se guardo ninguna pelicula.\n");
    }
}

int buscarPeliculaPorTitulo(char titulo[])
{
    int resultado = -1;
    int id = 0;
    EMovie pelicula;
    FILE * pArchivo;

    pArchivo = fopen("peliculas.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&pelicula,sizeof(EMovie),1,pArchivo))
        {
            if(!(strcmp(pelicula.titulo, titulo)))
            {
                resultado = id;
            }
            id++;
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);

    return resultado;
}

int pedirPuntaje()
{
    int puntaje;
    char puntajeIngresado[40];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el puntaje de la pelicula (0 - 10): ");
        //fflush(stdin);
        scanf("%s",&puntajeIngresado);
        puntaje = atoi(puntajeIngresado);

        if((puntaje > 0) && (puntaje < 11))
        {
            flag = 1;
        }
        else
        {
            if(!(strcmp(puntajeIngresado, "0")))
            {
                flag = 1;
            }
            else
            {
                printf("    Error: N%cmero no v%clido.\n", 163, 160);
            }
        }
    }
    return puntaje;
}

int pedirDuracion()
{
    int duracion;
    char duracionIngresada[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la duracion de la pelicula: ");
        fflush(stdin);
        scanf("%s",&duracionIngresada);
        duracion = atoi(duracionIngresada);

        if(duracion > 0)
        {
            flag = 1;
        }
        else
        {
            if(!(strcmp(duracionIngresada, "0")))
            {
                flag = 1;
            }
            else
            {
                printf("    Error: N%cmero no v%clido.\n", 163, 160);
            }
        }
    }
    return duracion;
}

void pedirTitulo(char titulo[])
{
    int flag = 0;
    char tituloIngresado[200];

    while(!flag)
    {
        printf("Ingrese el titulo: ");
        //fflush(stdin);
        scanf("%s",&tituloIngresado);

        if(!(atoi(tituloIngresado)))
        {
            strcpy(titulo, tituloIngresado);
            flag = 1;
        }
        else
        {
            printf("    Error: No es un titulo v%clido.\n", 160);
        }
    }
    printf("\n");
}
void pedirGenero(char genero[])
{
    int flag = 0;
    char generoIngresado[20];

    while(!flag)
    {
        printf("Ingrese el genero: ");
        //fflush(stdin);
        scanf("%s",&generoIngresado);

        if(!(atoi(generoIngresado)))
        {
            strcpy(genero, generoIngresado);
            flag = 1;
        }
        else
        {
            printf("    Error: No es un genero v%clido.\n", 160);
        }
    }
    printf("\n");
}
void pedirDescripcion(char descripcion[])
{
    int flag = 0;
    char descripcionIngresada[200];

    while(!flag)
    {
        printf("Ingrese la descripcion: ");
        //fflush(stdin);
        scanf("%s",&descripcionIngresada);

        if(!(atoi(descripcionIngresada)))
        {
            strcpy(descripcion, descripcionIngresada);
            flag = 1;
        }
        else
        {
            printf("    Error: No es una descripcion v%clido.\n", 160);
        }
    }
    printf("\n");
}
void pedirLink(char linkImagen[])
{
    int flag = 0;
    char linkIngresado[200];

    while(!flag)
    {
        printf("Ingrese el link de la imagen: ");
        //fflush(stdin);
        scanf("%s",&linkIngresado);

        if(!(atoi(linkIngresado)))
        {
            strcpy(linkImagen, linkIngresado);
            flag = 1;
        }
        else
        {
            printf("    Error: No es un link v%clido.\n", 160);
        }
    }
    printf("\n");
}
