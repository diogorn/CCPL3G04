#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "stack.h"


#define PUSH(s, val)        \
  printf("ADD: %2ld\n", val); s.array[s.pos++] = val;

#define POP(s)              \
  s.array[--s.pos]

void print_stack(MyStack s) {
  printf("Stack: ");
  for(int k = 0; k < s.top; k++)
    printf("\t%3d", s.a[k]);
  printf("\n");
}

int main() {
 
    char array[3] = {5,4,'-'};
    
    int i=0;
    while (i!=3){
        MyStack p = inicia_Stack(array[i]);
        i++;
    }
  return 0;
}

