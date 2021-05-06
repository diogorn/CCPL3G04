/**
 * @file Este ficheiro contém a função parser
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"

#define SIZE 10240

/**
 * \brief A função parser faz o parser de uma dada linha atribuida como argumento
 * 
 * @param line É a linha que foi lida e da qual se vai fazer o parser
 */
int main (){
    char line[SIZE];
    
    parser(fgets(line, SIZE, stdin));
    
    return 0;
}

