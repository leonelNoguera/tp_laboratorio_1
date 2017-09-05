/*Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
Ingresar 1er operando (A=x)
Ingresar 2do operando (B=y)
Calcular la suma (A+B)
Calcular la resta (A-B)
Calcular la division (A/B)
Calcular la multiplicacion (A*B)
Calcular el factorial (A!)
Calcular todas las operaciones
Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;

    int operandoA, operandoB;
    int banderaOperandoA = 0;
    int banderaOperandoB = 0;

    while(seguir=='s')
    {
        if(banderaOperandoA == 1)
        {
            printf("1- Ingresar 1er operando (A=%d)\n", operandoA);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        if(banderaOperandoB == 1)
        {
            printf("2- Ingresar 2do operando (B=%d)\n", operandoB);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                operandoA = ingresarOperando();
                banderaOperandoA = 1;
                break;
            case 2:
                operandoB = ingresarOperando();
                banderaOperandoB = 1;
                break;
            case 3:
                /*if((verificarOperandos(banderaOperandoA, banderaOperandoB, operandoB)[0] == 1) && (verificarOperandos(banderaOperandoA, banderaOperandoB, operandoB)[1] == 1))
                {
                    printf("El resultado de la suma es: %d", sumar(operandoA, operandoB));
                }*/
                if(banderaOperandoA == 1 && banderaOperandoB == 1)
                {
                    printf("El resultado de la suma es: %d", sumar(operandoA, operandoB));
                }
                else
                {
                    printf("Falta algun operando.\n");
                }
                //printf("El resultado de la suma es: %d", sumar(operandoA, operandoB));
                break;
            case 4:
                if(banderaOperandoA == 1 && banderaOperandoB == 1)
                {
                    printf("El resultado de la resta es: %d", restar(operandoA, operandoB));
                }
                else
                {
                    printf("Falta algun operando.\n");
                }
                break;
            case 5:

                if(banderaOperandoA == 1 && banderaOperandoB == 1)
                {
                    if(dividir(operandoA, operandoB)[1] >= 1)
                    {
                        printf("Error, división por 0(cero).\n");
                    }
                    else
                    {
                        printf("El resultado de la división es: %.2f", dividir(operandoA, operandoB)[0]);
                    }
                }
                else
                {
                    printf("Falta algun operando.\n");
                }
                break;
            case 6:
                if(banderaOperandoA == 1 && banderaOperandoB == 1)
                {
                    printf("El resultado de la multiplicación es: %d\n", multiplicar(operandoA, operandoB));
                }
                else
                {
                    printf("Falta algun operando.\n");
                }
                break;
            case 7:
                if(banderaOperandoA == 1)
                {
                    printf("El resultado de la factorial es: %d\n", factorizar(operandoA));
                }
                else
                {
                    printf("Falta el operando.\n");
                }
                break;
            case 8:
                if(banderaOperandoA == 1 && banderaOperandoB == 1)
                {
                    printf("El resultado de la suma es: %d\n", sumar(operandoA, operandoB));
                    printf("El resultado de la resta es: %d\n", restar(operandoA, operandoB));
                    if(dividir(operandoA, operandoB)[1] == 1)
                    {
                        printf("Error, división por 0(cero).\n");
                    }
                    else
                    {
                        printf("El resultado de la división es: %e\n", dividir(operandoA, operandoB)[0]);
                    }
                    printf("El resultado de la multiplicación es: %d\n", multiplicar(operandoA, operandoB));
                    printf("El resultado de la factorial es: %d\n", factorizar(operandoA));
                }
                else
                {
                    printf("Falta algun operando.\n");
                }

                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
