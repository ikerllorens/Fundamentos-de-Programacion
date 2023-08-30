/**
 * @file InversorDeCadenas.c
 * @brief Voltea una cadena  
 * @details Lee una cadena y la invierte.
 *
 * @author
 *  Irving Alejandro
 *  Emilio Roman Sanchez
 * @date Fecha de creacion
 *  21 de Noviembre de 2020
 *
 * @author Desarrollador que realizo la ultima modificacion
 *  Irving Alejandro
 * @date Fecha de ultima modificacion 
 *  21 de Noviembre de 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   @brief Prototipos de funcion*/
void mostrarInstrucciones(char [], char []);
void limpiarEntradaDatos(void);
char *voltearCadena(char []);
 


/**
 * @fn Funcion del programa principal
 * @return Entero: Si muestra un valor 0 nuestro programa se esta ejecutando correctamente
*/

int main(int argc, char *argv[]){
  int i=0;    
 	mostrarInstrucciones("Emilio Roman Sanchez", "Programa que invierte los argumentos de entrada");
  	limpiarEntradaDatos();

	for(i=1; i < argc; i++) 
	  {
	    printf("Tu cadena invertida es: %s \n\n", voltearCadena(argv[i]));
	  }
   
  
  return 0;
}

/**
 *@fn Procedimientos Muestra las instrucciones del programa.
 */

  void mostrarInstrucciones(char autores[],char instrucciones[])
  {
    
    system("clear");
    
    printf("\n\n\n\n\tAplicacion desarrollada por:\n");
    printf("\t\t%s\n\n", autores);
    printf("\tDescripcion del programa:\n");
    printf("\t\t%s\n\n", instrucciones);
    printf("\tPresiona la tecla \"enter\" para continuar.");

    getchar();

    system("clear");

    return;
    
  }

/**
 *@fn Procedimiento para limpiar el buffer de entrada
 */

void limpiarEntradaDatos(void)
  {
    int limpiar;
	
	while((limpiar = getchar()) != '\n' && limpiar != EOF) { 
	}
	
	return;
  }
  
  /**
 *@fn Funcion que convierte celcius a faherenheit
 *@param x numero real.
 */

  char *voltearCadena(char argv[])
{
	
  	int longitud = strlen(argv);
  	char temporal;
  	
    for (int i = 0, j = longitud - 1; i < (longitud / 2);
  		i++, j--) {
    	temporal = argv[i];
    	argv[i] = argv[j];
    	argv[j] = temporal;
  	}
  	return argv;    
  }
  
  
