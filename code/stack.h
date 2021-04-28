#ifndef stack_h
#define stack_h

#include <stdio.h>

#define SIZE 10240

typedef enum tipo{
    LONG=1, DOUBLE=2, CHAR=4, STRING=8
}TYPE;


typedef struct TipoDados{
    TYPE tipo;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
}Data;

typedef struct Pilha{
    Data *stack;
    int size;
    int n_elementos;
}MyStack;

int has_type(Data elem, int bytes);

MyStack *inicia_MyStack();
int is_empty(MyStack *p);
Data topo(MyStack *p);
void PRINT_STACK(MyStack *p);

Data POP(MyStack *p);
void PUSH(MyStack *p, Data elem);

//funcao para dar valor às variáveis
void edita_array(MyStack *p, char letra);
void popula_stack(MyStack *p);


// macros 
#define MyStack_OPERATION_PROTO(_tipo, _name)   \
  void PUSH_##_name(MyStack *s, _tipo val);     \
_tipo POP_##_name(MyStack *s);
MyStack_OPERATION_PROTO(long, LONG)
MyStack_OPERATION_PROTO(double, DOUBLE)
MyStack_OPERATION_PROTO(char, CHAR)
MyStack_OPERATION_PROTO(char *, STRING)


#endif /* stack_h */
