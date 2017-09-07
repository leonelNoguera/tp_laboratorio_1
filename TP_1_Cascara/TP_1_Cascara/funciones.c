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

    char aux[20];
    //int aux;
    printf("Ingrese un n%cmero entero: ", 163);
    scanf("%s",&aux);
    //scanf("%d",&aux);

    if(atoi(aux))
    {
        /*if(!aux == -999999999)
        {
            operando = atoi(aux);
        }
        else
        {
            printf("\n    Error: El dato ingresado es un n%cmero entero demasiado chico.\n", 163);
        }*/
    }
    /*else
    {
        printf("\n    Error: El dato ingresado no es un n%cmero entero.\n", 163);
        operando = -999999999;
    }*/
    //operando = aux;

    return operando;
}

/*int * ingresarOperandoEntero()
{
    int operando[2];

    char aux[10];
    printf("Ingrese un n%cmero entero: ", 163);
    scanf("%s",aux);

    if(atoi(aux))
    {
        operando[0] = atoi(aux);
    }
    else
    {
        printf("\n    Error: El dato ingresado no es un n%cmero entero.\n", 163);
        operando[1] = 1;
    }

    return operando;
}*/

int verificarOperandos(int banderaOperandoA, int banderaOperandoB, int operandoA, int operandoB, char operacionUno, char operacionDos, char operacionTres, char operacionCuatro, char operacionCinco)
{
    // bandera op1, op2, op1, op2, ope1(s), ope2(r), ope3(d), ope4(m), ope5(f) -- nada(n)

    if(banderaOperandoA == 1 && banderaOperandoB == 1)
    {
        printf("\n    Todos los operandos est%cn asignados.\n", 160);
        if(operacionTres == 'd')
        {
            if(operandoB == 0)
            {
                printf("\n    Advertencia: No se puede dividir por 0(cero).\n");
            }
        }
        if(operacionCinco == 'f')
        {
            if(operandoA < 0)
            {
                printf("\n    Advertencia: No se puede factorizar un n%cmero negativo.\n", 163);
            }
        }
    }
    else
    {
        /*á: 160
        é: 130
        í: 161
        ó: 162
        ú: 163
        Á: 181
        É: 144
        Í: 214
        Ó: 224
        Ú: 23
        ñ: 164
        Ñ: 165*/
        printf("\n    Falta alg%cn operando.\n", 163);
    }

    int estadoOperandos = 0;
    return estadoOperandos;
}

