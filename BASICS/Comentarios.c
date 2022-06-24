#include <stdio.h>

// Declaración de funciones
int UnaFuncionEspejo(int parametro);

/**
 * © Iker Llorens
 * Descripción del programa y su intención
 */
int main(void)
{
	// Este es un comentario de una sola línea.
	// Se pueden tener varios comentarios de una sola línea :) 
	int a = 2;
	int b = 0;
	
	/*
	Este es un comentario que admite varias líneas de comentarios
	Muy útil para documentar funciones o procesos.
	*/
	b = Cuadrado(a);
	
	// Imprimiendo el resultado
	printf("El resultado es: %d", b);
	
	return 0;
}

/**
 * A brief description. A more elaborate class description
 * @param int parametro 
 * @return 
 */
int Cuadrado(int parametro)
{
	return parametro*parametro;
}