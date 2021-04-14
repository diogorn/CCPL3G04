#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

int has_type (Data elem, int bytes){
    return (elem.NBytes & bytes);
}
// Funções que retribuem infos da stack
MyStack *inicia_MyStack(){
    MyStack *p = (MyStack *) calloc(1, sizeof(MyStack));
    p->size = 100;
    p->stack = (Data *) calloc(p->size, sizeof(Data));
    return p;
}

int is_empty(MyStack *p) {
  return p->n_elementos == 0;
}

Data topo(MyStack *p) {
  return p->stack[p->n_elementos - 1];
}

void PRINT_STACK(MyStack *p) {
    for (int i=0; i <= p->n_elementos; i++){
        Data elem = p->stack[i];
        TYPE wichType = elem.NBytes;
        
        switch(wichType){
            case LONG: printf("%ld", elem.LONG);
                break;
            case DOUBLE: printf("%g", elem.DOUBLE);
                break;
            case CHAR: printf("%c", elem.CHAR);
                break;
            case STRING: printf("%s", elem.STRING);
                break;
        }
    }
    printf("\n");
}

// operações na stack
Data POP(MyStack *p) {
  p->n_elementos--;
  return p->stack[p->n_elementos];
}

void PUSH(MyStack *p, Data elem) {
  if(p->size == p->n_elementos) {
    p->size += 100;
    p->stack = (Data *) realloc(p->stack, p->size * sizeof(Data));
  }
  p->stack[p->n_elementos] = elem;
  p->n_elementos++;
}


// macros

#define MyStack_OPERATION(_NBytes, _name)       \
  void PUSH_##_name(MyStack *s, _NBytes val) {  \
    Data elem;                                  \
    elem.NBytes = _name;                        \
    elem._name = val;                           \
    PUSH(s, elem);                              \
  }                                             \
  _NBytes POP_##_name(MyStack *s) {             \
    Data elem = POP(s);                         \
    assert(elem.NBytes == _name);               \
    return elem._name;                          \
  }

MyStack_OPERATION(long, LONG)
MyStack_OPERATION(double, DOUBLE)
MyStack_OPERATION(char, CHAR)
MyStack_OPERATION(char *, STRING)

