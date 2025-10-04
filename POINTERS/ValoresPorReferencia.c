/**
 * @file ValoresPorReferencia.c
 * @brief Programa que demuestra el paso de parámetros por referencia
 * @author Iker Llorens
 * 
 * Este programa ejemplifica cómo pasar parámetros por referencia usando
 * punteros, permitiendo que una función modifique variables externas.
 */

#include <stdio.h>

void Suma(int a, int b, int *resultado);

/**
 * @brief Función principal del programa
 * 
 * Solicita dos números al usuario, llama a la función Suma pasando
 * el resultado por referencia y muestra el resultado.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
    // Declaración de variables
	int VariableResultado;
	int numero1;
	int numero2;

    printf("Dame un número para sumar.\n");
    scanf("%d", &numero1);

    printf("Dame otro número para sumar.\n");
    scanf("%d", &numero2);

	Suma(numero1, numero2, &VariableResultado);

	return 0;
}

/**
 * @brief Suma dos valores y almacena el resultado por referencia
 * 
 * Esta función recibe dos enteros por valor y un puntero donde
 * almacena el resultado de la suma. Demuestra el paso por referencia.
 * 
 * @param a Primer valor a sumar
 * @param b Segundo valor a sumar
 * @param resultado Puntero donde se almacenará el resultado de la suma
 */
void Suma(int a, int b, int *resultado)
{
	*resultado = a + b;
	a = a + 1;
	b = b + 1;

    // El resultado lo enviamos en el puntero, así que no necesitamos tener un valor ni tipo de retorno.
	return;
}