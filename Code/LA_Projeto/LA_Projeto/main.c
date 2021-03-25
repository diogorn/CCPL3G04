#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"

#define SIZE 10240


int main() {
    char linha[SIZE];
      
    assert( fgets(linha, SIZE, stdin) != NULL); // le a srting
    assert( linha[strlen(linha) - 1] == '\n'); // ve se o ultimo caractrer é \n
    
    parser(linha);
    return 0;
}
