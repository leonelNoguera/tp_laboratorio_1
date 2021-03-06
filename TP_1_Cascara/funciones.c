/* funciones.c
Autor: Marcelo Leonel Noguera*/
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
float dividir(int numeroUno, int numeroDos)
{
    float resultado;
    if(numeroDos != 0)
    {
        resultado = (numeroUno + 0.0) / numeroDos;
    }
    return resultado;
}
long long int factorizar(int numeroUno)
{
    long long int resultado;
    if(numeroUno == 0)
    {
        resultado = 1;
    }
    int i;
    for(i = numeroUno; i > 1; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
int ingresarOperandoEntero()
{
    int operando;
    printf("Ingrese un n%cmero entero: ", 163);
    scanf("%d",&operando);

    return operando;
}
void verificarOperandos(int banderaOperandoA, int banderaOperandoB, int operandoA, int operandoB, char operacionUno, char operacionDos)
{
    if(banderaOperandoA == 1 && banderaOperandoB == 1)
    {
        printf("\n    Todos los operandos est%cn asignados.\n", 160);
        if(operacionUno == 'd')
        {
            if(operandoB == 0)
            {
                printf("\n    Advertencia: No se puede dividir por 0(cero).\n");
            }
        }
        if(operacionDos == 'f')
        {
            if(operandoA < 0)
            {
                printf("\n    Advertencia: No se puede factorizar un n%cmero negativo.\n", 163);
            }
        }
    }
    else
    {
        printf("\n    Falta alg%cn operando.\n", 163);
    }
}