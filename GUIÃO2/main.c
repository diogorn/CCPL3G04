/**
 * @file Ficheiro que contém a função principal de todo o programa
 */
#include <stdio.h>  
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 

#include "parser.h"
#include "stack.h"

#define SIZE 10240 

/**
 * Função função principal do programa.
 * @return O valor 0
 */
int main() {
    char linha[SIZE]; 
    
    assert( fgets(linha, SIZE, stdin) != NULL); 
    assert( linha[strlen(linha) - 1] == '\n'); 
    
    parser(linha); 
    
    return 0;
}


