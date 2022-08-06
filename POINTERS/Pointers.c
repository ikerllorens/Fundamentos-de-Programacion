#include <stdio.h>

int main(void)
{
	/*
	 * Los apuntadores se declaran con un asterisco antes del nombre del apuntador, Aunque tienen el tipo del apuntador
	 * antes de su nombre, no son ese tipo, sino un apuntador a una dirección de memoria que contiene un valor de ese
	 * tipo. El apuntador en si almacena una DIRECCIÓn de memoria. 
	 */
	int *UnApuntador;
	int *OtroApuntador;
	int UnaVariable;
	
	UnaVariable = 13;
	// UnApuntador = 13; //Esto no es válido, si se quita el comentario, ocurre un error de compilación
	
	/*
	 * El operando & en C (no confundir con la operación binaria de && para condiciones) se utiliza para referirse a la
	 * dirección de una variable cuando se antepone al nombre de una variable (incluidos los punteros, el puntero en si
	 * ocupa una dirección de memoria). Por eso, podríamos guardar la dirección de una variable en un puntero.
	 */
	UnApuntador = &UnaVariable; // Aquí guardamos la dirección de UnaVariable en el puntero UnApuntador, 
	
	printf("El apuntador UnApuntador %x apunta a la direccón de UnaVariable que se encuentra en %x\n", UnApuntador, &UnaVariable );
	
	// Podemos asignar la referencia de un apuntador a otro que sea un apuntador al mismo tipo
	OtroApuntador = UnApuntador;
	
	// Hagamos algunas comprobaciones
	if (OtroApuntador == UnApuntador)
	{
		printf("Nuestros dos apuntadores apuntan al mismo lugar! \n");
	}
	
	if (OtroApuntador == &UnaVariable)
	{
		printf("La dirección de memoria a la que apunta OtroApuntador es la dirección de la variable UnaVariable\n");
	}
	
	/*
	 * Una gran utilidad de los apuntadores es que podemos acceder al valor contenido en la dirección a la que apuntan,
	 * es decir, el contenido del apuntador o dicho de otra forma, el contenido de la dirección de memoria a la cual apunta
	 * el apuntador.
	 */
	
	printf("El contenido del apuntador UnApuntador en la dirección %x es %d\n", UnApuntador, *UnApuntador);
	
	if (*UnApuntador == *OtroApuntador)
	{
		printf("El contenido de los apuntadores es el mismo! \n");
	}
	
	return 0;
	
}
