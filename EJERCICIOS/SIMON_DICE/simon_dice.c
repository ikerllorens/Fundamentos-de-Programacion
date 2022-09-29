#include <stdio.h>
#include <stdlib.h>

// Primera vez que vemos define
#define MAXIMO 100

// Revisar después este truco
#define TURNOS 20

void LeerNumeros(int arregloALeer[]);
void GenerarNumeros(int arregloALlenar[]);
int SimonDice(int arregloDeJuego[]);

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

void LeerNumeros(int arregloALeer[])
{
    int i;
    for (i = 0; i < TURNOS; i++)
    {
        scanf("%i", &arregloALeer[i]);
    }

    return;
}

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