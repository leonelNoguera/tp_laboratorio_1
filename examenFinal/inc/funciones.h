#include "Cliente.h"
#include "Servicio.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void agregarCliente(ArrayList* clientes);
void pedirNombre(char nombre[]);
void pedirApellido(char apellido[]);
int pedirDni();
void mostrarClientes(ArrayList* clientes);
int buscarPorDni(int dni, ArrayList* this);
int pedirIdCliente();
int pedirIdServicio();
float pedirCostoDeReparacion();
void generarInformeServicios(ArrayList* servicios);
void modificarCliente(ArrayList* clientes);
void guardarClientePorId(ArrayList* clientes, Cliente* cliente, int id);
Cliente* buscarClientePorId(ArrayList* clientes, int id);
Servicio* buscarServicioPorId(ArrayList* servicios, int id);
void guardarClientePorId(ArrayList* clientes, Cliente* cliente, int id);

#endif // FUNCIONES_H_INCLUDED
