/*
 * Directivas del Preprocesador
 *
 * Generalmente aqui se declaran las bibloiotecas que utilizamos en el programa. Las bibliotecas pueden ser
 * del sistema (e.g. <stdio.h> <strings.h> <time.h> <math.h>) o bibliotecas que nosotros hayamos creado o paquetes
 * externos (e.g. "funciones.h" "operaciones.h"). Es importante notar que las bibliotecas definidas del sistema se declaran 
 * entre <> mientras que las bibliotecas y directivas definidas por nosotros se declaran entre ""
 *
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
int Resta(int paramtero1, int parametro2);

/*
 * Función Principal
 * 
 * Punto de entrada de nuestro ejecutable. N