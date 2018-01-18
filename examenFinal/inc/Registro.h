#ifndef __REGISTRO
#define __REGISTRO
struct
{
	int id;
    int id_empleado;
    int codigoDeTrabajo;
    int cantidadDeHoras;
    float precioUnitario;
}typedef Registro;
#endif // __REGISTRO

//int compareRegistro(void* pRegistro,void* pRegistro);
void printRegistro(Registro* p);
Registro* newRegistroParam(int id, int id_empleado, int codigoDeTrabajo, int cantidadDeHoras, float precioUnitario);

void setIdRegistro(Registro* registro, int id);
void setId_empleado(Registro* registro, int id_empleado);
void setCodigoDeTrabajo(Registro* registro, int codigoDeTrabajo);
void setCantidadDeHoras(Registro* registro, int cantidadDeHoras);
void setPrecioUnitario(Registro* registro, float precioUnitario);
int getIdRegistro(Registro* registro);
int getCodigoDeTrabajo(Registro* registro);
int getCantidadDeHoras(Registro* registro);
float getPrecioUnitario(Registro* registro);
