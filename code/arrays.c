#include <string.h>
#include <stdlib.h>

#include "arrays.h"
#include "stack.h"
#include "math.h"

#include "parser.h"


//
void cria_array(MyStack *p, int array_size){
    Data a;
    a.tipo = ARRAY;
    a.ARRAY->size = array_size;
    a.ARRAY->n_elementos = malloc(sizeof(struct TipoDados) * array_size) ;
}


//  y        x
//           y x
// [ 1 2 ] [ 3 4 ] \  -> [ 3 4 ] [ 1 2 ]

