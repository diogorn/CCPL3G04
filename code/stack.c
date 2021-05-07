/**
 * @file Este ficheiro contém todas as funções associadas à stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"
// conversoes de tipos
/**
 * \brief Esta função converte outros tipos diferentes de double para double
 * @param d Elemento d de determinado tipo que será convertido para double
 * @returns double Retorna valores em double
 */
double GET_AS_DOUBLE(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "inconvertivel");
    }
}

/**
 * \brief Esta função converte outros tipos diferentes de long para long
 * @param d Elemento d de determinado tipo que será convertido para long
 * @returns long Retorna valores em long
 */
long GET_AS_LONG(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "inconvertivel");
    }
}

/**
 * \brief Esta função converte outros tipos diferentes de char para char
 * @param d Elemento d de determinado tipo que será convertido para char
 * @returns Retorna valores em char
 */
char GET_AS_CHAR(Data d){
    switch (d.tipo) {
        case CHAR: return d.CHAR;
        case LONG: return d.LONG;
        case DOUBLE: return d.DOUBLE;
        default: assert(0 && "inconvertivel");
    }
}

/**
 * \brief A função has_type indica o tipo do elemento e o número de bytes utilizados
 * 
 * @param elem Elemento de um determinado tipo Data
 * @param bytes Número de bytes utilizados pelo elemento
 * @returns Retorna o tipo do elemento analisado e os bytes respetivos 
 */
int has_type (Data elem, int bytes){
    return (elem.tipo & bytes);
}
// Funções que retribuem infos da stack
/**
 * \brief Função que retribui informações sobre a estrutura Stack
 * @returns p apontador para a MyStack* 
 */
MyStack *inicia_MyStack(){
    MyStack *p = (MyStack *) calloc(1, sizeof(MyStack));
    p->size = 100;
    p->stack = (Data *) calloc(p->size, sizeof(Data));
    return p;
}

/**
 * \brief Verifica se a stack está vazia ou não
 * @param p apontador para a stack
 * @returns int Retorna o valor do número de elementos da stack
 */
int is_empty(MyStack *p) {
  return p->n_elementos == 0;
}

/**
 * \brief Retira o elemento que está no topo da stack
 * @param p Apontador para a stack
 * @returns Retorna a stack sem o elemento do topo
 */
Data topo(MyStack *p) {
  return p->stack[p->n_elementos - 1];
}

/**
 * \brief Função que imprime a stack 
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


// operações na stack
/**
 * \brief Responsável por desempilhar elementos numa stack
 * @param p Apontador para a stack
 * @returns Data Retorna a stack alterada 
 */
Data POP(MyStack *p) {
  p->n_elementos--;
  return p->stack[p->n_elementos];
}

/**
 * \brief Responsável por empilhar elementos na stack
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

// recebe um long e devolve um Data
/**
 * \brief A função make_long tranforma um elemento do tipo long num elemento do tipo Data
 * @param l Variável do tipo long 
 * @returns Um valor do tipo data 
 */
Data make_long (long l){
    Data x;
    x.tipo = LONG;
    x.LONG = l;
    return x;
}

/**
 * \brief A função make_long tranforma um elemento do tipo double num elemento do tipo Data
 * @param l Variável do tipo long 
 * @returns Um valor do tipo data 
 */
Data make_double (double d){
    Data x;
    x.tipo = DOUBLE;
    x.DOUBLE = d;
    return x;
}

/**
 * \brief A função make_long tranforma um elemento do tipo char num elemento do tipo Data
 * @param l Variável do tipo long 
 * @returns Um valor do tipo data 
 */
Data make_char (char c){
    Data x;
    x.tipo = CHAR;
    x.CHAR = c;
    
    return x;
}

// copia o topo da stack da variável
// :
// mudança de nome: conteudo -> add valor
/**
 * \brief A função add_valor copia o topo da Stack à variável
 * 
 * @param p Apontador para a stack
 * @param letra Um argumento do tipo char
 */
void add_valor (MyStack *p, char letra)  {
    Data x = topo(p);
    if (has_type(x, LONG)) {
        p->array[letra-'A'] = x;
    } else if (has_type(x, DOUBLE)){
        p->array[letra-'A'] = x;
    } else if (has_type(x, CHAR)){
        p->array[letra-'A'] = x;
    }
}

// Push do conteudo da variavel
// mudança de nome: da_valor -> variaveis
/**
 * \brief Esta função faz o push do conteúdo da variável
 * 
 * @param p Apontador para a stack
 * @param letra Um argumento do tipo char
 */
void variaveis(MyStack *p, char letra){
    Data x =  p->array[letra-'A'];
    
    if (has_type(x, LONG)) {
        PUSH_LONG(p, x.LONG);
    } else if (has_type(x, DOUBLE)){
        PUSH_DOUBLE(p, x.DOUBLE);
    } else if (has_type(x, CHAR)){
        PUSH_CHAR(p, x.CHAR);
    } else if (has_type(x, STRING)){
        PUSH_STRING(p, x.STRING);
    }
}

/**
 * \brief Esta função identifica as variáveis pré-definidas atribuindo-lhes os valores correspondetes, por omissão
 * 
 * @param p Apontador para a stack 
 */
void variaveis_pre_definidas(MyStack *p){
    for (int i=0; i<=5; i++) {
        p->array[i] = make_long(10+i);
    }
    for (int i=23; i<26;i++){
        p->array[i] = make_long(i-23);
    }
    p->array[13] = make_char('\n');
    p->array[18] = make_char(' ');
}


// macros
