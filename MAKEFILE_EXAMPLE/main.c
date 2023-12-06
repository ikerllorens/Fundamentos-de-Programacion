#include <stdio.h>
#include "biblioteca.h"

int main(void)
{
    int res;

    res = suma(2, 3, 5);
    printf("2 + 3 + 5 = %d\n", res);

    res = resta(2, 3);
    printf("2 - 3 = %d\n", res);
}