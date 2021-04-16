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

/**
 * @brief Esta função converte outros tipos diferentes de Double para double
 * @param d Elemento d de determinado tipo que será convertido para double
 * @return double Retorna valores em double
 */
double GET_AS_DOUBLE(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "a tentar converter algo");
    }
}

/**
 * @brief Esta função converte outros tipos diferentes de long para long
 * @param d Elemento d de determinado tipo que será convertido para long
 * @return long Retorna valores em double
 */
double GET_AS_LONG(Data d){
    switch (d.tipo) {
        case CHAR: return d.LONG;
        case LONG: return d.LONG;
        case DOUBLE: return d.LONG;
        default: assert(0 && "a tentar converter algo");
    }
}

/**
 * @brief A função parser faz o parse de uma dada linha
 * @param line A linha que foi lida e da qual se vai fazer o parser
 */
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
            
        } else if (strcmp(token, "^") == 0){ // ** nao double
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

        } else if (strcmp(token, "$") == 0){
//            long x = POP(p);
//            long y = POP(p);
//            PUSH(p, x);
//            PUSH(p, x);} //else if (strcmp(token, "l i") == 0){
//            Data inteiro;
//            fgets(inteiro.LONG, 1, stdin);
//            PUSH(p, inteiro);
            Data x = POP(p);
            long lx = GET_AS_LONG(x);
            for (int i=p->n_elementos; i<lx; i--) {
                char pilhaAuxiliar[p->n_elementos];
                strcpy(p, pilhaAuxiliar);
                if (i==0) {
                    PUSH_STRING(p, pilhaAuxiliar);
                } else {
                    POP(pilhaAuxiliar);
                }
            }
            
        } else if (strcmp(token, "l") == 0){

            
            char nome[1000];
            char *estado;
            estado = fgets(nome, 1000, stdin);
            char *target = strdup(estado);
            PUSH_STRING(p, target);
            
            
        } else if (strcmp(token, "i") == 0){
            if (has_type(topo(p), STRING)) {
                char *a = POP_STRING(p);
                PUSH_LONG(p, atoi(a));
            } else {
                PUSH_LONG(p, (long) POP_DOUBLE(p));
            }
        } else if (strcmp(token, "f") == 0){
            if (has_type(topo(p), STRING)) {
                char *a = POP_STRING(p);
                PUSH_DOUBLE(p, atof(a));
            } else {
                PUSH_DOUBLE(p, (long) POP_DOUBLE(p));
            }
        } else if (strcmp(token, "c") == 0){
            if (has_type(topo(p), LONG)) {
                long a = POP_LONG(p);
                char c = a;
                PUSH_CHAR(p, c);
            } else {
                PUSH_CHAR(p, (long) POP_LONG(p));
            }
        }

    }
    PRINT_STACK(p);
}
