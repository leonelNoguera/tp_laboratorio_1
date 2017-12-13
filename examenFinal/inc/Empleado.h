#ifndef __EMPLEADO
#define __EMPLEADO
struct
{
	int id;
    char nombre[51];
    char apellido[51];
    int dni;
}typedef Empleado;

int compareEmpleado(void* pEmpleadoA,void* pEmpleadoB);
void printEmpleado(Empleado* p);
Empleado* newEmpleadoParam(int id, char nombre[],char apellido[], int dni);

void setIdEmpleado(Empleado* empleado, int id);
void setNombre(Empleado* empleado, char nombre[]);
void setApellido(Empleado* empleado, char apellido[]);
void setDni(Empleado* empleado, int dni);

int getIdEmpleado(Empleado* empleado);
void getNombre(Empleado* empleado, char nombre[]);
void getApellido(Empleado* empleado, char apellido[]);
int getDni(Empleado* empleado);

#endif // __EMPLEADO
