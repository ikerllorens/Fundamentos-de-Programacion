#include <stdio.h>

int main(void) 
{
    int n1;
    int n2;
    int resultado;

    resultado = 0;
    printf("main: Dame un número:\n");
    scanf("%d", &n1);
    
    printf("main: Dame un número:\n");
    scanf("%d", &n2);

    printf ("main: La dirección de n1 es %p, y contiene el valor %d\n", &n1, n1);
    printf ("main: La dirección de n2 es %p, y contiene el valor %d\n", &n2, n2);

    resultado = Param_Referencia(&n2, &n1, n1);
    printf ("main: La dirección de n1 es %p, y contiene el valor %d\n", &n1, n1);
    printf ("main: La dirección de n2 es %p, y contiene el valor %d\n", &n2, n2);
    printf ("main: La dirección de resultado en main es %p, contiene el valor %d\n", &resultado, resultado);

    resultado = Param_Valor(n1, n2);
    printf ("main: La dirección de n1 es %p, y contiene el valor %d\n", &n1, n1);
    printf ("main: La dirección de n2 es %p, y contiene el valor %d\n", &n2, n2);
    printf ("main: La dirección de resultado en main es %p, contiene el valor %d\n", &resultado, resultado);
}

int Param_Referencia(int* p1, int* n2, int n1) 
{
    int resultado;
    printf ("Param_Referencia: La dirección de p1 es %p, contiene el valor %p y el contenido del apuntador es: %d\n", &p1, p1, *p1);
    printf ("Param_Referencia: La dirección de n2 es %p, contiene el valor %p y el contenido del apuntador es: %d\n", &n2, n2, *n2);
    printf ("Param_Referencia: La dirección de n1 es %p, contiene el valor: %d\n", &n1, n1);

    *p1 = *p1 + *n2;
    *n2 = *n2 + 10;

    resultado = *n2**n2;
    printf ("Param_Referencia: La dirección de resultado es %p, contiene el valor %d\n", &resultado, resultado);

    return resultado;
}

int Param_Valor(int n1, int n2) 
{
    int resultado = 0;

    printf ("Param_Valor: La dirección de n1 es %p, y contiene el valor %d\n", &n1, n1);
    printf ("Param_Valor: La dirección de n2 es %p, y contiene el valor %d\n", &n2, n2);

    resultado = n1 + n2;

    printf("Param_Valor: La dirección de resultado en Param_Valor es %p, contiene el valor %d\n", &resultado, resultado);

    n1 = -5;
    n2 = -13;

    return resultado;
}