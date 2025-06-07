/*
 * Ejemplo de uso de la función putchar() para escribir caracteres individuales
 * putchar() escribe un carácter a la vez hacia la salida estándar (pantalla)
 */

#include <stdio.h>

int main(void)
{
    printf("=== Ejemplo de putchar() ===\n\n");
    
    // Ejemplo 1: Escribir caracteres individuales
    printf("Escribiendo 'Hola' usando putchar():\n");
    putchar('H');
    putchar('o');
    putchar('l');
    putchar('a');
    putchar('\n'); // Salto de línea
    putchar('\n');
    
    // Ejemplo 2: Escribir el abecedario usando un bucle
    printf("El abecedario en mayúsculas:\n");
    for (char letra = 'A'; letra <= 'Z'; letra++)
    {
        putchar(letra);
        putchar(' '); // Espacio entre letras
    }
    putchar('\n');
    putchar('\n');
    
    // Ejemplo 3: Escribir números como caracteres
    printf("Los dígitos del 0 al 9:\n");
    for (int i = 0; i <= 9; i++)
    {
        putchar('0' + i); // Convertir número a carácter
        putchar(' ');
    }
    putchar('\n');
    putchar('\n');
    
    // Ejemplo 4: Crear un patrón usando putchar
    printf("Patrón de asteriscos:\n");
    for (int fila = 1; fila <= 5; fila++)
    {
        for (int col = 1; col <= fila; col++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    putchar('\n');
    
    // Ejemplo 5: Escribir códigos ASCII
    printf("Algunos caracteres especiales (códigos ASCII):\n");
    putchar(65);  // 'A'
    putchar(97);  // 'a'
    putchar(33);  // '!'
    putchar(64);  // '@'
    putchar(35);  // '#'
    putchar('\n');
    putchar('\n');
    
    // Información adicional
    printf("NOTAS SOBRE PUTCHAR:\n");
    printf("- putchar() escribe un carácter a la vez\n");
    printf("- Es más eficiente que printf() para un solo carácter\n");
    printf("- Acepta tanto caracteres ('A') como códigos ASCII (65)\n");
    printf("- Es útil para crear patrones y formatear salida\n");
    
    return 0;
}