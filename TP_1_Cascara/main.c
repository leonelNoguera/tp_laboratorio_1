#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
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
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        int operandoA, operandoB;
        int banderaOperandoA = 0;
        int banderaOperandoB = 0;

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
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
                printf("El resultado de la suma es: %d", sumar(operandoA, operandoB));
                break;
            case 4:
                printf("El resultado de la resta es: %d", restar(operandoA, operandoB));
                break;
            case 5:
                if(dividir(operandoA, operandoB)[1] >= 1)
                {
                    printf("Error, división por 0(cero).\n");
                }
                else
                {
                    printf("El resultado de la división es: %e", dividir(operandoA, operandoB)[0]);
                }
                break;
            case 6:
                printf("El resultado de la multiplicación es: %d", multiplicar(operandoA, operandoB));
                break;
            case 7:
                printf("El resultado de la factorial es: %d", factorizar(operandoA));
                break;
            case 8:
                printf("El resultado de la suma es: %d", sumar(operandoA, operandoB));
                printf("El resultado de la resta es: %d", restar(operandoA, operandoB));
                if(dividir(operandoA, operandoB)[1] >= 1)
                {
                    printf("Error, división por 0(cero).\n");
                }
                else
                {
                    printf("El resultado de la división es: %e", dividir(operandoA, operandoB)[0]);
                }
                printf("El resultado de la multiplicación es: %d", multiplicar(operandoA, operandoB));
                printf("El resultado de la factorial es: %d", factorizar(operandoA));
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
