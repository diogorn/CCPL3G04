#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"

// PARSER PROF. completada com a do grupo

// strok-parte a string numa sequencia de 0 ou mais tokens nao vazios .. na primeira chamada é a string inicial e nas chamadas seguintes ela tem que ser nula

// inicializar stack
 
void parser(char *STACK1){
    char *delimitador = " \t\n";
     criar_stack();
    
    for(char *token = strtok(STACK1, delimitador); token != NULL; token = strtok(NULL, delimitador)){
        char *sobra;
        int pos=0;
        
        long valor = strtol(token, &sobra, 10);   // strtol - separar por inteiros
        if(strlen(sobra)==0){ 
            PUSH(STACK1, pos);
        } else if (strcmp(token, "+")==0){      // string compare
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x+y);
        } else if (strcmp(token, "-")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x - y);
        } else if (strcmp(token, "*")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x * y);
        } else if (strcmp(token, "/")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x / y);
        } else if (strcmp(token, "#")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x # y);
        } else if (strcmp(token, "&")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x & y);
        } else if (strcmp(token, "|")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x | y);
        } else if (strcmp(token, "^")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x ^ y);
        } else if (strcmp(token, "~")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x ~ y);
        } else if (strcmp(token, "%")==0){
                  long y = POP(STACK1);
                  long x = POP(STACK1);
                  PUSH(x % y);
        } else if (strcmp(token, "(")==0){
                  long x = POP(STACK1);
                  PUSH(x+1);
        } else if (strcmp(token, ")")==0){
                  long x = POP(STACK1);
                  PUSH(x-1);
        }
    }
    PRINT_STACK();

}

