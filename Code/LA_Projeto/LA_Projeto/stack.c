#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE  10240




void print_stack(STACK1 s) {
  printf("Stack: ");
  for(int k = 0; k < s.pos; k++)
    printf("\t%3ld", s.array[k]);
  printf("\n");
}



int main() {
  STACK1 s = criar_stack();
  char op = '&';
  PUSH(s, 2);
  PUSH(s, 6);
  PUSH(s, 2);
  print_stack(s);
  switch(op) {
    case '+': SOMAR(s); break;
    case '-': SUBTR(s); break;
    case '*': MULT(s); break;
    case '/': DIV(s); break;
    case '&': AND(s); break;
  }
  print_stack(s);
}
