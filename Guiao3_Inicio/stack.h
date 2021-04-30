#ifndef stack_h
#define stack_h

#include <stdio.h>

#define SIZE 10240
// atribui um numero (escolhi o de bytes) para facil identificação do tipo de dado que é
typedef enum tipo{
//    o numero de posições corresponde ao numero de bytes que cada tipo de dados ocupa
    LONG=1, DOUBLE=2, CHAR=4, STRING=8

}TYPE;



// vai ajudar a definir o tipo de dados com a função vai trabalhar
typedef struct TipoDados{
    TYPE tipo;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
}Data ;
// --------------------------------------
typedef struct Pilha{
    Data array[26];
    Data *stack;
    int size;
    int n_elementos;
}MyStack;


int has_type(Data elem, int bytes);

MyStack *inicia_MyStack();
int is_empty(MyStack *p);
Data topo(MyStack *p);
void PRINT_STACK(MyStack *p);
void PRINT_TOP(Data p);

Data POP(MyStack *p);
void PUSH(MyStack *p, Data elem);
void PUSH_DOUBLE_AS_TYPE(MyStack *p, double value, TYPE type);

double GET_AS_DOUBLE(Data d);
long GET_AS_LONG(Data d);
char GET_AS_CHAR(Data d);

Data make_long (long l);
Data make_double (double d);
Data make_char (char c);

void conteudo (MyStack *p, char letra);

////funcao para dar valor às variáveis
void da_valor(MyStack *p, char letra);
void variaveis(MyStack *p);


// macros
#define MyStack_OPERATION_PROTO(_tipo, _name)   \
  void PUSH_##_name(MyStack *s, _tipo val);     \
_tipo POP_##_name(MyStack *s);
MyStack_OPERATION_PROTO(long, LONG)
MyStack_OPERATION_PROTO(double, DOUBLE)
MyStack_OPERATION_PROTO(char, CHAR)
MyStack_OPERATION_PROTO(char *, STRING)


#endif /* stack_h */
