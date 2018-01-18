#ifndef __CLIENTE
#define __CLIENTE
struct
{
	int id;
    char nombre[51];
    char apellido[51];
    long int dni;
}typedef Cliente;

int compareCliente(void* pClienteA,void* pClienteB);
void printCliente(Cliente* p);
Cliente* newClienteParam(int id, char nombre[],char apellido[], long int dni);

void setIdCliente(Cliente* cliente, int id);
void setNombre(Cliente* cliente, char nombre[]);
void setApellido(Cliente* cliente, char apellido[]);
void setDni(Cliente* cliente, long int dni);

int getIdCliente(Cliente* cliente);
void getNombre(Cliente* cliente, char nombre[]);
void getApellido(Cliente* cliente, char apellido[]);
long int getDni(Cliente* cliente);

#endif // __CLIENTE
