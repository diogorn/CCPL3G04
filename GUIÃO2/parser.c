/**
 * \brief Esta é a função que vai fazer o parse de uma linha
 * @param line A linha que foi lida e da qual se vai fazer o parse
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "parser.h"

void parser(char *linha){
    char *delims = " \t\n";

    MyStack s = inicia_Stack ();
    MyStack *p = &s;

    for (char *token = strtok(linha, delims); token != NULL; token = strtok(NULL,delims)){
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        
        if(strlen(sobra) == 0){
                 PUSH(p,val_i);
        
        } else if (strcmp(token, "+") == 0){
                  long y = POP(p);
                  long x = POP(p);
                  PUSH(p, (x + y));
        
        } else if (strcmp(token, "-") == 0){
                  long y = POP(p);
                  long x = POP(p);
                  PUSH(p, (x - y));
        
        } else if (strcmp(token, "*") == 0){
                  long y = POP(p);
                  long x = POP(p);
                  PUSH(p, (x * y));
        
        } else if (strcmp(token, "/") == 0){
                  long y = POP(p);
                  long x = POP(p);
                  PUSH(p, (x / y));
        
        } else if (strcmp(token, "#") == 0){
                  long y = POP(p);
                  long x = POP(p);
                  PUSH(p, pow(x,y));
        
        } else if (strcmp(token, "&") == 0){
                   long y = POP(p);
                   long x = POP(p);
                   PUSH(p, (x & y));
        
        } else if (strcmp(token, "|") == 0){
                   long y = POP(p);
                   long x = POP(p);
                   PUSH(p, (x | y));
        
 
