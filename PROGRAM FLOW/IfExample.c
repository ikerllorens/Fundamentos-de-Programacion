/**
 * <file>IfExample.c</file>
 * <brief>Programa que ejemplifica el uso de la sentencia if</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa demuestra varios usos de la sentencia if y cómo modifica
 * el flujo del programa. Se recomienda modificar los valores de las variables,
 * introducir diferentes valores durante la ejecución y modificar las condiciones.
 */

#include <stdio.h>

/**
 * <brief>Función principal del programa</brief>
 * 
 * Demuestra diferentes usos de la sentencia if: condiciones simples,
 * operadores de comparación, operadores lógicos y validación de entrada.
 * 
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(void)
{
	// Declaración de variables
	int VariableEjemploA = 13;
	int VariableEjemploB = 0;
	
	// Una de las instrucciones básicas en programación es la sentencia IF (Si ). La sentencia if siempre (en todos los
	// lenguajes) recibe el resultado de una operación Booleana. Siempre que ese resultado de dicha operación sea verdadera
	// al momento de su evaluación, las sentencias que se encuentren dentro de las llaves {} del if serán ejecutadas, 
	// en caso de que la opreración booleana sea falsa, nada de lo que se encuentra entre las llaves será ejecutado.
		
	// En este if la condición booleana es falsa (false) constantemente, así que el printf no será ejecutado
	if (false)
	{
		// STUDENTS: En que situación podría ser esto útil? 
		VariableEjemploA = 25;
		printf("Esto no será ejecutado nunca!\n");
	}
	printf("El valor de la variable VariableEjemploA debería ser 13 y es: %d\n", VariableEjemploA);
	
	// Lo que sucedió arriba es asignamos la variable VariableEjemploA con un valor de 13, en el if (false) 
	// intentamos asignar el valor 25 a VariableEjemploA pero como ese if no será ejecutado dado que la condición
	// es falsa, el valor nunca cambia
	
	// En este if comparamos si 12 es mayor que 1, operación que es verdadera. Por ende, lo que se encuentra dentro del 
	// if será ejecutado
	if (12 > 1)
	{
		// Aquí nuestra operación es verdadera, por lo que todo lo que está dentro de este if será ejecutado.
		printf("Este bloque de código si se ejecutará.");
		VariableEjemploA = 94;	
	}
	printf("El valor de la variable VariableEjemploA debería ser 94 y es: %d\n", VariableEjemploA);
	// Como el contenido del if fue ejecutado, el valor de nuestra variable cambió.
	
	// Haremos un ejemplo en el que no conocemos si el if será ejecutdo o no, ya que el usuario podría cualquier entrada.
	// Por ejemplo, podríamos validar la entrada del usuario
	printf("Ingresa un valor y te diré si es mayor a 10\n");
	scanf("%d", &VariableEjemploB);
	if (VariableEjemploB > 10)
	{
		printf("El valor introducido es mayor a 10\n");
	}
	
	// Revisando que VariableEjemploB sea mayor que VariableEjemploA Y (&&) que VariableEjemploB sea menor que 100. En esta 
	// operación booleana, las comparaciones se ejecutan y se obtienen los resultados y sobre dichos resultados booleanos, 
	// se ejecutan las operaciones lógicas, el resultado final deteminará si las instrucciones del if deberán ejecutarse.
	if (VariableEjemploB > VariableEjemploA && VariableEjemploB < 100)
	{
		printf("Si el valor introducido es mayor que el valor de VariableEjemploA y menor que 100 esto será impreso\n");
	}
	
	// Otro ejemplo de if con un caso especial
	if (9)
	{
		printf("\nEsto (if (9)) es verdadero para los lenguajes de programación (Aunque algunos no admiten un resultado 
				dentro del if que no sea un resultado booleano)\n");
	}
	
	return 0;
}