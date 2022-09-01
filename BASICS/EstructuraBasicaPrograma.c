/*
 * Directivas del Preprocesador
 *
 * Generalmente aqui se declaran las bibloiotecas que utilizamos en el programa. Las bibliotecas pueden ser
 * del sistema (e.g. <stdio.h> <string.h> <time.h> <math.h>) o bibliotecas que nosotros hayamos creado o paquetes
 * externos (e.g. "funciones.h" "operaciones.h"). Es importante notar que las bibliotecas definidas del sistema se declaran 
 * entre <> mientras que las bibliotecas y directivas definidas por nosotros se declaran entre ""
 * En estas directivas se declaran y definen funciones que no están en este archivo, pero son utilizadas.
 */
#include <stdio.h>

/*
 * Declaración de funciones
 *
 * En C, debemos declarar las funciones que utilizamos. Esto, es debido a que al ser un lenguaje con un paradigma
 * estructurado, las líneas de código son compiladas "en orden" por ende, si en nuestra función principal utilizamos la funcion
 * Suma pero no está declarada, C no "conoce" o no tiene la definición de esa función y arrojará un error en compilación.
 * La solución (y es probable que se encuentren algo escrito de esta forma), es escribir el contenido de la función Suma antes
 * de ser utilizada en la función principal. Esto generalmente hace que el código se vuelva más difícil de leer y menos claro.
 * Las buenas prácticas de C recomiendan declarar el nombre de las funciones que vamos a utilizar y definirlas después
 * de la función principal.
 */
int Suma(int parametro1, int parametro2);
int Resta(int parametro1, int valorARestar);

/*
 * Función Principal
 * 
 * Punto de entrada de nuestro ejecutable. La función Main no es diferente a cualquier otra función. Por convención siempre regresa
 * un entero al final, que se utiliza para saber si un programa terminó su sproceso exitosamente o hubo algún error o 
 * salida especial. También Main puede recibir agumentos, así que cuando ejecutamos un programa le podemos dar algún
 * valor de entrada. (Explicado más a detalle en otro ejemplo)
 */
int main(void)
{
	// El sistema operativo ejecutará la función Main al momento que ejecutemos el ejecutable compilado. 
	// Cuando se ejecute ./EstructuraBasicaPrograma.out el sistema operativo llama a esta función y empieza la 
	// ejecución de nuestro programa
	
	/*
	Declaración de variables
	En C debemos declarar nuestras variables que vamos a utilizar, normalmente, debemos de inicializarlas
	también. Las mejores prácticas indican que el las vriables deben ser declaradas al principio de las funciones
	*/
	int numero1 = 0;
	int numero2 = 0;
	//También podemos declarar varias variables en una sola línea
	int numero3=0, numero4=0;
	// Declarando variable sin 
	int OtraVariable;
	
	// Imprimiendo una instrucción para el usuario y esperando la entrada del usuario
	printf("Dame un número para sumar y restar: ");
	scanf("%d", &numero1); // Guardando la entrada en la variable numero1. Un ejemplo de comentario
	
	// Imprimiendo una instrucción para el usuario y esperando la entrada del usuario
	printf("Dame otro número para sumar y restarle al primer número: ");
	scanf("%d", &numero2); // Guardando la entrada en la variable numero1. Un ejemplo de comentario
	
	//Llamando a la función suma y guardando el resultado
	numero3 = Suma(numero1, numero2);
	numero4 = Resta(numero1, numero2);
	
	// Impriminedo el resultado
	printf("El resultado de la suma es %d y el de la resta es %d\n", numero3, numero4);
	
	// Regresamos el código 0 al sistema operativo.
	return 0;	
}

/**
 * Función que toma dos parámetros y devuelve la suma de los dos. La función 
 * hace crea una variable local qen la cual se almacena el resultado y luego es
 * retornado a la función desde la que fue llamada.
 *
 * Es importante notar que la definición de la función es exactamente igual a como
 * fue declarada al principio de la función.
 * 
 * @param int parametro1 Numero a sumar
 * @param int parametro2 El segundo número a sumar
 * @return Entero que representa la suma de los dos valore enviados a la función
 */
int Suma(int parametro1, int parametro2)
{
	// Declarando variables locales de la función
	int resultado = 0;	
	
	// Ejecutando la suma sumando las dos variables de entrada y almacenando el 
	// resultado en la varianle local
	resultado = parametro1 + parametro2;
	
	// Fin de la función y regresamos EL VALOR de la variable resultado
	return resultado;
}


/**
 * Función que resta el valorARestar a parametro1. La función regresa el valor que resulta de la resta
 * Es importante recalcar que parametro1 tiene el miso nombre aquí y en la función Suma, pero son
 * variables diferentes que no tienen nada que ver entre sí, ya que únicamente existen dentro de la
 * ejecución de la función
 * @param int parametro1 Valor del que se va a restar
 * @param int valorARestar Valor que queremos restar a parametro1
 * @return La resta parametro1 - valorARestar
 */
int Resta(int parametro1, int valorARestar)
{
	// También podemos realizar varias instrucciones en una sola línea
	return parametro1 - valorARestar; 
}