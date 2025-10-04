/**
 * @file abecedario_bad.c
 * @brief Ejemplo de código con malas prácticas de programación
 * @author Iker Llorens
 * 
 * Este programa contiene intencionalmente errores y malas prácticas
 * para propósitos educativos. Imprime el abecedario con errores.
 */

#include <stdio.h>

char a1; /**< Variable global (mala práctica) */

void a(void);
void b(void);
void c(char aVar);
char d(void);

/**
 * @brief Función principal del programa
 * 
 * Solicita entrada del usuario e intenta imprimir el abecedario.
 * Contiene errores intencionados para propósitos educativos.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{

    a = d();
    if (a1 == '\0')
    {
        printf("Hasta crees que con el error te voy a decir que hago! :D\n");
        return 0;
    }

    c(a1);
}

/**
 * @brief Intenta imprimir el abecedario en mayúsculas (CON ERROR)
 * 
 * NOTA: Esta función contiene un error intencional - el punto y coma
 * después del for hace que solo imprima la última letra.
 */
void a(void)
{
    int i;
    for (i = 'A'; i <= 'Z'; i++);
    {
        printf("%c\n", i);
    }
}

/**
 * @brief Imprime el abecedario en minúsculas
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
 * @brief Determina qué función llamar según el carácter
 * 
 * Llama a la función a() si aVar es 'M' (mayúsculas)
 * o a la función b() si aVar es 'm' (minúsculas).
 * 
 * @param aVar Carácter que indica mayúsculas ('M') o minúsculas ('m')
 */
void c(char aVar)
{
    if (aVar == 'M')
    {
        a();
    }
    else if (aVar == 'm')
    {
        b();
    }
}

/**
 * @brief Lee la entrada del usuario
 * 
 * Solicita al usuario que ingrese 'M' para mayúsculas o 'm' para minúsculas.
 * 
 * @return El carácter ingresado o '\0' si es inválido
 */
char d(void)
{
    char miProfesorEsElMejor;

    printf("Nunca confíes en una computadora que no puedas aventar por la ventana :) : ");
    miProfesorEsElMejor = getchar();

    if (miProfesorEsElMejor != 'm' && miProfesorEsElMejor != 'M')
    {
        return '\0';
    }

    return miProfesorEsElMejor;
}