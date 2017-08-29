/*Ingresar 1er operando (A=x)
Ingresar 2do operando (B=y)
Calcular la suma (A+B)
Calcular la resta (A-B)
Calcular la division (A/B)
Calcular la multiplicacion (A*B)
Calcular el factorial (A!)
Calcular todas las operaciones
Salir*/
double sumar(double numeroUno, double numeroDos)
{
    double resultado = numeroUno + numeroDos;
    return resultado;
}
double restar(double numeroUno, double numeroDos)
{
    double resultado = numeroUno - numeroDos;
    return resultado;
}
double multiplicar(double numeroUno, double numeroDos)
{
    double resultado = numeroUno * numeroDos;
    return resultado;
}
double dividir(double numeroUno, double numeroDos)
{
    double resultado;
    if(numeroDos != 0)
    {
        resultado = numeroUno / numeroDos;
    }
    else
    {
        printf("Error, división por 0(cero).\n");
    }
    return resultado;
}
double factorizar(double numeroUno, double numeroDos)
{
    double resultado = numeroUno + numeroDos;
    return resultado;
}
float ingresarOperando()
{
    float operando;
    printf("Ingrese un número: ");
    scanf("%f", &operando);
    return operando;
}
