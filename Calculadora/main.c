#include <stdio.h>
#include <stdlib.h>

int suma(int,int);
int resta(int,int);
int multiplicacion(int,int);
float division(int,int);

int main()
{
    int num1;
    int num2;
    int sum;
    int res;
    int mult;
    float div;

    printf("CALCULADORA\n\n");
    printf("Ingrese primer numero: ");
    scanf("%d",&num1);
    printf("Ingrese segundo numero: ");
    scanf("%d",&num2);

    sum=suma(num1,num2);
    res=resta(num1,num2);
    mult=multiplicacion(num1,num2);
    div=division(num1,num2);

    printf("\nLa suma es: %d",sum);
    printf("\nLa resta es: %d",res);
    printf("\nLa multiplicacion es: %d",mult);
    printf("\nLa division es: %.2f",div);


    return 0;
}

int suma(int numero1, int numero2)
{
    int resultado;

    resultado=numero1+numero2;

    return resultado;
}

int resta(int numero1, int numero2)
{
    int resultado;

    resultado=numero1-numero2;

    return resultado;
}

int multiplicacion(int numero1, int numero2)
{
    int resultado;

    resultado=numero1*numero2;

    return resultado;
}

float division(int numero1, int numero2)
{
    float resultado;

    resultado=numero1/numero2;

    return resultado;
}
