#ifndef arrays_h
#define arrays_h

#include <stdio.h>
#include "stack.h"

void cria_array(MyStack *p, int array_size);
void move_array_to_stack (MyStack *p);


//void tamanho_array(MyStack *p);


void array_tamanho (MyStack *p, char array[]);
void valor_por_indice (MyStack *p);
void range (MyStack *p);


#endif /* arrays_h */
