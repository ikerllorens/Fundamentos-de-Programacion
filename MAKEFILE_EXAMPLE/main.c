/**
 * @file main.c
 * @brief Programa principal que demuestra el uso de funciones en bibliotecas separadas
 * @author Iker Llorens
 * 
 * Este programa utiliza funciones definidas en archivos separados
 * y compiladas mediante un Makefile.
 */

#include <stdio.h>
#include "biblioteca.h"

/**
 * @brief Función principal del programa
 * 
 * Llama a las funciones suma y resta definidas en archivos separados
 * y muestra los resultados.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
    int res;

    res = suma(2, 3, 5);
    printf("2 + 3 + 5 = %d\n", res);

    res = resta(2, 3);
    printf("2 - 3 = %d\n", res);
}