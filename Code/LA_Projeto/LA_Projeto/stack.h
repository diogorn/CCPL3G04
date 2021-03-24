#ifndef stack_h
#define stack_h

#include <stdio.h>
#define SIZE 10240

// definição de stack Sara

// typedef struct{
//     int line[SIZE];
//     int top;
// } MyStack;
//
// void inicia_Stack (MyStack *p);
// int vazia (MyStack *p);
// int cheia (MyStack *p);
// void PUSH (MyStack *p, int x);
// int POP (MyStack *p);
//

#define PUSH(s, val)        \
   s.array[s.pos++] = val;

#define POP(s)              \
  s.array[--s.pos]

#define SOMAR(s)  PUSH(s, POP(s) + POP(s));
#define SUBTR(s)  {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X - Y);   \
}
#define MULT(s)  PUSH(s, POP(s) * POP(s));
#define DIV(s)  {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X / Y);   \
}

#define AND(s) {   \
  long Y = POP(s);  \
  long X = POP(s);  \
  PUSH(s, X & Y);   \
}

typedef struct {
  long array[SIZE]; // Array que armazena os elementos da stack
  int pos; // Nº de elementos  na stack (e indiretamente a sua posição)
} STACK1;

STACK1 criar_stack() {
  STACK1 s;
  s.pos = 0;
  return s;
}

void print_stack (STACK1 s);

#endif /* stack_h */
