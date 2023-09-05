/*
 * @file adivinaUnNumero.c
 * @brief Genera un numero aleatorio y lo checa.
 * @details Programa verifica si el usuario elijio el numero correcto.
 *
 * @author
 *  Irving Alejandro
 * @date Fecha de creacion
 *  09 de Noviembre de 2020
 *
 * @author Desarrollador que realizo la ultima modificacion
 *  Irving Alejandro
 * @date Fecha de ultima modificacion
 *  20 de Noviembre de 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
   @brief Prototipos de funcion*/
void mostrarInstrucciones(char[], char[]);
void limpiarEntradaDatos(void);
void numeroRandom(int);
int aleatorio(int);

/**
 * @fn Funcion del programa principal
 * @return Entero: Si muestra un valor 0 nuestro programa se esta ejecutando
 * correctamente
 */

int main(void) {

  int aleatorio, i, inicio = 1, final = 1000;
  char opc;
  long int tiempo;
  srand(time(NULL));
  aleatorio = inicio + rand() % final;

  mostrarInstrucciones(
      "Irving Alejandro",
      "Programa crea un numero random para que el usuario lo adivine");
  limpiarEntradaDatos();

  system("clear");

  do {
    printf("\n\n\t\tAdivina un Numero\n\t");
    printf(
        "\n\n\tUsted deve ingresar adivinar un numero que se encuentra entre "
        "el 1 y 1000\n\t");

    numeroRandom(aleatorio);

    getchar();
    printf("\n\n\t\tQuiere jugar denuevo (S)si (N)no\n\t");
    scanf("%c", &opc);
    aleatorio = inicio + rand() % final;
  } while (opc == 'S');

  printf("\n\n\t\tGracias por usar el programa\n\t");

  return 0;
}

/**
 *@fn Procedimientos Muestra las instrucciones del programa.
 */

void mostrarInstrucciones(char autores[], char instrucciones[]) {

  system("clear");

  printf("\n\n\n\n\tAplicacion desarrollada por:\n");
  printf("\t\t%s\n\n", autores);
  printf("\tDescripcion del programa:\n");
  printf("\t\t%s\n\n", instrucciones);
  printf("\tPresiona la tecla \"enter\" para continuar.");

  return;
}

/**
 *@fn Procedimiento para limpiar el buffer de entrada
 */

void limpiarEntradaDatos(void) {
  int limpiar;

  while ((limpiar = getchar()) != '\n' && limpiar != EOF) {
  }

  return;
}

/**
 *@fn Funcion Evaluar numero dado por el usuario
 *@param x numero real.
 */

void numeroRandom(int aleatorio) {
  float f;
  int usuario;
  int intento = 0;

  do {

    printf("\n\n\tQue numero crees que es\n\t");
    scanf("%f", &f);
    usuario = f;

    if (f - usuario > 0 || f < 0) {
      printf("\n Elija un numero entero y positivo \n");
    } else {
      if (usuario == aleatorio) {
        printf(
            "\n\n\tCorrecto su numero era %d y lo adivino en %d intentos\n\t",
            aleatorio, intento);
        return;
      } else {
        if (usuario < aleatorio) {
          printf("\n\n\tSu numero es muy bajo\n\t");
        } else {
          printf("\n\n\tSu numero es muy alto\n\t");
        }
        printf("\n\tLo siento intenta denuevo\n\t");
        intento = intento + 1;
      }
    }

  } while (1);
  return;
}

