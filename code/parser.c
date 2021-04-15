#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "parser.h"
#include "stack.h"

double GET_AS_DOUBLE(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "a tentar converter algo");
    }
}

void parser (char *line){
    char *delimita = " \t\n";
    
    MyStack *p = inicia_MyStack ();
    
    for (char *token = strtok(line, delimita); token != NULL; token = strtok(NULL,delimita)){
        char *sobra1;
        char *sobra2;
        
        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);
        
        if(strlen(sobra1) == 0){
                    PUSH_LONG(p, val_l);
               
        } else if(strlen(sobra2) == 0){
                    PUSH_DOUBLE(p, val_d);
    
// operações
        } else if (strcmp(token, "+") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            
            PUSH_DOUBLE(p, dx+dy);

        } else if (strcmp(token, "-") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            
            PUSH_DOUBLE(p, dx-dy);

        } else if (strcmp(token, "*") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            
            PUSH_DOUBLE(p, dx*dy);
            
        } else if (strcmp(token, "/") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            
            PUSH_DOUBLE(p, dx/dy);
            
        } else if (strcmp(token, "#") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            PUSH_DOUBLE(p, pow(dx,dy));
            //  bitwise ou o módulo da divisão nunca vão ser testados com doubles.
        } else if (strcmp(token, "&") == 0){
//            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
//            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
//            Data e = (x & y);
//            double de = GET_AS_DOUBLE(e);
//            PUSH_LONG(p, de);
//        } else if (strcmp(token, "|") == 0){
//            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
//            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
//            PUSH_DOUBLE(p, (x | y));
//        } else if (strcmp(token, "^") == 0){ ** nao double
//            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
//            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
//                   PUSH(p, (x ^ y));
//        } else if (strcmp(token, "~") == 0){
//            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
//                   PUSH(p, ~ x);
//        } else if (strcmp(token, "%")==0){ ** nao double
//            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
//            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
//                  PUSH(p,(y%x));
        } else if (strcmp(token, "(")==0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            PUSH_DOUBLE(p, (dx-1));
        } else if (strcmp(token, ")")==0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            PUSH_DOUBLE(p, (dx+1));

        } else if (strcmp(token, "_") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            PUSH_DOUBLE(p, dx);
            PUSH_DOUBLE(p, dx);

        } else if (strcmp(token, ";") == 0){
            Data x = POP(p);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            PUSH_DOUBLE(p, dy);

        } else if (strcmp(token, "\\") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            PUSH_DOUBLE(p, dx);
            PUSH_DOUBLE(p, dy);

        } else if (strcmp(token, "@") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            Data z = POP(p);
            double dz = GET_AS_DOUBLE(z);
            PUSH_DOUBLE(p, dy);
            PUSH_DOUBLE(p, dx);
            PUSH_DOUBLE(p, dz);
//
//        } else if (strcmp(token, "$") == 0){
//            long x = POP(p);
//            long y = POP(p);
//            PUSH(p, x);
//            PUSH(p, x);} //else if (strcmp(token, "l i") == 0){
//            Data inteiro;
//            fgets(inteiro.LONG, 1, stdin);
//            PUSH(p, inteiro);
        }
    }
    PRINT_STACK(p);
}
