#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define SIZE 10240

MyStack inicia_Stack (){
    MyStack p;
    p.topo = -1;
    return p;
}

int vazia (MyStack p){
    if(p.topo == -1){
        return 1;
    } else {
        return 0;
    }
}

int cheia (MyStack p){
    if(p.topo == SIZE-1){
        return 1;
    } else {
        return 0;
    }
}

void PUSH (MyStack p, long x){
    if(cheia(MyStack p) == 1){
        printf ("Pilha Cheia!");
    } else {
        p.topo++;
        p.a[p.topo] = x; //vamos guardar a variavel x e guardar dentro da pilha na posição topo
    }
}

int POP (MyStack p){
    int aux; // recebe o valor da pilha para depois retornar
    if(vazia (MyStack p) == 1){
        printf ("Pilha Vazia!");
        return 
    } else {
        aux = p.a[p.topo];
        p.topo--;
        return aux;
    }
}

 // porque é que está a pedir uma expressão antes no MyStack na linha 28 e 38
