/**
 * @file Este ficheiro contém a função principal do programa
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"

#define SIZE 10240

/**
 * @brief Função principal do programa.
 * @return Devolve o valor 0 
 */
int main (){
    char line[SIZE];
//    assert(fgets(line, SIZE, stdin) != NULL);
//    assert(line[strlen(line -1)] == '\n'); // se o ultimo caracter for \n, a função calcula o comprimento da line e tira-lhe 1

    
    parser(fgets(line, SIZE, stdin));
    
    return 0;
}
