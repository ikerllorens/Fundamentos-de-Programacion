#include <stdio.h>

void Suma(int a, int b, int *resultado);

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
 * Función que suma dos valores y almacena
 * @param int a
 * @param int b
 * @param int *resultado
 */
void Suma(int a, int b, int *resultado)
{
	*resultado = a + b;
	a = a + 1;
	b = b + 1;

    // El resultado lo enviamos en el puntero, así que no necesitamos tener un valor ni tipo de retorno.
	return;
}