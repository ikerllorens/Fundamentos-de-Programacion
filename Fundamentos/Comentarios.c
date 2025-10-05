#include <stdio.h>

// Declaración de funciones
int Cuadrado(int parametro);

/**
 * © Iker Llorens
 * Descripción del programa y su intención. Es importante notar que cada programador, empresa, organización,
 * profesor tienen un estilo de documentación. Lo más importante no es pelear cual es mejor, sino adaptarse al 
 * estilo. Varios lenguajes tienen herramientas que requieren de documentación estandarizada (con un formato 
 * específico) para ayudar al desarrollador a navegar el código más fácilmente. No visto en esta materia.

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
 * Descripción del funcionamiento de la función. Es importante hacer que quien lea nuestro código
 * pueda entender la funcionalidad de la función con esta descripción sin tener que descifrar el código
 * <param name="int">parametro Descripción del parametro que la función recibe</param>
 * <return>Describir el valor de regreso. DEscribir también casos especiales (TODOS los posibles resultados)</return>

 * Calculates the square of two integers.
 * <param name="p">The first integer.</param>
 *
 * <return>The square of a and b.</return>
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
 * <param name="a">The first integer.</param>
 * <param name="b">The second integer.</param>
 *
 * <return>The sum of a and b.</return>
 *
 * @example
 * int result = Suma(2, 3);
 * // result is now 5
 */
int Suma(int a, int b)
{
	return a + b;
}