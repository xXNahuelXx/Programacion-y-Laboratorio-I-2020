#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Functions.h"


void menu()
{
    float num1;
    float num2;
    int opcion;
    int sum;
    int res;
    int mult;
    float div;
    int fact1;
    int fact2;
    int auxInt;

    printf("CALCULADORA\n\n");

    do
    {

        printf("MENU DE OPCIONES\n\n");
        printf("(1). Ingresar 1er operando (A=%.2f)\n",num1);
        printf("(2). Ingresar 2do operando (B=%.2f)\n",num2);
        printf("(3). Calcular todas las operaciones\n");
        printf("(4). Informar resultados\n");
        printf("(5). Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            num1=pedirNumero("Eligio opcion (1)\nIngrese un numero: ");
            break;
        case 2:
            system("cls");
            num2=pedirNumero("Eligio opcion (2)\nIngrese un numero: ");
            break;
        case 3:
            printf("\nEligio opcion (3)\n");
            printf("a)Calcular la suma (%.2f+%.2f)",num1,num2);
            sum=suma(num1,num2);
            printf("\nb)Calcular la resta (%.2f-%.2f)",num1,num2);
            res=resta(num1,num2);
            printf("\nc)Calcular la division (%.2f/%.2f)",num1,num2);
            div=division(num1,num2);
            printf("\nd)Calcular la multiplicacion (%.2f*%.2f)",num1,num2);
            mult=multiplicacion(num1,num2);
            printf("\ne)Calcular el factorial de (%d!) y (%d!)\n\n",(int)num1,(int)num2);
            fact1=factorial((int)num1);
            fact2=factorial((int)num2);
            break;
        case 4:
            system("cls");
            informes(num1,num2,sum,res,mult,div,fact1,fact2,"Eligio opcion (4)");
            break;
        case 5:
            break;
        default:
            fflush(stdin);
            if(isdigit(opcion)==0)
            {
                auxInt=isdigit(opcion);
                printf("%d",auxInt);
                printf("\nIngrese una opcion correcta!\n\n");
            }
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);
}

float suma(float numero1,float numero2)
{
    float resultado;

    resultado=numero1+numero2;

    return resultado;
}

float resta(float numero1,float numero2)
{
    float resultado;

    resultado=numero1-numero2;

    return resultado;
}

float multiplicacion(float numero1,float numero2)
{
    float resultado;

    resultado=numero1*numero2;

    return resultado;
}

float division(float numero1,float numero2)
{
    float resultado;

    resultado=numero1/numero2;

    return resultado;
}

unsigned long long int factorial(int numero1)
{
    long unsigned int resultado=1;
    int i;

    if(numero1==0)
    {
        resultado=1;
    }
    else
    {
        for(i=1; i<=numero1; i++)
        {
            resultado=resultado*i;
        }
    }
    return resultado;
}

float pedirNumero(char mensaje[])
{
    float num;
    printf("%s",mensaje);
    scanf("%f",&num);

    return num;
}

void informes(float num1,float num2,float resSum,float resRest,float resMult,float resDiv,int resFact1, int resFact2, char mensaje[])
{

    printf("\n%s",mensaje);
    printf("\na) El resultado de %.2f+%.2f es: %.2f",num1,num2,resSum);
    printf("\nb) El resultado de %.2f-%.2f es: %.2f",num1,num2,resRest);
    printf("\nc) El resultado de %.2f*%.2f es: %.2f",num1,num2,resMult);
    if(num2==0)
    {
        printf("\nd)No es posible dividir por 0.\nVuelva al menu e ingrese otro numero distinto de cero en la opcion (2)...");
    }
    else
    {
        printf("\nd) El resultado de %.2f/%.2f es: %.2f",num1,num2,resDiv);
    }
    if(num1<0)
    {
        printf("e)\nERROR!...(%d!)-No es posible calcular el factorial de un numero negativo.\nIngrese otro numero en el menu principal.",(int)num1);
    }
    else
    {
        printf("\ne) El factorial de %d! es: %d",(int)num1,resFact1);
    }
    if(num2<0)
    {
        printf("\nERROR!...(%d!)-No es posible calcular el factorial de un numero negativo.\nIngrese otro numero en el menu principal.\n\n\n",(int)num2);
    }
    else
    {
        printf("\n   El factorial de %d! es: %d\n\n",(int)num2,resFact2);
    }

}