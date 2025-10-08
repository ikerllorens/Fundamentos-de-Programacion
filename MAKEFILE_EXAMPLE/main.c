/**
 * <file>main.c</file>
 * <brief>Programa principal que demuestra el uso de funciones en bibliotecas separadas</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa utiliza funciones definidas en archivos separados
 * y compiladas mediante un Makefile.
 */

#include <stdio.h>
#include "biblioteca.h"

/**
 * <brief>Función principal del programa</brief>
 * 
 * Llama a las funciones suma y resta definidas en archivos separados
 * y muestra los resultados.
 * 
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(void)
{
    int res;

    res = suma(2, 3, 5);
    printf("2 + 3 + 5 = %d\n", res);

    res = resta(2, 3);
    printf("2 - 3 = %d\n", res);
}