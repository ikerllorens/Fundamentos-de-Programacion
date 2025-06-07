/*
 * Ejemplo de uso de la función getchar() para leer caracteres individuales
 * getchar() lee un carácter a la vez desde la entrada estándar (teclado)
 */

#include <stdio.h>

int main(void)
{
    char caracter;
    
    printf("=== Ejemplo de getchar() ===\n\n");
    
    // Ejemplo 1: Leer un solo carácter
    printf("Introduce un carácter y presiona Enter: ");
    caracter = getchar();
    printf("El carácter que introdujiste es: '%c'\n", caracter);
    printf("Su código ASCII es: %d\n\n", caracter);
    
    // Limpiar el buffer (consumir el Enter que quedó)
    while (getchar() != '\n');
    
    // Ejemplo 2: Leer caracteres hasta encontrar un punto
    printf("Introduce caracteres (termina con un punto '.'): \n");
    printf("Caracteres introducidos: ");
    
    while ((caracter = getchar()) != '.')
    {
        printf("'%c' ", caracter);
    }
    printf("\n¡Encontré el punto final!\n\n");
    
    // Ejemplo 3: Contador de caracteres
    printf("Introduce una línea de texto (presiona Enter al final):\n");
    int contador = 0;
    
    while ((caracter = getchar()) != '\n')
    {
        contador++;
    }
    
    printf("Tu línea tiene %d caracteres (sin contar el Enter)\n\n", contador);
    
    // Información adicional
    printf("NOTAS SOBRE GETCHAR:\n");
    printf("- getchar() lee un carácter a la vez\n");
    printf("- Devuelve un int, no un char (para manejar EOF)\n");
    printf("- Es útil para leer entrada carácter por carácter\n");
    printf("- Puede quedarse en buffer hasta que presiones Enter\n");
    
    return 0;
}