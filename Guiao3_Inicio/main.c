#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"

#define SIZE 10240

int main (){
    char line[SIZE];
//    assert(fgets(line, SIZE, stdin) != NULL);
//    assert(line[strlen(line -1)] == '\n'); // se o ultimo caracter for \n, a função calcula o comprimento da line e tira-lhe 1

    
    parser(fgets(line, SIZE, stdin));
    
    return 0;
}
//65 - 10
//66 - 11
//67 - 12
//68 - 13
//69 - 14
//70 - 15
//78 - \n
//83 - " "
//88 - 0
//89 - 1
//90 - 2
