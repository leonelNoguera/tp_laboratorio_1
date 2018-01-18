#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/funciones.h"
#include "ArrayList.c"
#include "funciones.c"

int main()
{
    /*char fechaDeIngreso[50];
    int flag = 1;
    while(flag)
    {
        printf("Ingrese la fecha de ingreso (DD/MM/YYYY): ");
        //fflush(stdin);
        scanf("%s", fechaDeIngreso);
        
        //char c;
        int i = -1;
        char numeroTomado[10];
        do
        {
            i++;
            //c = fechaDeIngreso[i];
            numeroTomado = fechaDeIngreso[i];
        }
        while(c != '/');

        if(i <= 10)
        {
            flag = 0;
        }
        else
        {
            printf("    Error: El codigo es muy largo, la cantidad de caracteres maxima es 5.\n");
        }
    }*/




    ArrayList* clientes;
	clientes = al_newArrayList();
	ArrayList* servicios;
	servicios = al_newArrayList();

	char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Alta de cliente.\n");
        printf("2- Modificacion de cliente.\n");
        printf("3- Baja de cliente.\n");
        printf("4- Listar clientes.\n");
        //printf("5- Importar servicios tecnicos desde CSV.\n");
        printf("6- Ingresar un servicio tecnico.\n");
        printf("7- Finalizar un servicio tecnico.\n");
        //printf("8- Exportar servicios tecnicos de un cliente.\n");
        //printf("9- Imprimir servicios tecnicos por producto.\n");
        //printf("8- Informe de servicios de dias por tarea.\n");
        //printf("9- Generar informe de servicios de dias.\n");
        //printf("10- Informe de cantidad de dias trabajados.\n");
        printf("11- Mostrar clientes.bin.\n");
        printf("12- Mostrar servicios.bin\n");
        printf("13- Salir.\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarCliente(clientes);
                break;
            case 2:
                modificarCliente(clientes);
                break;
            case 3:
                eliminarCliente(clientes, servicios);
                break;
            case 4:
                mostrarClientes(clientes);
                break;
            case 6:
                registrarServicio(servicios);
                break;
            case 7:
                finalizarServicio(servicios);
                break;
            case 8:
                //exportarServiciosTecnicos(servicios, clientes);
                break;
            case 9:
                mostrarServicios(servicios);
                break;
            /*case 8:
                mostrarServiciosPorTarea(servicios);
                break;
            case 9:
                generarInformeServicios(servicios);
                break;
            case 10:
                //
                break;*/
            case 11:
                mostrarClientesDesdeArchivo();
                break;
            case 12:
                mostrarServiciosDesdeArchivo();
                break;    
            case 13:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
