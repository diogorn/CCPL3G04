#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int has_type (DATA elem, int mask){
    return (elem.type & mask) != 0; //queremos que seja sempre diferente de 0
}

STACK *create_stack(){
    STACK *s = (STACK *) malloc(sizeof(STACK)); //aloca espaços 
//tambem poderiamos ter -> ... calloc (1, sizeof(STACK)) e eliminavamos a linha seguinte 
    s->n_elems = 0;
    s->size = 100;
    s->stack = (DATA *) calloc (s->size, sizeof(DATA)); //calloc -> inicializa todo o espaço de memoria a zeros 
    return s;
}

void push(STACK *s, DATA elem){ //verifica se atingimos o limite 
    if (s->size == s->n_elems){
        s->stack += 100;
        s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}

DATA pop(STACK *s){
    s->n_elems--;
    return s->stack[s->n_elems];
}

DATA top(STACK *s){
    return s->stack[s->n_elems - 1];
}

int is_empty(STACK *s){
    return s->n_elems == 0;
}

void print_stack(STACK *s){
    for (int K = 0; K < s->n_elems; K++){
        DATA elem = s->stack[K];
        TYPE type = elem.type;

        switch (type){
            case LONG;
                printf (" ""%ld", elem.LONG);
                break;
            case DOUBLE;
                printf (" ""%g", elem.DOUBLE);
                break;
            case CHAR;
                printf (" ""%c", elem.CHAR);
                break;
            case STRING;
                printf (" ""%s", STRING);
                break;
        }
    }
    printf("\n");
}

#define STACK_OPERATION(_type, _name)
    void push_##_name(STACK *s, _type val){
        DATA elem;
        elem.type = _name;
        elem._name = val;
        push(s, elem);
    }
    _type pop_##_name(STACK *s){
        DATA elem = pop(s);
        assert(elem.type == _name);
        return elem._name;
    }

STACK_OPERATION(long, LONG);
STACK_OPERATION(double, DOUBLE);
STACK_OPERATION(char, CHAR);
STACK_OPERATION(char *, STRING);