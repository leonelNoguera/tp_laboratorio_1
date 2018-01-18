#ifndef __SERVICIO
#define __SERVICIO
struct
{
	int id;
    int id_cliente;
    char codigoDeProducto[51];
    char fechaDeIngreso[51];
    float costoDeReparacion;
    int estado;
}typedef Servicio;

//int compareServicio(void* pServicio,void* pServicio);
void printServicio(Servicio* p);
Servicio* newServicioParam(int id, int id_cliente, char codigoDeProducto[], char fechaDeIngreso[], float costoDeReparacion);

void setIdServicio(Servicio* servicio, int id);
void setId_cliente(Servicio* servicio, int id_cliente);
void setCodigoDeProducto(Servicio* servicio, char codigoDeProducto[]);
void setFechaDeIngreso(Servicio* servicio, char fechaDeIngreso[]);
void setCostoDeReparacion(Servicio* servicio, float costoDeReparacion);
int getIdServicio(Servicio* servicio);
void getCodigoDeProducto(Servicio* servicio, char codigoDeProducto[]);
void getFechaDeIngreso(Servicio* servicio, char fechaDeIngreso[]);
float getCostoDeReparacion(Servicio* servicio);

#endif // __SERVICIO

