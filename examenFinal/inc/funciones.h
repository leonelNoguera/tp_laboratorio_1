#include "Empleado.h"
#include "Registro.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void agregarEmpleado(ArrayList* empleados);
void pedirNombre(char nombre[]);
void pedirApellido(char apellido[]);
int pedirDni();
void mostrarEmpleados(ArrayList* empleados);
int buscarPorDni(int dni, ArrayList* this);
int pedirIdEmpleado();
int pedirIdRegistro();
float obtenerPrecioUnitario(int cantidadDeHoras);
void generarInformeRegistros(ArrayList* registros);
void modificarEmpleado(ArrayList* empleados);
void guardarEmpleadoPorId(ArrayList* empleados, Empleado* empleado, int id);
Empleado* buscarEmpleadoPorId(ArrayList* empleados, int id);
Registro* buscarRegistroPorId(ArrayList* registros, int id);
void guardarEmpleadoPorId(ArrayList* empleados, Empleado* empleado, int id);

#endif // FUNCIONES_H_INCLUDED
