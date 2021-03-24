#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define T    10240

typedef struct {
  long a[T]; // Array que armazena os elementos da stack
  int pos; // Nº de elementos  na stack (e indiretamente a sua posição)
} STACK;

void inicia_Stack (MyStack *p){
    p->top = -1;
    
}

int vazia (MyStack *p){
    if(p->top == -1){
        return 1;
    } else {
        return 0;
    }
}

int cheia (MyStack *p){
    if(p->top == T-1){
        return 1;
    } else {
        return 0;
    }
}

void PUSH (MyStack *p, int x){
    if(cheia(p) == 1){
        printf ("Pilha Cheia!");
    } else {
        p->top++;
        p->a[p->top] = x; //vamos guardar a variavel x e guardar dentro da pilha na posição topo
    }
}

int POP (MyStack *p){
    int aux; // recebe o valor da pilha para depois retornar
    if(vazia(p) == 1){
        printf ("Pilha Vazia!");
    } else {
        aux = p->a[p->top];
        p->top--;
    }
    return aux;
}
