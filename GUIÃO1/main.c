/**
 * @file Ficheiro que contém a função que imprime a stack e a função principal de todo o programa
 */
#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 

#include "parser.h"
#include "stack.h"

#define SIZE 10240

/**
 * Esta função é a função principal do programa.
 * @return O valor 0
 */
int main() {
    char linha[SIZE]; // definimos uma variavel do tipo char com o tamanho definido na macro
    
    assert( fgets(linha, SIZE, stdin) != NULL); // Lê a sequência de caractres ate encontrar o caracter NULL
    assert( linha[strlen(linha) - 1] == '\n'); //Lê uma sequência de caracteres até encontrar um \n. O limite é sempre um caractere a menos que o especificado porque no final é incluso um caractere NULL para terminar a string.
    
    parser(linha);  //coloca a linha obtida na função parser
    
    return 0;
}



