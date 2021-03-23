#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

void parser(char *linha){
    char *delims = " \t\n";
    
    for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL,delims)){
        char *sobra;
        long val_i = strtol(token, &sobra, 10);
        if(strlen(sobra) == 0){
                 PUSH(val_i);
        } else if (strcmp(token, "+") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x + y);
        } else if (strcmp(token, "-") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x - y);
        } else if (strcmp(token, "*") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x * y);
        } else if (strcmp(token, "/") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x / y);
        } else if (strcmp(token, "#") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x # y);
        }  else if (strcmp(token, "&") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x & y);
        } else if (strcmp(token, "|") == 0){
                  long y = POP();
                  long x = POP();
                  PUSH(x | y);
    }
}
