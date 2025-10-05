/**
 * <file>Abecedario.c</file>
 * <brief>Programa que imprime el abecedario en mayúsculas o minúsculas</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa solicita al usuario si desea ver el abecedario en
 * mayúsculas o minúsculas e imprime la secuencia correspondiente.
 */

#include <stdio.h>

void a(void);
void b(void);
void c(char Mayuscula);
char d(void);

/**
 * <brief>Función principal del programa</brief>
 * 
 * Solicita al usuario su elección y muestra el abecedario correspondiente.
 * 
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(void)
{
    char letra;

    letra = d();
    if (letra == '\0')
    {
        printf("Introdujiste un valor inválido. Adiós!\n");
        return 0;
    }

    c(letra);
}

/**
 * <brief>Imprime el abecedario en mayúsculas</brief>
 * 
 * Imprime todas las letras del alfabeto desde A hasta Z,
 * cada una en una línea separada.
 */
void a(void)
{
    int i;
    for (i = 'A'; i <= 'Z'; i++)
    {
        printf("%c\n", i);
    }
}

/**
 * <brief>Imprime el abecedario en minúsculas</brief>
 * 
 * Imprime todas las letras del alfabeto desde a hasta z,
 * cada una en una línea separada.
 */
void b(void)
{
    int i;
    for (i = 'a'; i <= 'z'; i++)
    {
        printf("%c\n", i);
    }
}

/**
 * <brief>Selecciona e imprime el abecedario según la opción</brief>
 * 
 * Llama a la función a() si la opción es 'M' (mayúsculas)
 * o a la función b() si la opción es 'm' (minúsculas).
 * 
 * <param name="opcion">Carácter que indica mayúsculas ('M') o minúsculas ('m')</param>
 */
void c(char opcion)
{
    if (opcion == 'M')
    {
        a();
    }
    else if (opcion == 'm')
    {
        b();
    }
}

/**
 * <brief>Lee la opción del usuario para el tipo de abecedario</brief>
 * 
 * Solicita al usuario que ingrese 'M' para mayúsculas o 'm' para minúsculas.
 * Si el usuario ingresa un valor inválido, retorna '\0'.
 * 
 * <return>'M' para mayúsculas, 'm' para minúsculas, '\0' si es inválido</return>
 */
char d(void)
{
    char charALeer;

    printf("Dime si quieres que imprima el abecedario en mayúscula o minúscula. M para mayúsculas, m para minúsculas: ");
    charALeer = getchar();

    if (charALeer != 'm' && charALeer != 'M')
    {
        return '\0';
    }

    return charALeer;
}