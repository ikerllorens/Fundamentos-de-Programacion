#include <stdio.h>

// Declaración de funciones
int Cuadrado(int parametro);

/**
 * © Iker Llorens
 * Descripción del programa y su intención
 * Entradas:
 * Salidas:
 *
 * Puede ser escrito en inglés o en español
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
 * Calculates the square of two integers.
 * @param p The first integer.
 *
 * @return The square of a and b.
 *
 * @example
 * int result = Cuadrado(2);
 * // result is now 4
 */
int Cuadrado(int p)
{
	return p * p;
}

/**
 * Calculates the sum of two integers.
 * @param a The first integer.
 * @param b The second integer.
 *
 * @return The sum of a and b.
 *
 * @example
 * int result = Suma(2, 3);
 * // result is now 5
 */
int Suma(int a, int b)
{
	return a + b;
}