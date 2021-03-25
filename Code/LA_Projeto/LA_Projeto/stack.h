#define SIZE 10240

typedef struct{
    long a[SIZE];
    int topo;
} MyStack;

MyStack inicia_Stack ();
void PRINT_STACK(MyStack *p);
int vazia (MyStack p);
int cheia (MyStack p);
void PUSH (MyStack *p, long x);
int POP (MyStack *p);
