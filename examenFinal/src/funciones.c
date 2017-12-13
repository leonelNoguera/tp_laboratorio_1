#include "../inc/funciones.h"
#include "../inc/Empleado.h"
#include "../inc/ArrayList.h"
#include "Empleado.c"
#include "Registro.c"
#include <string.h>

void agregarEmpleado(ArrayList* empleados)
{
    if(empleados != NULL)
    {
        char nombre[51];
        char apellido[51];

        pedirNombre(nombre);
        pedirApellido(apellido);
        int dni = pedirDni();

        int id = idDisponibleEmpleados(empleados);

        Empleado* empleado = newEmpleado();

        if(empleado != NULL)
        {
            setIdEmpleado(empleado, id);
            setNombre(empleado, nombre);
            setApellido(empleado, apellido);
            setDni(empleado, dni);

            if(empleados->add(empleados, empleado))
            {
                printf("    Error: No se guardo el empleado.\n");
            }
            else
            {
                printf("%d) %d,%s,%s,%d\n", empleados->len(empleados), empleado->id, empleado->nombre, empleado->apellido, empleado->dni);
                guardarEmpleadosEnArchivo(empleados);
                printf("Guardado.\n");
            }
        }
        else
        {
            printf("    Error: empleado = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList empleados = NULL.\n");
    }
}

void modificarEmpleado(ArrayList* empleados)
{
    if(empleados != NULL)
    {
        char nombre[51];
        char apellido[51];

        int id = pedirIdEmpleado();

        Empleado* empleado = buscarEmpleadoPorId(empleados, id);

        if(empleado != NULL)
        {
            pedirNombre(nombre);
            pedirApellido(apellido);
            int dni = pedirDni();

            setNombre(empleado, nombre);
            setApellido(empleado, apellido);
            setDni(empleado, dni);

            guardarEmpleadoPorId(empleados, empleado, id);

            guardarEmpleadosEnArchivo(empleados);

            printf("Guardado.\n");
        }
        else
        {
            printf("    Error: empleado = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList empleados = NULL.\n");
    }
}

void eliminarEmpleado(ArrayList* empleados)
{
    if(empleados != NULL)
    {
        int id = pedirIdEmpleado();

        Empleado* empleado = buscarEmpleadoPorId(empleados, id);

        if(empleado != NULL)
        {
            eliminarEmpleadoPorId(empleados, id);

            guardarEmpleadosEnArchivo(empleados);

            printf("Guardado.\n");
        }
        else
        {
            printf("    Error: empleado = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList empleados = NULL.\n");
    }
}

void eliminarRegistro(ArrayList* registros)
{
    if(registros != NULL)
    {
        int id = pedirIdRegistro();

        Registro* registro = buscarRegistroPorId(registros, id);

        if(registro != NULL)
        {
            eliminarRegistroPorId(registros, id);

            guardarRegistrosEnArchivo(registros);

            printf("Guardado.\n");
        }
        else
        {
            printf("    Error: registro = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList registros = NULL.\n");
    }
}

void mostrarEmpleados(ArrayList* empleados)
{
    ArrayList* empleadosAux = empleados->clone(empleados);
    empleadosAux->sort(empleadosAux, compareEmpleado, 1);

    if(empleadosAux != NULL)
    {
        int i=0;
        printf("cantidad: %d\n", empleadosAux->len(empleadosAux));
        for(i=0;i<empleadosAux->len(empleadosAux);i++)
        {
            Empleado* pAux = empleadosAux->get(empleadosAux,i);
            printEmpleado(pAux);
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void mostrarRegistros(ArrayList* this)
{
    if(this != NULL)
    {
        int i=0;
        for(i=0;i<this->len(this);i++)
        {
            Registro* pAux = this->get(this,i);
            printRegistro(pAux);
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void mostrarRegistrosPorTarea(ArrayList* registros)
{
    int codigoDeTrabajo = pedirCodigoTrabajo();
    if(registros != NULL)
    {
        int i=0;
        for(i=0;i<registros->len(registros);i++)
        {
            Registro* pAux = registros->get(registros,i);
            if (getCodigoDeTrabajo(pAux) == codigoDeTrabajo)
            {
                printRegistro(pAux);
            }
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void generarInformeRegistros(ArrayList* registros)
{
    if(registros != NULL)
    {
        FILE * pArchivo;
        pArchivo = fopen("informe.txt","w");

        int i=0;
        for(i=0;i<registros->len(registros);i++)
        {
            Registro* pAux = registros->get(registros,i);
            fprintf(pArchivo, "id: %d - id de empleado: %d - codigo de trabajo: %d - cantidad de horas: %d - precio unitario: %f\n", pAux->id, pAux->id_empleado, pAux->codigoDeTrabajo, pAux->cantidadDeHoras, pAux->precioUnitario);
        }

        fclose(pArchivo);
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

int idDisponibleEmpleados(ArrayList* empleados)
{
    int id = 0;

    Empleado* empleadoAux;

    int i;
    for(i=0; i<empleados->len(empleados); i++)
    {
        if(empleados->get(empleados, i) != NULL)
        {
            empleadoAux = empleados->get(empleados, i);

            if(empleadoAux->id == id)
            {
                id++;
                i = -1;
            }
        }
        else
        {
            printf("Problema.\n");
        }

    }

    return id;
}

int idDisponibleRegistros(ArrayList* registros)
{
    int id = 0;

    Registro* registroAux;

    int i;
    for(i=0; i<registros->len(registros); i++)
    {
        if(registros->get(registros, i) != NULL)
        {
            registroAux = registros->get(registros, i);

            if(registroAux->id == id)
            {
                id++;
                i = -1;
            }
        }
        else
        {
            printf("Problema.\n");
        }

    }

    return id;
}

void registrarDia(ArrayList* registros)
{
    if(registros != NULL)
    {
        //id_registro,id_empleado,codTarea,cantidadDeHoras,precioUnitario
        int id = idDisponibleRegistros(registros);

        int id_empleado = pedirIdEmpleado();
        int codigoDeTrabajo = pedirCodigoTrabajo();
        int cantidadDeHoras = pedirCantidadDeHoras();

        float precioUnitario = obtenerPrecioUnitario(codigoDeTrabajo);

        Registro* registro = newRegistro();

        if(registro != NULL)
        {
            setIdRegistro(registro, id);
            setId_empleado(registro, id_empleado);
            setCodigoDeTrabajo(registro, codigoDeTrabajo);
            setCantidadDeHoras(registro, cantidadDeHoras);
            setPrecioUnitario(registro, precioUnitario);

            printf("...\n");

            if(registros->add(registros, registro))
            {
                printf("    Error: No se guardo el registro.\n");
            }
            else
            {
                guardarRegistrosEnArchivo(registros);
                printf("Guardado.\n");
            }
        }
        else
        {
            printf("    Error: registro = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList registros = NULL.\n");
    }
}

void cargarEmpleadosDesdeArchivo(ArrayList* empleados)
{
    Empleado* empleadoAux;
    FILE * pArchivo;
    pArchivo = fopen("empleados.txt","r");

    char idCargado[51];
    int id;
    char nombre[51];
    char apellido[51];
    int dniCargado[51];
    int dni;

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idCargado, nombre, apellido, dniCargado);

        while(fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idCargado, nombre, apellido, dniCargado) == 4)
        {
            id = atoi(idCargado);
            dni = atoi(dniCargado);
            empleadoAux = newEmpleadoParam(id, nombre, apellido, dni);
            empleados->add(empleados, empleadoAux);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}

void guardarEmpleadosEnArchivo(ArrayList* empleados)
{
    Empleado* empleadoAux = newEmpleado();
    FILE * pArchivo;
    pArchivo = fopen("empleados.txt","w");

    if(pArchivo != NULL)
    {
        int id;
        char nombre[51];
        char apellido[51];
        int dni;

        fprintf(pArchivo, "id,nombre,apellido,dni\n");
        int i=0;
        for(i=0;i<empleados->len(empleados);i++)
        {
            empleadoAux = empleados->get(empleados,i);

            id = getIdEmpleado(empleadoAux);
            getNombre(empleadoAux, nombre);
            getApellido(empleadoAux, apellido);
            dni = getDni(empleadoAux);

            fprintf(pArchivo, "%d,%s,%s,%d\n", id, nombre, apellido, dni);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}

void cargarRegistrosDesdeArchivo(ArrayList* registros)
{
    FILE * pArchivo;
    pArchivo = fopen("registro_de_dias.txt","r");
    Registro* registroAux;

    int id;
    char idCargado[51];
    int id_empleado;
    char id_empleadoCargado[51];
    int codigoDeTrabajo;
    char codigoDeTrabajoCargado[51];
    int cantidadDeHoras;
    char cantidadDeHorasCargado[51];
    float precioUnitario;
    char precioUnitarioCargado[51];

    if(pArchivo != NULL)
    {
        fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCargado, id_empleadoCargado, codigoDeTrabajoCargado, cantidadDeHorasCargado, precioUnitarioCargado);
        while(fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCargado, id_empleadoCargado, codigoDeTrabajoCargado, cantidadDeHorasCargado, precioUnitarioCargado) == 5)
        {
            id = atoi(idCargado);
            id_empleado = atoi(id_empleadoCargado);
            codigoDeTrabajo = atoi(codigoDeTrabajoCargado);
            cantidadDeHoras = atoi(cantidadDeHorasCargado);

            precioUnitario = atof(precioUnitarioCargado);

            registroAux = newRegistroParam(id, id_empleado, codigoDeTrabajo, cantidadDeHoras, precioUnitario);
            registros->add(registros, registroAux);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
        printf("registros\n");
    }
    fclose(pArchivo);
}

void guardarRegistrosEnArchivo(ArrayList* registros)
{
    Registro* registroAux = newRegistro();
    FILE * pArchivo;
    pArchivo = fopen("registro_de_dias.txt","w");

    if(pArchivo != NULL)
    {
        int id;
        int id_empleado;
        int codigoDeTrabajo;
        int cantidadDeHoras;
        float precioUnitario;

        fprintf(pArchivo, "id_registro,id_empleado,codTarea,cantidadDeHoras,precioUnitario\n");

        int i;
        for(i=0;i<registros->len(registros);i++)
        {
            registroAux = registros->get(registros,i);

            id = getIdRegistro(registroAux);
            id_empleado = getId_empleado(registroAux);
            codigoDeTrabajo = getCodigoDeTrabajo(registroAux);
            cantidadDeHoras = getCantidadDeHoras(registroAux);
            precioUnitario = getPrecioUnitario(registroAux);

            fprintf(pArchivo, "%d,%d,%d,%d,%f\n", id, id_empleado, codigoDeTrabajo, cantidadDeHoras, precioUnitario);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    fclose(pArchivo);
}

Empleado* buscarEmpleadoPorId(ArrayList* empleados, int id)
{
    Empleado* empleado = NULL;
    Empleado* empleadoAux = newEmpleado();

    int i=0;
    for(i=0;i<empleados->len(empleados);i++)
    {
        empleadoAux = empleados->get(empleados,i);

        if(getIdEmpleado(empleadoAux) == id)
        {
            empleado = empleadoAux;
            break;
        }
    }

    return empleado;
}

Registro* buscarRegistroPorId(ArrayList* registros, int id)
{
    Registro* registro = NULL;
    Registro* registroAux = newRegistro();

    int i=0;
    for(i=0;i<registros->len(registros);i++)
    {
        registroAux = registros->get(registros,i);

        if(getIdRegistro(registroAux) == id)
        {
            registro = registroAux;
            break;
        }
    }

    return registro;
}

void guardarEmpleadoPorId(ArrayList* empleados, Empleado* empleado, int id)
{
    Empleado* empleadoAux = newEmpleado();

    int i=0;
    for(i=0;i<empleados->len(empleados);i++)
    {
        empleadoAux = empleados->get(empleados,i);

        if(getIdEmpleado(empleadoAux) == id)
        {
            empleados->set(empleados, i, empleado);
            break;
        }
    }
}

void eliminarEmpleadoPorId(ArrayList* empleados, int id)
{
    Empleado* empleadoAux = newEmpleado();

    int i=0;
    for(i=0;i<empleados->len(empleados);i++)
    {
        empleadoAux = empleados->get(empleados,i);

        if(getIdEmpleado(empleadoAux) == id)
        {
            empleados->remove(empleados, i);
            break;
        }
    }
}

void eliminarRegistroPorId(ArrayList* registros, int id)
{
    Registro* registroAux = newRegistro();

    int i=0;
    for(i=0;i<registros->len(registros);i++)
    {
        registroAux = registros->get(registros,i);

        if(getIdRegistro(registroAux) == id)
        {
            registros->remove(registros, i);
            break;
        }
    }
}

void pedirNombre(char nombre[])
{
    printf("Ingrese el nombre: ");
    //fflush(stdin);
    scanf("%s",nombre);
    printf("\n");
}

void pedirApellido(char apellido[])
{
    printf("Ingrese el apellido: ");
    //fflush(stdin);
    scanf("%s",apellido);
    printf("\n");
}

int pedirDni()
{
    int dni;
    char dniIngresado[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el dni del empleado: ");
        fflush(stdin);
        scanf("%s",&dniIngresado);
        dni = atoi(dniIngresado);

        if(!(dni <= 0))
        {
            flag = 1;
        }
        else
        {
            printf("    Error: N%cmero no v%clido.\n", 163, 160);
            flag = 0;
        }
    }
    return dni;
}

int pedirIdEmpleado()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID de la empleado: ");
        //fflush(stdin);
        scanf("%s",&indexIngresado);

        index = atoi(indexIngresado);

        if(!(index < 0))
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
    return index;
}

int pedirIdRegistro()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID del registro: ");
        //fflush(stdin);
        scanf("%s",&indexIngresado);

        index = atoi(indexIngresado);

        if(!(index < 0))
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
    return index;
}

int pedirCodigoTrabajo()
{
    int codigo;
    char codigoIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el codigo del trabajo (20, 30 o 40): ");
        //fflush(stdin);
        scanf("%s",&codigoIngresado);

        codigo = atoi(codigoIngresado);

        if((codigo == 20) || (codigo == 30) || (codigo == 40))
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
    return codigo;
}

int pedirCantidadDeHoras()
{
    int horas;
    char horasIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese la cantidad de horas trabajadas: ");
        //fflush(stdin);
        scanf("%s",&horasIngresado);

        horas = atoi(horasIngresado);

        if(!(horas < 0))
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
    return horas;
}

float obtenerPrecioUnitario(int cantidadDeHoras)
{
    float resultado = -1;

    if(cantidadDeHoras == 20)
    {
        resultado = 295.55;
    }
    else
    {
        if(cantidadDeHoras == 30)
        {
            resultado = 252.23;
        }
        else
        {
            if(cantidadDeHoras == 40)
            {
                resultado = 215.22;
            }
            else
            {
                printf("    Error: No se pudo obtener el precio unitario.\n");
            }
        }
    }

    return resultado;
}
