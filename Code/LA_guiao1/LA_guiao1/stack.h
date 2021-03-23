#define STACK_H_INCLUDED

#define T 10240

typedef struct{
    typedef struct{
    int a[T];
    int top;
} MyStack;

void inicia_Stack (MyStack *p);
int vazia (MyStack p*);
int cheia (MyStack *p);
void push (MyStack *p, int x);
int pop (MyStack *p);


#endif // STACK_H_INCLUDED
