#ifndef STACK_H
#define STACK_H_INCLUDED

#define T 10240

typedef struct{
    int a[T];
    int top=-1;
} MyStack;

void inicia_Stack (MyStack *p);
int vazia (MyStack *p);
int cheia (MyStack *p);
void PUSH (MyStack *p, int x);
int POP (MyStack *p);


#endif // STACK_H_INCLUDED
