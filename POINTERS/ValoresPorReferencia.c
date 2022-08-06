#include <stdio.h>

void Suma(int a, int b, int *resultado);

int main(void)
{
	int VariableResultado;
	int numero1;
	int numero2;

	Suma(numero1, numero2, &VariableResultado);

	return 0;
}

void Suma(int a, int b, int *resultado)
{
	*resultado = a + b;
	a = a + 1;
	b = b + 1;

	return;
}