/**
 * @file Este ficheiro contém todas as funções associadas à stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

/**
 * @brief A função has_type indica o tipo do elemento e o número de bytes utilizados
 * @param elem Elemento de um determinado tipo Data
 * @param bytes Número de bytes utilizados pelo elemento
 * @return Retorna o tipo do elemento analisado e os bytes respetivos 
 */
int has_type (Data elem, int bytes){
    return (elem.tipo & bytes);
}

/**
 * @brief Função que retribui informações sobre a estrutura Stack
 * @return p apontador para a MyStack* 
 */
MyStack *inicia_MyStack(){
    MyStack *p = (MyStack *) calloc(1, sizeof(MyStack));
    p->size = 100;
    p->stack = (Data *) calloc(p->size, sizeof(Data));
    return p;
}

/**
 * @brief Verifica se a stack está vazia ou não
 * @param p apontador para a stack
 * @return int Retorna o valor do número de elementos da stack
 */
int is_empty(MyStack *p) {
  return p->n_elementos == 0;
}

/**
 * @brief Retira o elemento que está no topo da stack
 * @param p Apontador para a stack
 * @return Retorna a stack sem o elemento do topo
 */
Data topo(MyStack *p) {
  return p->stack[p->n_elementos - 1];
}

//void PUSH_DOUBLE_AS_TYPE(MyStack *p, double value, TYPE type){
//    Data d;
//    switch (d.tipo) {
//        case CHAR: d.tipo = CHAR; d.CHAR = value;
//    }
//    PUSH(p, d);
//}

/**
 * @brief Função que imprime a stack 
 * @param p Apontador para a stack
 */
void PRINT_STACK(MyStack *p) {
    for (int i=0; i < p->n_elementos; i++){
        Data elem = p->stack[i];
        TYPE wichType = elem.tipo;
        
        switch(wichType){
            case LONG:
                printf("%ld", elem.LONG);
                break;
            case DOUBLE:
                printf("%g", elem.DOUBLE);
                break;
            case CHAR:
                printf("%c", elem.CHAR);
                break;
            case STRING:
                printf("%s", elem.STRING);
                break;
        }
    }
    printf("\n");
}

/**
 * @brief Responsável por desempilhar elementos numa stack
 * @param p Apontador para a stack
 * @return Data Retorna a stack alterada 
 */
Data POP(MyStack *p) {
  p->n_elementos--;
  return p->stack[p->n_elementos];
}

/**
 * @brief Responsável por empilhar elementos na stack
 * @param p Apomtador para a stack
 * @param elem Um dado elemento de um dado tipo
 */
void PUSH(MyStack *p, Data elem) {
  if(p->size == p->n_elementos) {
    p->size += 100;
    p->stack = (Data *) realloc(p->stack, p->size * sizeof(Data));
  }
  p->stack[p->n_elementos] = elem;
  p->n_elementos++;
}


// macros

#define MyStack_OPERATION(_tipo, _name)         \
  void PUSH_##_name(MyStack *s, _tipo val) {    \
    Data elem;                                  \
    elem.tipo = _name;                          \
    elem._name = val;                           \
    PUSH(s, elem);                              \
  }                                             \
  _tipo POP_##_name(MyStack *s) {               \
    Data elem = POP(s);                         \
    assert(elem.tipo == _name);                 \
    return elem._name;                          \
  }

MyStack_OPERATION(long, LONG)
MyStack_OPERATION(double, DOUBLE)
MyStack_OPERATION(char, CHAR)
MyStack_OPERATION(char *, STRING)

