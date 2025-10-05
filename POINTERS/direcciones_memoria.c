/**
 * <file>direcciones_memoria.c</file>
 * <brief>Programa que demuestra direcciones de memoria y paso por valor vs referencia</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa muestra cómo las variables ocupan direcciones de memoria
 * y la diferencia entre pasar parámetros por valor y por referencia.
 */

#include <stdio.h>

int Param_Referencia(int* p1, int* n2, int n1);
int Param_Valor(int n1, int n2);

/**
 * <brief>Función principal del programa</brief>
 * 
 * Solicita dos números al usuario y demuestra la diferencia entre
 * paso por valor y paso por referencia, mostrando direcciones de memoria.
 * 
 * <return>0 si el programa se ejecutó correctamente</return>
 */
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

/**
 * <brief>Función que recibe parámetros por referencia (punteros)</brief>
 * 
 * Demuestra cómo modificar valores externos usando punteros.
 * Muestra las direcciones de memoria de los parámetros.
 * 
 * <param name="p1">Puntero al primer entero (por referencia)</param>
 * <param name="n2">Puntero al segundo entero (por referencia)</param>
 * <param name="n1">Tercer entero (por valor)</param>
 * <return>El cuadrado de n2</return>
 */
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

/**
 * <brief>Función que recibe parámetros por valor</brief>
 * 
 * Demuestra que modificar parámetros por valor no afecta las variables
 * originales. Muestra las direcciones de memoria locales.
 * 
 * <param name="n1">Primer entero (copia local)</param>
 * <param name="n2">Segundo entero (copia local)</param>
 * <return>La suma de n1 y n2</return>
 */
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