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
int ingresarOperando()
{
    int operando;
    printf("Ingrese un número entero: ");
    scanf("%d", &operando);
    return operando;
}
int verificarOperandos(int banderaOperandoA, int banderaOperandoB, int operandoA, int operandoB, char operacionUno, char operacionDos, char operacionTres, char operacionCuatro, char operacionCinco)
{
    // bandera op1, op2, op1, op2, ope1(s), ope2(r), ope3(d), ope4(m), ope5(f) -- nada(n)

    if(banderaOperandoA == 1 && banderaOperandoB == 1)
    {
        printf("Todos los operandos están asignados.\n");
        if(operacionTres == 'd')
        {
            if(operandoB == 0)
            {
                printf("Advertencia: No se puede dividir por 0(cero).\n");
            }
        }
        if(operacionCinco == 'f')
        {
            if(operandoA < 0)
            {
                printf("Advertencia: No se puede factorizar un número negativo.\n");
            }
        }
    }
    else
    {
        printf("Falta algún operando.\n");
    }

    int estadoOperandos = 0;
    return estadoOperandos;
}

