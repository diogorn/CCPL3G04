#include "calculos.h"

int soma (int x, int y){
    printf ("%d %d %c\n", x, y, '+');

    return x + y;
}

int subtrai (int x, int y){
    printf ("%d %d %c\n", x, y, '-');

    return x - y;
}

int multiplica (int x, int y){
    printf ("%d %d %c\n", x, y, '*');

    return x * y;
}

int divide (int x, int y){
    printf ("%d %d %c\n", x, y, '/');

    return x / y;
}
