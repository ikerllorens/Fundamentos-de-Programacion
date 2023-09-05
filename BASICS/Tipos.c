#include <stdio.h>


int main(void)
{
	// Void es una palabra reservada, que se puede considerar un "tipo" algunas veces ya que al escribir funciones
	// el valor de retorno es void, pero indica una ausencia de valor, sin embargo es importante
	// recalcar que NO puede existir una variable tipo void, ya que indica ausencia de un valor.
	
	int Entero = 13;
	char Carater = 'i';
	
	// También conocido como string o cadnea de caracteres
	char[15] UnArregloDeCaracteres = {'H', 'o', 'l', 'a', ' ', 'M', 'u', 'n', 'd', 'o'}; 
	char[15] OtroArreglo = "Hello World!"; // No se puede asignar de esta manera a menos que sea en inicialización de variable
	
	float PuntoFlotante = 13.4;
	int* PunteroAEntero = &Entero; // Para más información de punteros, ver los ejercicios de punteros
	int* PunteroLibre = NULL;
	int[5] UnArreglo = {1, 2, 3, 4, 5}; // Un arreglo de memoria, para saber más de arreglos ver los ejercicios de arreglos

	// STUDENTS: Cuanta memoria RAM ocuparemos con este programa?

	// Existen muchos otros tipos en C, incluso nosotros podemos definir nuestro propios tipos.
	typedef int EnterosDeLaSuerte;
	// Definimos una variable tipo EnterosDeLaSuerte que esta basada en int. En este ejemplo no tiene una utilidad
	// mayor que demostrar que se puede definir un tipo y su nombre. Es extremadamente útil para estructuras y listas
	// dinámicas, para más información ver ejemplos.
	EnterosDeLaSuerte unEntero = 13;
	printf("El valor de UnArregloDeCaracteres es \"%s\" y esta almacenado en la dirección: %p \n");
	
	
	return 0;	
}