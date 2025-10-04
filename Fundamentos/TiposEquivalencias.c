/**
 * @file TiposEquivalencias.c
 * @brief Programa que ejemplifica las equivalencias del tipo char
 * @author Iker Llorens
 * 
 * Este programa demuestra cómo los caracteres pueden ser tratados como
 * números y las equivalencias entre valores ASCII, decimales y hexadecimales.
 */

#include <stdio.h>

/**
 * @brief Función principal del programa
 * 
 * Demuestra operaciones aritméticas con caracteres y conversiones
 * entre representaciones decimal, hexadecimal y ASCII.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
	char UnCaracter = 'a';
	char OtroCaracter = 'A';
	
	char UnCaracterInt = 57;
	char UnCaracterHex = 0x4c;
	
	// Para más ejemplos de if, ver los ejemplos de Instrucciones de Control
	// En esta comparación, comprobamos que podemos operar un caracter como si fuera un número, en realidad
	// el caracter almacena un byte que corresponde a un valor de la tabla ASCII. (ver https://asciitable.com para
	// ver la tabla completa)
	if (UnCaracter - 32 == OtroCaracter)
	{
		printf("Si esto se imprime, significa que si restamos 32 al caracter %c obtendremos el caracter %c\n", 
			UnCaracter, OtroCaracter);
	}
	
	
	printf("En el código asignamos el hexadecimal 0x4c a la variable UnCaracterHex y el caracter almacenado es: %c\n", UnCaracterHex);
	
	printf("En el código asignamos el decimal 57 a la variable UnCaracterHex y el caracter almacenado es: %c\n", UnCaracterInt);
	
}