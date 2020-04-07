#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int suma;
    int resta;
    int mult;
    int div;

    printf("CALCULADORA\n\n");
    printf("Ingrese primer numero: ");
    scanf("%d",&num1);
    printf("Ingrese segundo numero: ");
    scanf("%d",&num2);

    suma=num1+num2;
    resta=num1-num2;
    mult=num1*num2;
    div=num1/num2;

    printf("\nLa suma es: %d",suma);
    printf("\nLa resta es: %d",resta);
    printf("\nLa multiplicacion es: %d",mult);
    printf("\nLa division es: %d",div);


    return 0;
}
