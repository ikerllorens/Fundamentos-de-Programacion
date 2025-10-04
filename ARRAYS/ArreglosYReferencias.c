/**
 * @file ArreglosYReferencias.c
 * @brief Programa que demuestra la relación entre arreglos y punteros
 * @author Iker Llorens
 * 
 * Este programa ejemplifica cómo los arreglos son tratados como punteros
 * y cómo se puede usar un puntero para acceder a elementos de un arreglo.
 */

#include <stdio.h>

void LlenarArreglo();

/**
 * @brief Función principal del programa
 * 
 * Demuestra que un arreglo puede ser asignado a un puntero y que
 * ambos comparten la misma dirección de memoria.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
	// Este es un apuntador o puntero, para más información acerca de punteros ver los ejemplos de apuntadores
	int *UnaReferencia;
	int UnArreglo[10];
	
	UnaReferencia = UnArreglo;
	UnaReferencia[0]=55;
	
	
}

