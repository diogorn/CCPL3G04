#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "parser.h"
#include "stack.h"



// conversores
//double GET_AS_DOUBLE(Data d){
//    switch (d.tipo) {
//        case CHAR: return d.CHAR;
//        case LONG: return d.LONG;
//        case DOUBLE: return d.DOUBLE;
//        default: assert(0 && "inconvertivel");
//    }
//}
//long GET_AS_LONG(Data d){
//    switch (d.tipo) {
//        case CHAR: return d.CHAR;
//        case LONG: return d.LONG;
//        case DOUBLE: return d.DOUBLE;
//        default: assert(0 && "inconvertivel");
//    }
//}
//char GET_AS_CHAR(Data d){
//    switch (d.tipo) {
//        case CHAR: return d.CHAR;
//        case LONG: return d.LONG;
//        case DOUBLE: return d.DOUBLE;
//        default: assert(0 && "inconvertivel");
//    }
//}

void parser (char *line){
    
    MyStack *p = inicia_MyStack ();
    variaveis(p);
    
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
//            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
//
//            PUSH_DOUBLE(p, dx+dy);

            if (has_type(x, LONG) & has_type(y, LONG)) {
                long lx = GET_AS_LONG(x);
                long ly = GET_AS_LONG(y);
                PUSH_LONG(p, ly+lx);
            } else {
               double dx = GET_AS_DOUBLE(x);
               double dy =  GET_AS_DOUBLE(y);
                PUSH_DOUBLE(p, dy+dx);
            }
          
        } else if (strcmp(token, "-") == 0){
            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
            
//            PUSH_DOUBLE(p, dy-dx);
            if (has_type(x, LONG) & has_type(y, LONG)) {
                long lx = GET_AS_LONG(x);
                long ly = GET_AS_LONG(y);
                PUSH_LONG(p, ly-lx);
            } else {
               double dx = GET_AS_DOUBLE(x);
               double dy =  GET_AS_DOUBLE(y);
                PUSH_DOUBLE(p, dy-dx);
            }
        } else if (strcmp(token, "*") == 0){
            Data x = POP(p);
//            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
//            double dy =  GET_AS_DOUBLE(y);
            
//            PUSH_DOUBLE(p, dx*dy);
            if (has_type(x, LONG) & has_type(y, LONG)) {
                long lx = GET_AS_LONG(x);
                long ly = GET_AS_LONG(y);
                PUSH_LONG(p, ly*lx);
            } else {
               double dx = GET_AS_DOUBLE(x);
               double dy =  GET_AS_DOUBLE(y);
                PUSH_DOUBLE(p, dy*dx);
            }
            
        } else if (strcmp(token, "/") == 0){
            Data x = POP(p);
            Data y = POP(p);
            if (has_type(x, LONG) & has_type(y, LONG)) {
                long lx = GET_AS_LONG(x);
                long ly = GET_AS_LONG(y);
                PUSH_LONG(p, ly/lx);
            } else {
               double dx = GET_AS_DOUBLE(x);
               double dy =  GET_AS_DOUBLE(y);
                PUSH_DOUBLE(p, dy/dx);
            }

            
        } else if (strcmp(token, "#") == 0){
            Data x = POP(p);
            Data y = POP(p);
            if (has_type(x, LONG) & has_type(y, LONG)) {
                long lx = GET_AS_LONG(x);
                long ly = GET_AS_LONG(y);
                PUSH_LONG(p, pow(ly,lx));
            } else {
               double dx = GET_AS_DOUBLE(x);
               double dy =  GET_AS_DOUBLE(y);
                PUSH_DOUBLE(p, pow(dy, dx));
            }
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
            
            if (has_type(x, LONG)) {
                long lx = GET_AS_LONG(x);
                PUSH_LONG(p, lx-1);
            } else if ( has_type(x, DOUBLE)){
               double dx = GET_AS_DOUBLE(x);
                PUSH_DOUBLE(p, dx-1);
            } else if (has_type(x, CHAR)){
                char cx = GET_AS_CHAR(x);
                PUSH_CHAR(p, cx-1);
            }
            
        } else if (strcmp(token, ")")==0){
            Data x = POP(p);
            if (has_type(x, LONG)) {
                long lx = GET_AS_LONG(x);
                PUSH_LONG(p, lx+1);
            } else if ( has_type(x, DOUBLE)){
               double dx = GET_AS_DOUBLE(x);
                PUSH_DOUBLE(p, dx+1);
            } else if (has_type(x, CHAR)){
                char cx = GET_AS_CHAR(x);
                PUSH_CHAR(p, cx+1);
            }

        
        } else if (strcmp(token, "_") == 0){
            Data x = POP(p);
            PUSH(p, x);
            PUSH(p, x);

        } else if (strcmp(token, ";") == 0){
            p->n_elementos--;
            
        } else if (strcmp(token, "\\") == 0){
            Data x = POP(p);
            Data y = POP(p);
            PUSH(p, x);
            PUSH(p, y);

        } else if (strcmp(token, "@") == 0){
            Data x = POP(p);
            Data y = POP(p);
            Data z = POP(p);
            PUSH(p, y);
            PUSH(p, x);
            PUSH(p, z);
           

        } else if (strcmp(token, "$") == 0){
            long posicaoDoN = GET_AS_LONG(POP(p));
            long idx = p->n_elementos-1 - posicaoDoN;
            
            Data valor  = p->stack[idx];
            PUSH(p, valor);
            
        } else if (strcmp(token, "l") == 0){
            char readline[SIZE];
            char *l = strdup(fgets(readline, SIZE, stdin));
            PUSH_STRING(p, l);
            
        } else if (strcmp(token, "p") == 0){
            Data x = POP(p);
            PUSH(p, x);
            PRINT_TOP(x);
            
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
            
        //PERGUNTAR 0 E 1 / TRUE FALSE
        } else if (strcmp(token, "=")==0) {
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dx == dy) {
                PUSH_DOUBLE(p, 1);
            }
        } else if (strcmp(token, "<")==0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy < dx) {
                PUSH_LONG(p, 1);
            } else {
                PUSH_LONG(p, 0);
            }
        } else if (strcmp(token, ">")==0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy > dx) {
                PUSH_LONG(p, 1);
            } else {
                PUSH_LONG(p, 0);
            }
        } else if (strcmp(token, "!") == 0){
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            if (lx == 0) {
                PUSH_LONG (p, 1);
            } else {
                PUSH_LONG (p, 0);
            }
        } else if (strcmp(token, "e&") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy == 0) {
                PUSH_DOUBLE(p, 0);
            } else {
                PUSH_DOUBLE(p, dx);
            }
        } else if (strcmp(token, "e|") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy != 0) {
                PUSH_DOUBLE(p, 1);
            } else {
                PUSH_DOUBLE(p, dx);
            }
        } else if (strcmp(token, "e<") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy<dx) {
                PUSH_DOUBLE(p, dy);
            } else {
                PUSH_DOUBLE(p, dx);
            }
        } else if (strcmp(token, "e>") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            if (dy>dx) {
                PUSH_DOUBLE(p, dy);
            } else {
                PUSH_DOUBLE(p, dx);
            }
//             1 2 1 1 = ?
        } else if (strcmp(token, "?") == 0){
            Data x = POP(p);
            double dx = GET_AS_DOUBLE(x);
            Data y = POP(p);
            double dy = GET_AS_DOUBLE(y);
            Data z = POP(p);
            double dz = GET_AS_DOUBLE(z);
            if (dz != 0){
                PUSH_DOUBLE(p, dy);
            }else {
                PUSH_DOUBLE(p, dx);
            }
            
        } else if (strcmp(token, "A") == 0){
            da_valor(p, 'A');
        } else if (strcmp(token, "B") == 0){
            da_valor(p, 'B');
        } else if (strcmp(token, "C") == 0){
            da_valor(p, 'C');
            // fazer else if para o resto das letras
        } else if (strcmp(token, ":A") == 0){
            conteudo(p, 'A');
        } else if (strcmp(token, ":B") == 0){
            conteudo(p, 'B');
        } else if (strcmp(token, ":C") == 0){
            conteudo(p, 'C');
            // fazer else if para o resto das letras
        } 
    }
    PRINT_STACK(p);
}

