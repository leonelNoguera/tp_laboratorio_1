#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/**
 *  \brief Agrega una pelicula al archivo binario
 */
void agregarEmpleado(ArrayList* this);

/**
 * \brief Pide que se ingrese el puntaje y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int pedirSector();

/**
 * \brief Pide que se ingrese el puntaje y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
float pedirSalario();

/**
 * \brief Pide que se ingrese el puntaje y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int pedirOrden();
/**
 * \brief Pide que se ingrese el puntaje y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int ingresarIndexEmpleado();

void borrarArrayList(ArrayList* this);
void borrarArrayList(ArrayList* this);
ArrayList* clonarArrayList(ArrayList* this);
void insertarEmpleado(ArrayList* this);
int pedirIndice();
Employee* quitarEmpleado(ArrayList* this);
/**
 * \brief Pide los datos necesarios para guardar una pelicula en el archivo binario.
 * \param this
 */
void guardarEmpleadosEnArchivo(ArrayList* this);

#endif // FUNCIONES_H_INCLUDED