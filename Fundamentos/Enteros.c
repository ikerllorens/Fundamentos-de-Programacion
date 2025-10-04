/**
 * @file Enteros.c
 * @brief Programa que ejemplifica los límites de un entero en ANSI C
 * @author Iker Llorens
 * 
 * Este programa demuestra qué sucede cuando un entero alcanza su límite
 * máximo y experimenta overflow (desbordamiento).
 */

#include <stdio.h>

/**
 * @brief Función principal del programa
 * 
 * Incrementa un entero en un ciclo hasta que experimenta overflow
 * y se vuelve negativo, demostrando los límites del tipo int.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
	// Decalración de variables
    int Entero = 0;
	
	// Mientras que entero sea mayor o igual a 0, ejecuta lo que está entre llavaes
	// Para más información acerca de ciclos e instrucciones de control ver los ejemplos de ciclos e instrucciones 
	// de control ver la sección correspondiente.
    while (Entero >= 0)
    {
        Entero += 1;
    }

	// El programa alguna vez alcanzará esto? Si si, que imprimiría?
    printf("El valor de Entero es %d\n", Entero);

    return 0;
}