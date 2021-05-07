/**
  *@file Ficheiro                 !!!!!!!!!!!!!!!!!!!!!!           .
  *\brief Neste ficheiro está presente mascáras, estruturas de dados e de stack,bem omo funções utilizadas na stack.
  *@date April 2021
  *@returns                    !!!!!!!!!!!!!!!!!!!!!!!!!!
 */
#ifndef stack_h
#define stack_h

#include <stdio.h>

#define SIZE 10240
/**
 * Struct que enumera os tipos e que vai aplicá-los na struct data.
 */
typedef enum tipo{ 
   LONG = 1,    /**< Tipo Long com o valor 1 (2⁰) associado */
   DOUBLE = 2,  /**< Tipo Double com o valor 2 (2¹) associado */
   CHAR = 4,    /**< Tipo Char com o valor 4 (2²) associado */
   STRING = 8   /**< Tipo String com o valor 8 (2³) associado */
} TYPE;

/**
 * Uma struct que nos dá os tipos de dados que estamos a usar na stack
 */
typedef struct TipoDados{
    TYPE tipo;
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
    struct arrays *ARRAY;
}Data;

/**
 * Definição de uma struct com as caracteristicas da stack.
 */
typedef struct arrays{
    int size;
    int n_elementos;
    Data array;
}MyArray;

/**
 * \struct Stack  
 * \brief Esta estrutura representa a Stack 
 */
typedef struct Pilha{
    Data array[26];
    Data *stack;
    int size;
    int n_elementos;
//    int pos;
}MyStack;

/**
 * \brief Definição dos protótipos das funções utilizadas na stack.
 */
MyStack *inicia_MyStack();
int is_empty(MyStack *p); // inutil ¿?
Data topo(MyStack *p);
void PRINT_STACK(MyStack *p);

Data POP(MyStack *p);
void PUSH(MyStack *p, Data elem);

// identifica tipo
int has_type(Data elem, int bytes);
//conversores de Data->long/double/char
double GET_AS_DOUBLE(Data d);
long GET_AS_LONG(Data d);
char GET_AS_CHAR(Data d);

// Recebe long/double/char ->Data
Data make_long (long l);
Data make_double (double d);
Data make_char (char c);

void add_valor (MyStack *p, char letra);
void variaveis(MyStack *p, char letra);
void variaveis_pre_definidas(MyStack *p);


// macros
/**
 * \brief Definição de uma macro para os operadores da stack.
 */
#define MyStack_OPERATION_PROTO(_tipo, _name)   \
  void PUSH_##_name(MyStack *p, _tipo val);     \
_tipo POP_##_name(MyStack *p);
MyStack_OPERATION_PROTO(long, LONG)
MyStack_OPERATION_PROTO(double, DOUBLE)
MyStack_OPERATION_PROTO(char, CHAR)
MyStack_OPERATION_PROTO(char *, STRING)
MyStack_OPERATION_PROTO(struct Pilha *, ARRAY)


#endif /* stack_h */
