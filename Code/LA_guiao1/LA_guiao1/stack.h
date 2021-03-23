#ifndef STACK_H
#define STACK_H_INCLUDED

#define T 10240

typedef struct{
    int a[T];
    int top;
} MyStack;

int inicia_Stack (MyStack *p);
int vazia (MyStack *p);
int cheia (MyStack *p);
void push (MyStack *p, int x);
int pop (MyStack *p);


#endif // STACK_H_INCLUDED
