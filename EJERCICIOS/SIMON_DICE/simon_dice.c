/**
 * @file simon_dice.c
 * @brief Juego de memoria "Simon Dice"
 * @author Iker Llorens
 * 
 * Este programa implementa un juego de memoria donde el jugador debe
 * recordar y repetir secuencias de números cada vez más largas.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 100  /**< Valor máximo para los números aleatorios */
#define TURNOS 20   /**< Número de turnos/rondas del juego */

void LeerNumeros(int arregloALeer[]);
void GenerarNumeros(int arregloALlenar[]);
int SimonDice(int arregloDeJuego[]);

/**
 * @brief Función principal del programa
 * 
 * Genera una secuencia de números aleatorios e inicia el juego Simon Dice.
 * 
 * @return 0 si el programa se ejecutó correctamente
 */
int main(void)
{
    int numeros[TURNOS];

    GenerarNumeros(numeros);
    if (SimonDice(numeros) == 1)
    {
        printf("Ganaste!\n");
    }
    else
    {
        printf("Perdiste!\n");
    }

    return 0;
}

/**
 * @brief Lee números ingresados por el usuario
 * 
 * Solicita al usuario que ingrese TURNOS números y los almacena en el arreglo.
 * 
 * @param arregloALeer Arreglo donde se almacenarán los números ingresados
 */
void LeerNumeros(int arregloALeer[])
{
    int i;
    for (i = 0; i < TURNOS; i++)
    {
        scanf("%i", &arregloALeer[i]);
    }

    return;
}

/**
 * @brief Genera una secuencia de números aleatorios
 * 
 * Solicita una semilla al usuario y genera TURNOS números aleatorios
 * entre 0 y MAXIMO, almacenándolos en el arreglo proporcionado.
 * 
 * @param arregloALlenar Arreglo donde se almacenarán los números generados
 */
void GenerarNumeros(int arregloALlenar[])
{
    int i;
    int semilla;

    printf("Dame una semilla para los números aleatorios.");
    scanf("%i", &semilla);
    srand(semilla);

    for (i = 0; i < TURNOS; i++)
    {
        arregloALlenar[i] = rand() % MAXIMO;
    }
}

/**
 * @brief Ejecuta la lógica principal del juego Simon Dice
 * 
 * Muestra secuencias de números cada vez más largas y solicita al jugador
 * que las repita. El juego termina cuando el jugador comete un error o
 * completa todos los turnos exitosamente.
 * 
 * @param arregloDeJuego Arreglo con la secuencia de números del juego
 * @return 1 si el jugador ganó, 0 si perdió
 */
int SimonDice(int arregloDeJuego[])
{
    int i;
    int j;
    int numeroUsuario;

    system("clear");
    for (i = 0; i < TURNOS; i++)
    {
        printf("Memoriza esto, presiona enter cuando estes list@: \n");
        for (j = 0; j <= i; j++)
        {
            printf("%i ", arregloDeJuego[j]);
        }

        getchar();
        system("clear");
        printf("Dame la secuencia, introduce un número a la vez y presiona enter por cada número");

        for (j = 0; j <= i; j++)
        {
            scanf("%i", &numeroUsuario);
            if (numeroUsuario != arregloDeJuego[j])
                return 0;
        }

        printf("Adivinaste todos los números de esta vuelta!! Presiona enter...\n");
        getchar();
        system("clear");
    }

    return 1;
}