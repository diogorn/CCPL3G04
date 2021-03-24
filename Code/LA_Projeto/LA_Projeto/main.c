#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "stack.h"

#define SIZE 10240


int main() {
    
    char MyStack[SIZE];
    
    assert( fgets(MyStack, SIZE, stdin) != NULL); // le a srting
    assert( MyStack[strlen(MyStack) - 1] == '\n'); // ve se o ultimo caractrer é \n
    
    parser(MyStack);
    return 0;
}
