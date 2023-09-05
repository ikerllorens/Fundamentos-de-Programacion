#include <stdio.h>

int main(void)
{
	/* 
	* Un arreglo es una serie de localidades de memoria reservadas por el sistema operativo (generalmente las localidades
	* son contiguas). Su utilidad principal es poder almacenar varios datos del mismo tipo dentro de la misma "variable",
	* propiamente, con una misma referencia. Esto nos permite enviar varios datos con una sola referencia, y podemos 
	* obtener los datos en una determinada posición. Los arreglos por definición tienen un tamaño fijo y no se puede 
	* modificar dicho tamaño. 
	*/
	
	int UnArreglo[10]; // Inicializamos un arreglo. 
	int i;
	
	// Siempre, la posición de un arreglo empieza desde el 0, no desde el 1. por ejemplo, en el arreglo UnArreglo, habrá 
	// valores en las posiciones 0 a la 9, la posición 10 no existe ya que sería la 11va del arreglo, pero definimos un
	// arreglo de 10 posiciones, si intentamos acceder a la posición 10, el programa "crashearía" o en un lenguaje más
	// elegante, tendría un error de ejecución (runtime error), que es un error que no se detecta en la compilación
	// sino hasta la ejecución del programa. 
	
	// Asignemos el valor 13 a la posición 0. Nota como 
	UnArreglo[0] = 13;
	
	// Imprimamos todos los valores, veremos que el primer valor es 13. Para más información sobre ciclos y
	// control de programa ver los ejemplos correspondientes
	for (i = 0; i < 10; i++)
	{
		printf("El valor de la posición %d es %d \n",h i, UnArreglo[i]);
	}
	
	// Ahora hagamos la tabla de multiplicar del 13.
	for (i=0; i < 10; i++)
	{
		UnArreglo[i] = 13 * i;
	}
	
	
	// malloc?
	
	
	
}
