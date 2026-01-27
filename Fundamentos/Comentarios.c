/**
 * <file>Comentarios.c</file>
 * <brief>Programa que ejemplifica diferentes tipos de comentarios y documentación en C</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa demuestra los diferentes estilos de comentarios en C y la importancia
 * de la documentación estandarizada. Es importante notar que cada programador, empresa,
 * organización, o profesor tienen un estilo de documentación. Lo más importante no es
 * pelear cual es mejor, sino adaptarse al estilo. Varios lenguajes tienen herramientas
 * que requieren de documentación estandarizada (con un formato específico) para ayudar
 * al desarrollador a navegar el código más fácilmente.
 * 
 * Entradas: Ninguna
 * Salidas: Imprime el resultado de operaciones matemáticas
 */

#include <stdio.h>

// Declaración de funciones
int Cuadrado(int parametro);

/**
 * <brief>Función principal del programa</brief>
 * 
 * Demuestra el uso de diferentes tipos de comentarios en C y llama a funciones
 * para realizar operaciones matemáticas básicas.
 * 
 * <return>0 si el programa se ejecutó correctamente</return>
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
 * <brief>Calcula el cuadrado de un número entero</brief>
 * 
 * Descripción del funcionamiento de la función. Es importante hacer que quien lea nuestro código
 * pueda entender la funcionalidad de la función con esta descripción sin tener que descifrar el código.
 * Esta función toma un entero y devuelve su cuadrado.
 * 
 * <param name="parametro">El número entero a elevar al cuadrado</param>
 * <return>El cuadrado del parámetro parametro (parametro * parametro)</return>
 */
int Cuadrado(int parametro)
{
	return parametro * parametro;
}

/**
 * <brief>Calcula la suma de dos números enteros</brief>
 * 
 * Esta función toma dos enteros como parámetros y devuelve su suma.
 * 
 * <param name="a">El primer número entero a sumar</param>
 * <param name="b">El segundo número entero a sumar</param>
 * <return>La suma de a y b</return>
 */
int Suma(int a, int b)
{
	return a + b;
}