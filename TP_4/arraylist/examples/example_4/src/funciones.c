/*funciones.c
Autor: Marcelo Leonel Noguera
08/09/2017*/
#include "funciones.h"
#include "../inc/Employee.h"
#include <string.h>

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

        if((this->contains(this, empleado) == 0) || (this->contains(this, empleado) == -1))
        {
            if(al_add(this, empleado))
            {
                printf("    Error: No se guardo el empleado.\n");
            }
            else
            {
                printf("Guardado.\n");
            }
        }
        else
        {
            printf("    Error: El empleado ya esta registrado.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void borrarEmpleado(ArrayList* this)
{
    if(this != NULL)
    {
        if(this->len(this) > 0)
        {
            mostrarEmpleados();

            int index = ingresarIndexEmpleado();

            if(!this->remove(this, index))
            {
                printf("Eliminado.\n");
            }
            else
            {
                printf("    Error: No se pudo eliminar.\n");
            }
        }
        else
        {
            printf("    Error: No hay empleados.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void modificarempleado(ArrayList* this)
{
    if(this != NULL)
    {
        if(this->len(this) > 0)
        {
            mostrarEmpleados();

            int index = ingresarIndexEmpleado();

            char apellido[40];
            char nombre[20];

            pedirApellido(apellido);
            pedirNombre(nombre);
            float salario = pedirSalario();
            int sector = pedirSector();

            Employee* empleado = newEmployee(0, nombre, apellido, salario, sector);

            if(!this->set(this, index, empleado))
            {
                printf("Modificado.\n");
            }
            else
            {
                printf("    Error: No se pudo modificar.\n");
            }
        }
        else
        {
            printf("    Error: No hay empleados.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

int ingresarIndexEmpleado()
{
    int index;
    char indexIngresado[10];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el index de la empleado: ");
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

void mostrarEmpleados(ArrayList* this)
{
    if(this != NULL)
    {
        if(this->len(this) > 0)
        {
            int i=0;
            for(i=0;i<this->len(this);i++)
            {
                Employee* pAux = this->get(this,i);
                //printf("----Nombre:%s Salario:%.2f\r\n",pAux->name,pAux->salary);
                printf("%d) ",i);
                printEmployee(pAux);
            }
        }
        else
        {
            printf("    Error: No hay empleados.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void guardarEmpleadosEnArchivo(ArrayList* this)
{
    int cantidad = 0;
    int leido;
    FILE * pArchivo;

    Employee* empleado;
    pArchivo = fopen("empleados.bin","wb");
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

void borrarArrayList(ArrayList* this)
{
    if(this != NULL)
    {
        if(!this->deleteArrayList(this))
        {
            printf("Eliminado.\n");
        }
        else
        {
            printf("    Error: No se pudo eliminar.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void borrarEmpleados(ArrayList* this)
{
    if(this != NULL)
    {
        if(!this->clear(this))
        {
            printf("Eliminados.\n");
        }
        else
        {
            printf("    Error: No se pudo eliminar.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void ordenarEmpleados(ArrayList* this)
{
    if(this != NULL)
    {
        int orden = pedirOrden();
        if(!this->sort(this, compareEmployee, orden))
        {
            printf("Ordenados.\n");
        }
        else
        {
            printf("    Error: No se pudo ordenar.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

ArrayList* clonarArrayList(ArrayList* this)
{
    if(this != NULL)
    {
        if(this->clone(this) != NULL)
        {
            printf("Clonado.\n");
        }
        else
        {
            printf("    Error: No se pudo clonar.\n");
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void compararArrayList(ArrayList* this, ArrayList* this2)
{
    if((this != NULL) && (this2 != NULL))
    {
        if(this->al_containsAll(this, this2) == 1)
        {
            printf("Son iguales.\n");
        }
        else
        {
            if(!this->al_containsAll(this, this2))
            {
                printf("No son iguales.\n");
            }
            else
            {
                printf("    Error: No se pudo comparar.\n");    
            }
        }
    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

void insertarEmpleado(ArrayList* this)
{
    if(this != NULL)
    {
        char apellido[40];
        char nombre[20];

        pedirApellido(apellido);
        pedirNombre(nombre);
        float salario = pedirSalario();
        int sector = pedirSector();

        int index = pedirIndice();

        Employee* empleado = newEmployee(0, nombre, apellido, salario, sector);

        if((this->contains(this, empleado) == 0) || (this->contains(this, empleado) == -1))
        {
            if(!this->push(this, index, empleado))
            {
                printf("    Error: No se guardo el empleado.\n");
            }
            else
            {
                printf("Guardado.\n");
            }
        }
        else
        {
            printf("    Error: El empleado ya esta registrado.\n");
        }

    }
    else
    {
        printf("    Error: ArrayList = NULL.\n");
    }
}

/*int buscarempleadoPorapellido(char apellido[])
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

int pedirOrden()
{
    int orden;
    char ordenIngresado[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el orden (0 - 1): ");
        fflush(stdin);
        scanf("%s",&ordenIngresado);
        orden = atoi(ordenIngresado);

        if(orden > 0)
        {
            flag = 1;
        }
        else
        {
            if(!(strcmp(ordenIngresado, "0")))
            {
                flag = 1;
            }
            else
            {
                printf("    Error: N%cmero no v%clido.\n", 163, 160);
            }
        }
    }
    return orden;
}

int pedirIndice()
{
    int indice;
    char indiceIngresado[4];
    int flag = 0;

    while(!flag)
    {
        printf("Ingrese el indice (0 - 1): ");
        fflush(stdin);
        scanf("%s",&indiceIngresado);
        indice = atoi(indiceIngresado);

        if(indice > 0)
        {
            flag = 1;
        }
        else
        {
            if(!(strcmp(indiceIngresado, "0")))
            {
                flag = 1;
            }
            else
            {
                printf("    Error: N%cmero no v%clido.\n", 163, 160);
            }
        }
    }
    return indice;
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
