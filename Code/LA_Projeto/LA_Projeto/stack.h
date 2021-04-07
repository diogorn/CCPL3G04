#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE; //declara um tipo de dados

#define INTEGER (LONG | CHAR)
#define NUMBER (INTEGER | DOUBLE)

typedef struct data{
    TYPE type;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
} DATA; //tipo de dados que esta na stack

typedef struct stack{
    DATA *stack; //um array do tipo DATA
    int size; //tamanho da stack
    int n_elems; //nº de elementos
} STACK;

int has_type (DATA elem, int mask); //diz nos se o tipo daquele elemento faz sentido em relaçao aquela mascara
STACK *create_stack(); //cria espaço para uma stack faz oq tem a fazer e devolve o apontador para a dita stack
void push(STACK *s, DATA elem);
DATA pop (STACK *s);
int is_empty(STACK *s);
void print_stack(STACK *s);

#define STACK_OPERATION_PROTO(_type, _name)
    void push_##_name(STACK *s, _type val);
    _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG);
STACK_OPERATION_PROTO(double, DOUBLE);
STACK_OPERATION_PROTO(char, CHAR);
STACK_OPERATION_PROTO(char *, STRING);

#endif
