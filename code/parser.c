/**
 * @file Este ficheiro contém a função parser
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "parser.h"
#include "stack.h"

// conversores
double GET_AS_DOUBLE(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "inconvertivel");
    }
}
long GET_AS_LONG(Data d){
    switch (d.tipo) {
        case CHAR: return d.LONG;
        case LONG: return d.LONG;
        case DOUBLE: return d.LONG;
        default: assert(0 && "inconvertivel");
    }
}
char GET_AS_CHAR(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.CHAR;
        default: assert(0 && "inconvertivel");
    }
}

void parser (char *line){
    
    MyStack *p = inicia_MyStack ();
    
    char *delimita = " \t\n";
    
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
            
            PUSH_DOUBLE(p, dy-dx);

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
            
            PUSH_DOUBLE(p, dy/dx);
            
        } else if (strcmp(token, "#") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy =  GET_AS_DOUBLE(y);
            PUSH_DOUBLE(p, pow(dx,dy));
            //  bitwise ou o módulo da divisão nunca vão ser testados com doubles.
        } else if (strcmp(token, "&") == 0){
            Data x = POP(p);
            long dx = GET_AS_LONG(x);
            Data y = POP(p);
            long dy =  GET_AS_LONG(y);;
            PUSH_LONG(p, dx&dy);
            
        } else if (strcmp(token, "|") == 0){
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            Data y = POP(p);
            long ly =  GET_AS_LONG(y);
            
            PUSH_LONG(p, lx|ly);
            
        } else if (strcmp(token, "^") == 0){
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            Data y = POP(p);
            long ly =  GET_AS_LONG(y);
            
            PUSH_LONG(p, lx^ly);
            
        } else if (strcmp(token, "~") == 0){
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            
            PUSH_DOUBLE(p, ~ lx);
            
        } else if (strcmp(token, "%")==0){
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            Data y = POP(p);
            long ly =  GET_AS_LONG(y);
            
            PUSH_LONG(p,(ly%lx));
            
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
            p->n_elementos--;
            
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

        } else if (strcmp(token, "$") == 0){
    int posicaoDoN = GET_AS_LONG(POP(p));
            int idx = p->n_elementos - posicaoDoN;
            
            Data valor  = p->stack[idx];
            PUSH(p, valor);
            }
//            7 2 3 2 $ -> 7237
        } else if (strcmp(token, "l") == 0){
            char readline[1000];
            char *x = strdup(fgets(readline, 1000, stdin));
            PUSH_STRING(p, x);
            
        } else if (strcmp(token, "i") == 0){
            if (has_type(topo(p), STRING)) {
                char *sx = POP_STRING(p);
                PUSH_LONG(p, atoi(sx));
            } else {
                long lx = GET_AS_LONG(POP(p));
                PUSH_LONG(p, lx);
            }
            
        } else if (strcmp(token, "f") == 0){
            if (has_type(topo(p), STRING)) {
                char *sx = POP_STRING(p);
                PUSH_DOUBLE(p, atof(sx));
            } else {
                double dx = GET_AS_DOUBLE(POP(p));
                PUSH_DOUBLE(p, dx);
            }
            
        } else if (strcmp(token, "c") == 0){
            Data x = POP(p);
            char cx = GET_AS_CHAR(x);
            PUSH_CHAR(p, cx);
        }

    }
    PRINT_STACK(p);
}
