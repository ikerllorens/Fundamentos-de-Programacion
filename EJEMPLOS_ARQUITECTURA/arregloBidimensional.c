/**
 * @file arregloBidimensional.c
 * @brief Arreglo bidimensional
 * @details Programa que rellena e imprime el contenido de un arreglo bidimensional.
 *
 * @author Desarrolladores del proyecto
 *   Thalía Bravo
 * @date Fecha de creación
 *   23 de noviembre de 2020
 *
 * @author Desarrollador que realizó la última modificación
 *   Thalía Bravo
 * @date Fecha de última modificación
 *   24 de noviembre de 2020
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN_COLUMNAS 3
#define MIN_FILAS 3
#define COLUMNAS 50
#define FILAS 50

/*
 * @brief Prototipos de función
 */
void mostrarInstrucciones(char nombre[], char inst[]);
void limpiarEntradaDatos(void);
int generarNumerosAleatorios(int, int);
int pedirNumero(int, int);
void llenarMatriz(int *, int *, float matriz[FILAS][COLUMNAS]);
void desplegarMatriz(int, int, float matriz[FILAS][COLUMNAS]);

/**
 * @fn Función del programa principal
 * @return Entero: Si muestra un valor 0 nuestro programa, se está ejecutando correctamente.
 */

int main(void)
{
  float matriz[FILAS][COLUMNAS];
  int filas, columnas;

  mostrarInstrucciones("Thalia Bravo", "Programa que muestra el uso de arreglos de dos dimensiones o bidimensionales.");

  llenarMatriz(&filas, &columnas, matriz);

  desplegarMatriz(filas, columnas, matriz);

  return 0;
}

/**
 *@fn Procedimiento Muestra las instrucciones del programa.
 */
void mostrarInstrucciones(char autores[], char instrucciones[])
{
  printf("Aplicación desarrollada por:\n");
  printf("\t%s\n\n", autores);
  printf("Descripción del programa:\n");
  printf("\t%s\n\n", instrucciones);
  printf("Presiona la tecla \"enter\" para continuar.\n");
  getchar();

  system("clear");

  return;
}

/**
 *@fn Procedimiento que limpia el buffer de entrada.
 */
void limpiarEntradaDatos(void)
{
  int limpiar;

  while ((limpiar = getchar()) != '\n' && limpiar != EOF)
  {
  }

  return;
}

/**
 *@fn Función que genera números aleatorios
 *@param Entero rango inicio, Entero rango final
 *@return Número entero aleatorio
 */
int generarNumerosAleatorios(int inicio, int final)

{
  int aleatorio;

  aleatorio = inicio + rand() % final;

  return aleatorio;
}

/**
 *@fn Función que recibe un número entero entre un número mínimo y máximo.
@param Enteros que definen el mínimo y el máximo a introducir.
*/
int pedirNumero(int min, int max)
{
  int num;

  do
  {
    scanf(" %d", &num);
    if (num < min || num > max)
    {
      printf("ERROR: Tu número debe estar entre %d y %d.\n", min, max);
      printf("Intenta de nuevo: ");
    }
  } while (num < min || num > max);

  return num;
}

/**
 *@fn Procedimiento que llena una matriz con un mínimo y un máximo de filas y columnas.
 *@param Enteros para filas y columnas, matriz con un máximo de filas y colunas.
 */

void llenarMatriz(int *filas, int *columnas, float matriz[FILAS][COLUMNAS])
{
  /**
   *@var i representa las filas
   *@var j representa las columnas
   */

  int i, j;

  printf("Dime de cuántas filas va a ser la matriz (%d...%d): ", MIN_FILAS, FILAS);
  *filas = pedirNumero(MIN_FILAS, FILAS);

  printf("\nDime de cuántas columnas va a ser la matriz (%d...%d): ", MIN_COLUMNAS, COLUMNAS);
  *columnas = pedirNumero(MIN_COLUMNAS, COLUMNAS);

  printf("\n");

  for (i = 0; i < *filas; i++)
  {
    for (j = 0; j < *columnas; j++)
    {
      printf("matriz[%d][%d] = ", i, j);
      scanf(" %f", &matriz[i][j]);
    }
  }

  return;
}

/**
 *@fn Procedimiento que muestra los valores que hay dentro d euna matriz.
 *@param filas, columnas, matriz de números reales.
 */
void desplegarMatriz(int filas, int columnas, float matriz[FILAS][COLUMNAS])

{
  int i, j;
  printf("\n\nLa matriz que se ingresó fue:\n");
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas; j++)
    {
      printf(" %5.2f\t ", matriz[i][j]);
    }
    printf("\n");
  }

  return;
}
