#include <stdio.h>
#include <stdlib.h>
#include "../inc/ArrayList.h"
#include "../inc/funciones.h"
#include "ArrayList.c"
#include "funciones.c"

int main()
{
	ArrayList* empleados;
	empleados = al_newArrayList();
	ArrayList* registros;
	registros = al_newArrayList();

    cargarEmpleadosDesdeArchivo(empleados);
    cargarRegistrosDesdeArchivo(registros);

	char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Alta de empleado.\n");
        printf("2- Modificacion de empleado.\n");
        printf("3- Baja de empleado.\n");
        printf("4- Listar empleados.\n");
        printf("5- Registrar dia.\n");
        printf("6- Anular registro.\n");
        printf("7- Informe de registros de dias.\n");
        printf("8- Informe de registros de dias por tarea.\n");
        printf("9- Generar informe de registros de dias.\n");
        //printf("10- Informe de cantidad de dias trabajados.\n");
        printf("11- Salir.\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarEmpleado(empleados);
                break;
            case 2:
                modificarEmpleado(empleados);
                break;
            case 3:
                eliminarEmpleado(empleados);
                break;
            case 4:
                mostrarEmpleados(empleados);
                break;
            case 5:
                registrarDia(registros);
                break;
            case 6:
                eliminarRegistro(registros);
                break;
            case 7:
                mostrarRegistros(registros);
                break;
            case 8:
                mostrarRegistrosPorTarea(registros);
                break;
            case 9:
                generarInformeRegistros(registros);
                break;
            case 10:
                //
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
