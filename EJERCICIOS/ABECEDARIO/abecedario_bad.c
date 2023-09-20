#include <stdio.h>

char a1;

void a(void);
void b(void);
void c(char aVar);
char d(void);

int main(void)
{

    a1 = d();
    if (a1 == '\0')
    {
        printf("Hasta crees que con el error te voy a decir que hago! :D\n");
        return 0;
    }

    c(a1);
}

void a(void)
{
    int i;
    for (i = 'A'; i <= 'Z'; i++)
        ;
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

void c(char aVar)
{
    if (aVar == 'M')
    {
        a();
    }
    else if (aVar == 'm')
    {
        b();
    }
}

char d(void)
{
    char miProfesorEsElMejor;

    printf("Nunca confíes en una computadora que no puedas aventar por la ventana :) : ");
    miProfesorEsElMejor = getchar();

    if (miProfesorEsElMejor != 'm' && miProfesorEsElMejor != 'M')
    {
        return '\0';
    }

    return miProfesorEsElMejor;
}