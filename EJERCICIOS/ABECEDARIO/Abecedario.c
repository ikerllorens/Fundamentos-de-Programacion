#include <stdio.h>

void a(void);
void b(void);
void c(char Mayuscula);
char d(void);
// Hacer esto con los numeros;

int main(void)
{
    char letra;

    letra = d();
    if (letra == '\0')
    {
        printf("Introdujiste un valor inválido. Adiós!\n");
        return 0;
    }

    c(letra);
}

void a(void)
{
    int i;
    for (i = 'A'; i <= 'Z'; i++)
    {
        printf("%c\n", i);
    }
}

void b(void)
{
    int i;
    for (i = 'a'; i <= 'z'; i++)
    {
        printf("%c\n", i);
    }
}

void c(char opcion)
{
    if (opcion == 'M')
    {
        a();
    }
    else if (opcion == 'm')
    {
        b();
    }
}

char d(void)
{
    char charALeer;

    printf("Dime si quieres que imprima el abecedario en mayúscula o minúscula. M para mayúsculas, m para minúsculas: ");
    charALeer = getchar();

    if (charALeer != 'm' && charALeer != 'M')
    {
        return '\0';
    }

    return charALeer;
}