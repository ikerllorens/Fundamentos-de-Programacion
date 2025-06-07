/*
 * Ejemplo de uso de la función scanf() para recibir datos del usuario
 * scanf() es muy útil para leer entradas del usuario desde el teclado
 */

#include <stdio.h>

int main(void)
{
    // Declaración de variables para almacenar diferentes tipos de datos
    int numero_entero;
    float numero_flotante;
    char caracter;
    char cadena[50];
    
    // Ejemplo 1: Leer un número entero
    printf("Introduce un número entero: ");
    scanf("%d", &numero_entero);
    printf("El número entero que introdujiste es: %d\n\n", numero_entero);
    
    // Ejemplo 2: Leer un número flotante (decimal)
    printf("Introduce un número decimal: ");
    scanf("%f", &numero_flotante);
    printf("El número decimal que introdujiste es: %.2f\n\n", numero_flotante);
    
    // Ejemplo 3: Leer un carácter
    printf("Introduce un carácter: ");
    scanf(" %c", &caracter); // Nota el espacio antes de %c para ignorar espacios en blanco
    printf("El carácter que introdujiste es: %c\n\n", caracter);
    
    // Ejemplo 4: Leer una cadena de caracteres (sin espacios)
    printf("Introduce una palabra (sin espacios): ");
    scanf("%s", cadena); // No necesita & para cadenas
    printf("La palabra que introdujiste es: %s\n\n", cadena);
    
    // Ejemplo 5: Leer múltiples valores en una sola línea
    int a, b;
    printf("Introduce dos números separados por espacio: ");
    scanf("%d %d", &a, &b);
    printf("Los números que introdujiste son: %d y %d\n", a, b);
    printf("Su suma es: %d\n\n", a + b);
    
    // Notas importantes sobre scanf:
    printf("NOTAS IMPORTANTES SOBRE SCANF:\n");
    printf("1. Siempre usa & antes de las variables (excepto para cadenas)\n");
    printf("2. El formato %%d es para enteros, %%f para flotantes, %%c para caracteres\n");
    printf("3. scanf puede ser problemático con espacios y caracteres especiales\n");
    printf("4. Para uso más avanzado, considera usar fgets() para cadenas\n");
    
    return 0;
}