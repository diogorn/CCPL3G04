#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "parser.h"

void parser(char *linha){
    char *delims = " \t\n";

    MyStack p = inicia_Stack ();
    
    for (char *token = strtok(linha, delims); token != NULL; token = strtok(NULL,delims)){
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if(strlen(sobra) == 0){
                 PUSH(MyStack p,val_i);
        } else if (strcmp(token, "+") == 0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x + y));
        } else if (strcmp(token, "-") == 0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x - y));
        } else if (strcmp(token, "*") == 0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x * y));
        } else if (strcmp(token, "/") == 0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x / y));
        } else if (strcmp(token, "#") == 0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x # y));
        } else if (strcmp(token, "&") == 0){
                   long y = POP(MyStack p);
                   long x = POP(MyStack p);
                   PUSH(MyStack p, (x & y));
        } else if (strcmp(token, "|") == 0){
                   long y = POP(MyStack p);
                   long x = POP(MyStack p);
                   PUSH(MyStack p, (x | y));
        } else if (strcmp(token, "^") == 0){
                   long y = POP(MyStack p);
                   long x = POP(MyStack p);
                   PUSH(MyStack p, (x ^ y));
        } else if (strcmp(token, "~") == 0){
                   long y = POP(MyStack p);
                   long x = POP(MyStack p);
                   PUSH(MyStack p, (x ~ y));
        } } else if (strcmp(token, "%")==0){
                  long y = POP(MyStack p);
                  long x = POP(MyStack p);
                  PUSH(MyStack p,(x % y));
        } else if (strcmp(token, "(")==0){
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x+1));
        } else if (strcmp(token, ")")==0){
                  long x = POP(MyStack p);
                  PUSH(MyStack p, (x-1));
        }
    PRINT_STACK();
}


