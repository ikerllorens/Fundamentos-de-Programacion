#include <stdio.h>

int main() {
    int a, b;
    int c; //Para el sistema de recursion
    printf ("Introduce el 1er numero: ");
    scanf ("%d", &a);
    printf ("Introduce el 2do numero: ");
    scanf ("%d", &b);
    while (b != 0) {
        c = b;
        b = a % b;
        a = c;
    }
    printf("%d\n", a);
}
