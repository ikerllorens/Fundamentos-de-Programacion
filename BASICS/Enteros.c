#include <stdio.h>

/*
 * Programa para ejemplificar los límites de un entero en ANSII C
 * El porgrama no tiene parámetros de entrada
 */
int main(void)
{
	// Decalración de variables
    int Entero = 0;
	
	// Mientras que entero sea mayor o igual a 0, ejecuta lo que está entre llavaes
	// Para más información acerca de ciclos e instrucciones de control ver los ejemplos de ciclos e instrucciones 
	// de control
    while (Entero >= 0)
    {
        Entero += 1;
    }

	// El programa alguna vez alcanzará esto? Si si, que imprimiría?
    printf("El valor de Entero es %d\n", Entero);

    return 0;
}