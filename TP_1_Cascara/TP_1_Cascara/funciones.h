#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED
/** \brief Permite el cálculo de la suma de 2 números enteros.
* \param Recibe un número entero.
* \param Recibe otro número entero.
* \return Retorna el resultado de la suma de los 2 números ingresados.
*/
int sumar(int, int);
/** \brief Permite el cálculo de la resta de 2 números enteros.
* \param Recibe un número entero.
* \param Recibe otro número entero.
* \return Retorna el resultado de la resta de los 2 números ingresados.
*/
int restar(int, int);
/** \brief Permite el cálculo de la multiplicación de 2 números enteros.
* \param Recibe un número entero.
* \param Recibe otro número entero.
* \return Retorna el producto de 2 números ingresados.
*/
int multiplicar(int, int);
/** \brief Permite el cálculo de la división de 2 números enteros.
* \param Recibe un número entero que será el dividendo.
* \param Recibe otro número entero que será el divisor.
* \return Retorna un vector tipo float de 2 elementos en el cual el primero es el cociente de los 2 números ingresados y el segundo es una bandera que vale 0 si el dividor es distinto de 0 y vale 1 si el dividor es igual a 0.
*/
float dividir(int, int);
/** \brief Permite el cálculo del factorial de un número.
* \param Recibe un número entero.
* \return Retorna el factorial del número ingresado.
*/
long long int factorizar(int);
/** \brief Permite ingresar un número con scanf().
* \return Retorna el número ingresado.
*/
int ingresarOperandoEntero();
//int * ingresarOperandoEntero();
int verificarOperandos(int, int, int, int, char, char, char, char, char);
