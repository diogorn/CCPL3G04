#include <stdio.h>
#define SIZE    10240

typedef struct {
  long array[SIZE]; // Array que armazena os elementos da stack
  int pos; // Nº de elementos  na stack (e indiretamente a sua posição)
} STACK;

STACK criar_stack() {
  STACK s;
  s.pos = 0;
  return s;
}

#define PUSH(s, val)        \
  printf("ADD: %2ld\n", val); s.array[s.pos++] = val;

#define POP(s)              \
  s.array[--s.pos]

void print_stack(STACK s) {
  printf("Stack: ");
  for(int k = 0; k < s.pos; k++)
    printf("\t%3ld", s.array[k]);
  printf("\n");
}

int main() {
 
//    pusch
//    pop 
  STACK s = criar_stack();
  
  PUSH(s, 7l);
  PUSH(s, 2l);
  PUSH(s, -3l);
  print_stack(s);
  printf("REM: %3ld\n", POP(s));
  printf("REM: %3ld\n", POP(s));
  PUSH(s, 3l);
  PUSH(s, -12l);
  PUSH(s, 34l);
  print_stack(s);
  printf("REM: %3ld\n", POP(s));
  printf("REM: %3ld\n", POP(s));
  printf("REM: %3ld\n", POP(s));
  printf("REM: %3ld\n", POP(s));

  return 0;
}
