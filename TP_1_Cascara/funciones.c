/*Ingresar 1er operando (A=x)
Ingresar 2do operando (B=y)
Calcular la suma (A+B)
Calcular la resta (A-B)
Calcular la division (A/B)
Calcular la multiplicacion (A*B)
Calcular el factorial (A!)
Calcular todas las operaciones
Salir*/
#include "funciones.h"
int sumar(int numeroUno, int numeroDos)
{
    int resultado = numeroUno + numeroDos;
    return resultado;
}
int restar(int numeroUno, int numeroDos)
{
    int resultado = numeroUno - numeroDos;
    return resultado;
}
int multiplicar(int numeroUno, int numeroDos)
{
    int resultado = numeroUno * numeroDos;
    return resultado;
}
double * dividir(int numeroUno, int numeroDos)
{
    double resultado[2];
    if(numeroDos != 0)
    {
        resultado[0] = numeroUno / numeroDos;
        resultado[1] = 0;
    }
    else
    {
        resultado[1] = 1;
    }
    return resultado;
}
long long int factorizar(int numeroUno)
{
    long long int resultado = 1;
    int i;
    for(i = numeroUno; i > 1; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
int ingresarOperando()
{
    int operando;
    printf("Ingrese un número entero: ");
    scanf("%d", &operando);
    return operando;
}
int * verificarOperandos(int banderaOperandoA, int banderaOperandoB)
{
    double estadoOperandos[3];
    if(banderaOperandoA == 1)
    {
        
    }
    else
    {
        estadoOperandos[1] = 1;
    }
    return estadoOperandos;
}
