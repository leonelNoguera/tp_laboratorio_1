/*funciones.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
#include "funciones.h"
#include "../inc/Employee.h"

void agregarEmpleado(ArrayList* this)
{
    if(this != NULL)
    {
        char apellido[40];
        char nombre[20];

        pedirApellido(apellido);
        pedirNombre(nombre);
        float salario = pedirSalario();
        int sector = pedirSector();

        Employee* empleado = newEmployee(0, nombre, apellido, salario, sector);

        if(al_add(this, empleado))
        {
            //guardarEmpleadosEnArchivo(empleado->lastName, empleado->name, empleado->salary, empleado->sector);
            printf("    Error: No se guardo el empleado.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

/*void borrarempleado()
{
    FILE * pArchivo;
    FILE * pArchivoAux;
    EMovie empleado;
    int contador = 0;
    int encontro = 0;

    mostrarempleados();

    pArchivo = fopen("empleados.bin","rb");
    pArchivoAux = fopen("empleadosAux.bin","wb");

    if((pArchivo != NULL) || (pArchivoAux != NULL))
    {
        int id = ingresarIdempleado();
        while(fread(&empleado,sizeof(EMovie),1,pArchivo))
        {
            if(contador == id)
            {
                encontro = 1;
            }
            else
            {
                fwrite(&empleado,sizeof(EMovie),1,pArchivoAux);
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
            pArchivo = fopen("empleados.bin","wb");
            pArchivoAux = fopen("empleadosAux.bin","rb");
            while(fread(&empleado,sizeof(EMovie),1,pArchivoAux))
            {
                fwrite(&empleado,sizeof(EMovie),1,pArchivo);
            }
        }
        else
        {
            printf("    Error: No se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
    fclose(pArchivoAux);
}

void modificarempleado()
{
    FILE * pArchivo;
    FILE * pArchivoAux;
    EMovie empleado;
    int contador = 0;
    int encontro = 0;

    char apellido[40];
    char nombre[20];
    char descripcion[200];
    char linkImagen[200];

    mostrarempleados();

    pArchivo = fopen("empleados.bin","rb");
    pArchivoAux = fopen("empleadosAux.bin","wb");

    if((pArchivo != NULL) || (pArchivoAux != NULL))
    {
        int id = ingresarIdempleado();
        while(fread(&empleado,sizeof(EMovie),1,pArchivo))
        {
            if(contador == id)
            {
                pedirApellido(apellido);

                if((buscarempleadoPorapellido(apellido) == -1) || (buscarempleadoPorapellido(apellido) == id))
                {
                    pedirNombre(nombre);
                    pedirDescripcion(descripcion);
                    pedirLink(linkImagen);

                    float salario = pedirSalario();
                    int sector = pedirsector();

                    fwrite(&empleado,sizeof(EMovie),1,pArchivoAux);

                    printf("Modificado.\n");
                }
                else
                {
                    printf("    Error: Ya hay una empleado con ese apellido\n");
                }
                encontro = 1;
            }
            else
            {
                fwrite(&empleado,sizeof(EMovie),1,pArchivoAux);
            }
            contador++;
        }
        if(!encontro)
        {
            printf("    Error: No se encuentra ese ID.\n");
        }
        fclose(pArchivo);
        fclose(pArchivoAux);

        pArchivo = fopen("empleados.bin","wb");
        pArchivoAux = fopen("empleadosAux.bin","rb");

        if((pArchivo != NULL) || (pArchivoAux != NULL))
        {
            while(fread(&empleado,sizeof(EMovie),1,pArchivoAux))
            {
                fwrite(&empleado,sizeof(EMovie),1,pArchivo);
            }
        }
        else
        {
            printf("    Error: No se pudo abrir el archivo.\n");
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }

    fclose(pArchivo);
    fclose(pArchivoAux);
}

int ingresarIdempleado()
{
    int id;
    char idIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID de la empleado: ");
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

void mostrarempleados()
{
    EMovie empleado;
    int id = 0;
    FILE * pArchivo;
    int flag = 0;
    pArchivo = fopen("empleados.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&empleado,sizeof(EMovie),1,pArchivo))
        {
            if(!flag)
            {
                printf(" | ID --- NOMBRE --- PRECIO --- CANTIDAD VENDIDA --- STOCK --- NOMBRE USUARIO|\n");
            }
            printf(" | %d\t - %s\t - %s\t - %s\t - %s\t - %d\t - %d\n", id, empleado.apellido, empleado.nombre, empleado.descripcion, empleado.linkImagen, empleado.salario, empleado.sector);
            flag = 1;
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}*/

void guardarEmpleadosEnArchivo(ArrayList* this)
{
    int cantidad = 0;
    int leido;
    FILE * pArchivo;

    Employee* empleado;
    pArchivo = fopen("empleados.bin","ab");
    if(pArchivo != NULL)
    {
        int i;
        for(i = 0; i < this->size; i++)
        {
            empleado = this->get(this, i);
            fwrite(&empleado,sizeof(Employee),1,pArchivo);
            printf("Guardado.\n");
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}

/*void addMovieToWeb(EMovie empleado)
{
    printf("El link:\n%s\n", empleado.linkImagen);
    FILE * pArchivoWeb;
    pArchivoWeb = fopen("template/index.html","a");
    if(pArchivoWeb != NULL)
    {
        fprintf(pArchivoWeb, "\t\t\t<article class=\'col-md-4 article-intro\'>\n\t\t\t\t<a href=\'#\'>\n\t\t\t\t\t<img class=\'img-responsive img-rounded\' src=\'%s\' alt=\'\'>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href=\'#\'>%s</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>%s</li>\n\t\t\t\t\t<li>salario: %d</li>\n\t\t\t\t\t<li>Duración: %d</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>%s</p>\n\t\t\t</article>\n", empleado.linkImagen, empleado.apellido, empleado.nombre, empleado.salario, empleado.sector, empleado.descripcion);
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivoWeb);
}

void generarWeb()
{
    FILE * pArchivo;
    FILE * pArchivoWeb;
    EMovie empleado;

    pArchivoWeb = fopen("template/index.html","w");

    if(pArchivoWeb != NULL)
    {
        fprintf(pArchivoWeb, "<!DOCTYPE html>\n<html lang=\'en\'>\n<head>\n\t<meta charset=\'utf-8\'>\t<meta http-equiv=\'X-UA-Compatible\' content=\'IE=edge\'>\t<meta name=\'viewport\' content=\'width=device-width, initial-scale=1\'>\n\t<title>Lista empleados</title>\n\t<link href=\'css/bootstrap.min.css\' rel=\'stylesheet\'>\n\t<link href=\'css/custom.css\' rel=\'stylesheet\'>\n</head>\n<body>\n\t<div class=\'container\'>\n\t\t<div class=\'row\'>\n");
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivoWeb);

    // agregando empleados
    pArchivo = fopen("empleados.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&empleado,sizeof(EMovie),1,pArchivo))
        {
            addMovieToWeb(empleado);
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
}

int buscarempleadoPorapellido(char apellido[])
{
    int resultado = -1;
    int id = 0;
    EMovie empleado;
    FILE * pArchivo;

    pArchivo = fopen("empleados.bin","rb");

    if(pArchivo != NULL)
    {
        while(fread(&empleado,sizeof(EMovie),1,pArchivo))
        {
            if(!(strcmp(empleado.apellido, apellido)))
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
}*/

float pedirSalario()
{
    float salario;
    //char salarioIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el salario del empleado: ");
        fflush(stdin);
        scanf("%f",&salario);
        //salario = atof(salarioIngresado);

        /*if(!(salario < 0.0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: N%cmero no v%clido.\n", 163, 160);
            flag = 0;
        }*/
        flag = 1;
    }
    return salario;
}

int pedirSector()
{
    int sector;
    char sectorIngresada[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la sector de la empleado: ");
        fflush(stdin);
        scanf("%s",&sectorIngresada);
        sector = atoi(sectorIngresada);

        if(!(sector <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: N%cmero no v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    return sector;
}

void pedirApellido(char apellido[])
{
    printf("Ingrese el apellido: ");
    //fflush(stdin);
    scanf("%s",&apellido);
    printf("\n");
}
void pedirNombre(char nombre[])
{
    printf("Ingrese el nombre: ");
    //fflush(stdin);
    scanf("%s",&nombre);
    printf("\n");
}
