#include "inc/funciones.h"
#include "inc/Cliente.h"
#include "inc/ArrayList.h"
#include "Cliente.c"
#include "Servicio.c"
#include <string.h>

void agregarCliente(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        char nombre[51];
        char apellido[51];

        pedirNombre(nombre);
        pedirApellido(apellido);
        long int dni = pedirDni();

        int id = idDisponibleClientes(clientes); // La función retorna el menor id disponible del ArrayList, evita repeticiones de id.

        Cliente* cliente = newCliente();

        if(cliente != NULL)
        {
            setIdCliente(cliente, id);
            setNombre(cliente, nombre);
            setApellido(cliente, apellido);
            setDni(cliente, dni); // ¿permite hasta 4 digitos?

            //printf("Punto de control...\n");

            if(clientes->add(clientes, cliente))
            {
                printf("    Error: No se guardo el cliente.\n");
            }
            else
            {
                printf("Cliente guardado en memoria RAM.\n");
                guardarClienteEnArchivo(cliente);
            }
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void modificarCliente(ArrayList* clientes)
{
    if(clientes != NULL)
    {
        char nombre[51];
        char apellido[51];

        int id = pedirIdCliente();

        Cliente* cliente = buscarClientePorId(clientes, id); // Retorna el cliente que tiene el id indicado, retorna NULL si no lo encuentra.

        if(cliente != NULL)
        {
            pedirNombre(nombre);
            pedirApellido(apellido);
            int dni = pedirDni();

            setNombre(cliente, nombre);
            setApellido(cliente, apellido);
            setDni(cliente, dni);

            guardarClientePorId(clientes, cliente, id); // Sobreescribe el cliente que tiene el id indicado.

            guardarClienteEnArchivo(cliente);
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void eliminarCliente(ArrayList* clientes, ArrayList* servicios)
{
    if(clientes != NULL)
    {
        int id_cliente = pedirIdCliente(); // Pide el id y verifica que sea >= 0.

        Cliente* cliente = buscarClientePorId(clientes, id_cliente); // Retorna el cliente que tiene el id indicado, retorna NULL si no lo encuentra.

        if(cliente != NULL)
        {
            if(buscarClienteEnServicios(servicios, id_cliente))
            {
                printf("    Error: Hay alguna venta asociada al cliente, no se puede eliminar el cliente.\n");
            }
            else
            {
                if(eliminarClientePorId(clientes, id_cliente)) // Elimina el cliente que tiene ese id.
                {
                    printf("Cliente eliminado de la memoria RAM.\n");
                }
                else
                {
                    printf("    Error: No se pudo eliminar el cliente.\n");
                }
            }
        }
        else
        {
            printf("    Error: cliente = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList clientes = NULL.\n");
    }
}

void mostrarClientes(ArrayList* clientes)
{
    if(clientes->len(clientes) > 0)
    {
        ArrayList* clientesAux = clientes->clone(clientes); // Se crea un ArrayList auxiliar.
        clientesAux->sort(clientesAux, compareCliente, 1); // Se ordena el ArrayList auxiliar.

        if(clientesAux != NULL)
        {
            int i=0;
            for(i=0;i<clientesAux->len(clientesAux);i++) // Recorre todo el ArrayList auxiliar.
            {
                printCliente(clientesAux->get(clientesAux,i));
            }
        }
        else
        {
            printf("    Error: No se pudo crear el ArrayList auxiliar.\n");
        }
    }
    else
    {
        printf("    Error: No hay clientes en el ArrayList.\n");
    }
}

void registrarServicio(ArrayList* servicios)
{
    if(servicios != NULL)
    {
        //id_servicio,id_cliente,codTarea,fechaDeIngreso,costoDeReparacion
        int id = idDisponibleServicios(servicios);

        int id_cliente = pedirIdCliente(); // Pide el id del cliente y verifica que sea >= 0.
        char codigoDeProducto[51];
        pedirCodigoProducto(codigoDeProducto);  // Esta función pide el codigo y verifica que no tenga más de 5 caracteres.
        char fechaDeIngreso[51];
        pedirFechaDeIngreso(fechaDeIngreso); // Faltan verificaciones en esta función.
        float costoDeReparacion = pedirCostoDeReparacion(); // Faltan verificaciones en esta función.

        Servicio* servicio = newServicio();

        if(servicio != NULL)
        {
            setIdServicio(servicio, id);
            setId_cliente(servicio, id_cliente);
            setCodigoDeProducto(servicio, codigoDeProducto);
            setFechaDeIngreso(servicio, fechaDeIngreso);
            setCostoDeReparacion(servicio, costoDeReparacion);

            if(servicios->add(servicios, servicio))
            {
                printf("    Error: No se guardo el servicio en la memoria RAM.\n");
            }
            else
            {
                printf("Guardado en memoria RAM.\n");
                //guardarServicioEnArchivo(servicio);
            }
        }
        else
        {
            printf("    Error: servicio = NULL.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList servicios = NULL.\n");
    }
}

void finalizarServicio(ArrayList* servicios)
{
    if(servicios != NULL)
    {
        int id = pedirIdServicio();

        Servicio* servicio = buscarServicioPorId(servicios, id); // Retorna el cliente que tiene el id indicado, retorna NULL si no lo encuentra.

        if(servicio != NULL)
        {
            finalizarServicioPorId(servicios, id);

            printf("Guardado.\n");
        }
        else
        {
            printf("    Error: servicio = NULL.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList servicios = NULL.\n");
    }
}


void mostrarServicios(ArrayList* servicios)
{
    ArrayList* serviciosAux = servicios->clone(servicios);
    serviciosAux->sort(serviciosAux, compareServicio, 1);

    if(serviciosAux != NULL)
    {
        int i=0;
        printf("cantidad: %d\n", serviciosAux->len(serviciosAux));
        for(i=0;i<serviciosAux->len(serviciosAux);i++)
        {
            Servicio* pAux = serviciosAux->get(serviciosAux,i);
            printServicio(pAux);
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void generarInformeServicios(ArrayList* servicios)
{
    if(servicios != NULL)
    {
        FILE * pArchivo;
        pArchivo = fopen("informe.txt","w");

        int i=0;
        for(i=0;i<servicios->len(servicios);i++)
        {
            Servicio* pAux = servicios->get(servicios,i);
            fprintf(pArchivo, "id: %d - id de cliente: %d - codigo de trabajo: %d - cantidad de horas: %d - precio unitario: %f\n", pAux->id, pAux->id_cliente, pAux->codigoDeProducto, pAux->fechaDeIngreso, pAux->costoDeReparacion);
        }

        fclose(pArchivo);
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

int idDisponibleClientes(ArrayList* clientes)
{
    int id = 0; // el id por defecto es 0, a menos que esté utilizado quedará ese

    Cliente* clienteAux;

    int i;
    for(i=0; i<clientes->len(clientes); i++) // Recorre todo el ArrayList de los clientes.
    {
        if(clientes->get(clientes, i) != NULL)
        {
            clienteAux = clientes->get(clientes, i);

            if(clienteAux->id == id)
            {
                id++; // Si ya se encuentra ese id, incrementa el id.
                i = -1; // Este valor es para que vuelva a revisar desde el principio.
            }
        }
        else
        {
            printf("    Error: El cliente en la posicion %d del ArrayList esta en NULL.\n", i);
        }

    }

    return id;
}

int idDisponibleServicios(ArrayList* servicios)
{
    int id = 0; // El id por defecto es 0, a menos que esté utilizado quedará ese.

    Servicio* servicioAux;

    int i;
    for(i=0; i<servicios->len(servicios); i++) // Recorre todo el ArrayList de los servicios.
    {
        if(servicios->get(servicios, i) != NULL)
        {
            servicioAux = servicios->get(servicios, i);

            if(servicioAux->id == id)
            {
                id++; // Si ya se encuentra ese id, incrementa el id.
                i = -1; // Este valor es para que vuelva a revisar desde el principio.
            }
        }
        else
        {
            printf("Problema.\n");
        }

    }

    return id;
}

void cargarClientesDesdeArchivo(ArrayList* clientes)
{
    /*int cantidad = 0;
    int leido;
    FILE * pArchivo;

    Cliente* cliente = newCliente();

    pArchivo = fopen("clientes.bin","rb");
    if(pArchivo != NULL)
    {
        printf("Antes del while...\n");
        while(fread(&cliente,sizeof(Cliente),1,pArchivo))
        {
            printf("En el while...\n");
            if(cliente != NULL)
            {
                printf("direccion: %p\n", cliente);
                printf("ID: %d\n", getIdCliente(cliente));
                //printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI:%d\n", cliente->id, cliente->nombre, cliente->apellido, cliente->dni);

                //printCliente(cliente);

                clientes->add(clientes, cliente);
                printf("Guardado.\n");
            }
            else
            {
                break;
            }
        }
        fclose(pArchivo);
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }*/
}

void guardarClienteEnArchivo(Cliente* cliente)
{
    FILE * pArchivo;

    pArchivo = fopen("clientes.bin","ab");
    if(pArchivo != NULL)
    {
        fwrite(&cliente,sizeof(Cliente),1,pArchivo);
        printf("Cliente guardado en archivo binario.\n");

        fclose(pArchivo);
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
}

void mostrarClientesDesdeArchivo()
{
    Cliente* cliente = newCliente();
    FILE * pArchivo;
    pArchivo = fopen("clientes.bin","rb");
    if(pArchivo != NULL)
    {
        while(fread(&cliente,sizeof(Cliente),1,pArchivo))
        {
            printCliente(cliente);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    
    fclose(pArchivo);
}

void cargarServiciosDesdeArchivo(ArrayList* servicios)
{
    /*int cantidad = 0;
    int leido;
    FILE * pArchivo;

    Servicio* servicio = newServicio();

    pArchivo = fopen("servicios.bin","rb");
    if(pArchivo != NULL)
    {
        printf("Antes del while...\n");
        while(fread(&servicio,sizeof(Servicio),1,pArchivo))
        {
            printf("En el while...\n");
            if(servicio != NULL)
            {
                printf("direccion: %p\n", servicio);
                printf("ID: %d\n", getIdServicio(servicio));
                //printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI:%d\n", cliente->id, cliente->nombre, cliente->apellido, cliente->dni);

                //printServicio(servicio);

                servicios->add(servicios, servicio);
                printf("Guardado.\n");
            }
            else
            {
                break;
            }
        }
        fclose(pArchivo);
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }*/
}

void guardarServicioEnArchivo(Servicio* servicio)
{
    FILE * pArchivo;

    pArchivo = fopen("servicios.bin","ab");
    if(pArchivo != NULL)
    {
        fwrite(&servicio,sizeof(Servicio),1,pArchivo);
        printf("Guardado en archivo binario.\n");

        fclose(pArchivo);
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
}

void mostrarServiciosDesdeArchivo()
{
    Servicio* servicio;
    FILE * pArchivo;
    pArchivo = fopen("servicios.bin","rb");
    if(pArchivo != NULL)
    {
        while(fread(&servicio,sizeof(Servicio),1,pArchivo))
        {
            printServicio(servicio);
        }
    }
    else
    {
        printf("    Error: No se pudo abrir el archivo.\n");
    }
    
    fclose(pArchivo);
}

Cliente* buscarClientePorId(ArrayList* clientes, int id)
{
    Cliente* cliente = NULL;
    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++)
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            cliente = clienteAux;
            break;
        }
    }

    if(cliente == NULL)
    {
        printf("    Error: No se encontro un cliente con el id %d.\n", id);
    }

    return cliente;
}

Servicio* buscarServicioPorId(ArrayList* servicios, int id)
{
    Servicio* servicio = NULL;
    Servicio* servicioAux = newServicio();

    int i=0;
    for(i=0;i<servicios->len(servicios);i++)
    {
        servicioAux = servicios->get(servicios,i);

        if(getIdServicio(servicioAux) == id)
        {
            servicio = servicioAux;
            break;
        }
    }

    if(servicio == NULL)
    {
        printf("    Error: No se encontro un servicio con el id %d.\n", id);
    }

    return servicio;
}

int buscarClienteEnServicios(ArrayList* servicios, int id_cliente)
{
    int resultado = 0;
    Servicio* servicioAux = newServicio();

    int i=0;
    for(i=0;i<servicios->len(servicios);i++) // Recorre todo el ArrayList de servicios.
    {
        servicioAux = servicios->get(servicios,i);

        if(getId_cliente(servicioAux) == id_cliente)
        {
            resultado = 1; // Hay un servicio asociado a ese id de cliente.
            break;
        }
    }

    return resultado;
}

void guardarClientePorId(ArrayList* clientes, Cliente* cliente, int id)
{
    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++) // Recorre todo el ArrayList de clientes.
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            if(!(clientes->set(clientes, i, cliente))) // Guarda el cliente en la posición indicada por el id.
            {
                printf("Cliente guardado en memoria RAM.\n");
            }
            break;
        }
    }
}

int eliminarClientePorId(ArrayList* clientes, int id)
{
    int returnAux = 0;

    Cliente* clienteAux = newCliente();

    int i=0;
    for(i=0;i<clientes->len(clientes);i++) // Recorre todo el ArrayList de clientes.
    {
        clienteAux = clientes->get(clientes,i);

        if(getIdCliente(clienteAux) == id)
        {
            clientes->remove(clientes, i); // Si se encuentra ese id se elimina el cliente correspondiente.
            returnAux = 1;
            break;
        }
    }

    return returnAux;
}

int finalizarServicioPorId(ArrayList* servicios, int id)
{
    int returnAux = 0;

    Servicio* servicioAux = newServicio();

    int i=0;
    for(i=0; i<servicios->len(servicios); i++) // Recorre todo el ArrayList de servicios.
    {
        servicioAux = servicios->get(servicios,i);

        if(getIdServicio(servicioAux) == id)
        {
            if(getEstado(servicioAux) != 0)
            {
                setEstado(servicioAux, 0);
                returnAux = 1;
            }
            else
            {
                printf("    Error: El servicio ya estaba finalizado previamente.\n");
            }
            break;
        }
    }

    return returnAux;
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
        printf("Ingrese el dni del cliente: ");
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

int pedirIdCliente()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID de la cliente: ");
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

int pedirIdServicio()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el ID del servicio: ");
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

void pedirCodigoProducto(char codigoDeProducto[]) // Esta función pide el codigo y verifica que no tenga más de 5 caracteres.
{
    int flag = 1;
    while(flag)
    {
        printf("Ingrese el codigo del producto: ");
        //fflush(stdin);
        scanf("%s", codigoDeProducto);

        char c;
        int i = -1;
        do
        {
            i++;
            c = codigoDeProducto[i];
        }
        while(c != '\0');

        if(i <= 5)
        {
            flag = 0;
        }
        else
        {
            printf("    Error: El codigo es muy largo, la cantidad de caracteres maxima es 5.\n");
        }
    }
}

void pedirFechaDeIngreso(char fechaDeIngreso[])
{
    printf("Ingrese la fecha de ingreso (DD/MM/YYYY): ");
    //fflush(stdin);
    scanf("%s", fechaDeIngreso);
    printf("\n");
}

float pedirCostoDeReparacion()
{
    float costoDeReparacion;
    
    printf("Ingrese el costo de reparacion: ");
    //fflush(stdin);
    scanf("%f",&costoDeReparacion);

    return costoDeReparacion;
}
