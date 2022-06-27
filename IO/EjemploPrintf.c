/*
 *
 *
 */
#include <stdio.h>

int main(void)
{
	int UnEntero = 13;
	int OtroEntero = 23;
	char UnCaracter = 'i';
	float UnNumeroFlotante = 13.4;
	char[] UnaCadena = "foo"; // Para más información sobre cadenas busca el ejemplo de cadenas dentro del repositorio :)
	
	// Imprimimos una cadena de caracteres (string) a la consola
	printf("Hola Mundo! ");
	// 
	printf("Esto también es una cadena de caracteres :) 2022, 34,4\n");

	/* Para imprimir un valor de alguna variable, printf es una función muy útil para esto, pero en C
	la sintaxis puede ser un poco confusa. Al momento de imprimir una variable el programador debe especificar
	el formato (en otras palabras, una plantilla) en la que forma en la que se desea imprimir el valor de la variable.
	*/
	
	// Lo que hacemos aquí es especificar una cadena de caracteres y con el %d especificamos el lugar donde queremos
	// imprimir el valor de la variable. scanf siempre recibe una cadena como primer argmento, y puede recibir n argumentos
	// adicionales dependiendo la cantidad de marcadores (en este caso %d) haya en la cadena enviada como primer 
	// argumento.
	printf("El valor de la variable UnEntero es: %d\n", UnEntero);
	// En este caso, le enviamos dos variables a printf ya que tenemos dos marcadores en nuestra cadena.
	printf("El valor de la variable UnEntero es: %d y el de la variable OtroEntero es: %d", UnEntero, OtroEntero);
	
	
	return 0;
}