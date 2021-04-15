#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

void parser (char *line){
    char *delimita = "\t\n";
    
    MyStack *p = inicia_MyStack ();
    
    for (char *token = strtok(line, delimita); token != NULL; token = strtok(NULL,delimita)){
        char *sobra1;
        char *sobra2;
        
        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);
        
        if(strlen(sobra1) == 0){
                    PUSH_LONG(p, val_l);
               
        } else if(strlen(sobra2) == 0){
                    PUSH_DOUBLE(p, val_d);
                
        } else if(token[0] != '+'){
                    PUSH_STRING(p, token);
// operações
        } else if (strcmp(token, "+") == 0){
            Data x;
            if((has_type(topo(p), LONG))){
                  x = POP(p);
            }  else if((has_type(topo(p), DOUBLE))){
                  x = POP(p);
            }
        
            Data y;
            if((has_type(topo(p), LONG))){
                  y = POP(p);
            } else if((has_type(topo(p), DOUBLE))){
                  y = POP(p);
            }
               if(has_type(x, LONG) && has_type(y, DOUBLE)){
                   PUSH_LONG(p, x.LONG);
                   PUSH_DOUBLE(p, y.DOUBLE);
                  
               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
                   PUSH_DOUBLE(p, x.DOUBLE);
                   PUSH_LONG(p, y.LONG);

               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
                   PUSH_DOUBLE(p, x.DOUBLE);
                   PUSH_DOUBLE(p, y.DOUBLE);
               } else if(has_type(x, LONG) && has_type(y, LONG)){
                   PUSH_LONG(p, x.LONG);
                   PUSH_LONG(p, y.LONG);
               }
            
            
        
//        } else if (strcmp(token, "-") == 0){
//
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){
//                   Data r;
//                   r.DOUBLE = x.LONG - y.DOUBLE;
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE - y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE - y.DOUBLE;
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.LONG = x.LONG - y.LONG;
//                      PUSH_LONG (p, r);
//
//               }
//        } else if (strcmp(token, "*") == 0){
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){
//                   Data r;
//                   r.DOUBLE = x.LONG * y.DOUBLE;
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE * y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE * y.DOUBLE;
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.LONG * y.LONG;
//                      PUSH(p, r);
//               }
//
//        } else if (strcmp(token, "/") == 0){ // como fazer divisao inteira
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){
//                   Data r;
//                   r.DOUBLE = x.LONG / y.DOUBLE;
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE / y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE / y.DOUBLE;
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.LONG / y.LONG;
//                      PUSH(p, r);
//               }
//        } else if (strcmp(token, "#") == 0){
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){
//                   Data r;
//                   r.DOUBLE = pow(x.LONG, y.DOUBLE);
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = pow(x.DOUBLE, y.LONG);
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = pow(x.DOUBLE, y.DOUBLE);
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = pow(x.LONG, y.LONG);
//                      PUSH(p, r);
//               }
//
//        } else if (strcmp(token, "&") == 0){
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){
//                   Data r;
//                   r.DOUBLE = x.LONG & y.LONG;
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.LONG & y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = x.LONG & y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.LONG & y.LONG;
//                      PUSH(p, r);
//               }
//        } else if (strcmp(token, "|") == 0){
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//
//            Data y;
//            if((has_type(topo(p), LONG))){
//                  y = POP(p);
//            } else if((has_type(topo(p), DOUBLE))){
//                  y = POP(p);
//            }
//               if(has_type(x, LONG) && has_type(y, DOUBLE)){ //isto é feito so para ints, converter doubles em ints?
//                   Data r;
//                   r.DOUBLE = x.LONG / y.DOUBLE;
//                   PUSH(p, r);
//
//               } else if (has_type(x, DOUBLE) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE / y.LONG;
//                      PUSH(p, r);
//               } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)){
//                      Data r;
//                      r.DOUBLE = x.DOUBLE / y.DOUBLE;
//                      PUSH(p, r);
//               } else if(has_type(x, LONG) && has_type(y, LONG)){
//                      Data r;
//                      r.DOUBLE = x.LONG / y.LONG;
//                      PUSH(p, r);
//               }
////        } else if (strcmp(token, "^") == 0){  isto é feito so para ints, converter doubles em ints?
//
//        } else if (strcmp(token, "~") == 0){
//            Data x;
//            if((has_type(topo(p), LONG))){
//                  x = POP(p);
//            }  else if((has_type(topo(p), DOUBLE))){
//                  x = POP(p);
//            }
//            if(has_type(x, LONG)){
//                Data r;
//                r.DOUBLE = ~ x.LONG;
//                PUSH(p, r);
//
//            } else if (has_type(x, DOUBLE)){
//                   Data r;
//                r.DOUBLE = ~ x.LONG;
//                   PUSH(p, r);
//            } else if(has_type(x, DOUBLE)){
//                   Data r;
//                r.DOUBLE = ~ x.LONG;
//                   PUSH(p, r);
//            } else if(has_type(x, LONG)){
//                   Data r;
//                r.DOUBLE = ~ x.LONG;
//                   PUSH(p, r);
//            }

//        } else if (strcmp(token, "%") == 0){
//                  long x = POP(p);
//                  long y = POP(p);
//                  PUSH(p,(y%x));
//
//        } else if (strcmp(token, "(") == 0){
//                  long x = POP(p);
//                  PUSH(p, (x-1));
//
//        } else if (strcmp(token, ")") == 0){
//                  long x = POP(p);
//                  PUSH(p, (x+1));
//
//        } else if (strcmp(token, "_") == 0){
//                  long x = POP(p);
//                  PUSH(p, x);
//                  PUSH(p, x);
//
//        } else if (strcmp(token, ";") == 0){
//                  long x = POP(p);
//                  long y = POP(p);
//                  PUSH(p, y);
//
//        } else if (strcmp(token, "\\") == 0){
//            long x = POP(p);
//            long y = POP(p);
//            PUSH(p, x);
//            PUSH(p, y);
//
//        } else if (strcmp(token, "@") == 0){
//            long x = POP(p);
//            long y = POP(p);
//            long z = POP(p);
//            PUSH(p, y);
//            PUSH(p, x);
//            PUSH(p, z);
//
//        } else if (strcmp(token, "$") == 0){
//            long x = POP(p);
//            long y = POP(p);
//            PUSH(p, x);
//            PUSH(p, x);
           
        } //else if (strcmp(token, "l i") == 0){
//            Data inteiro;
//            fgets(inteiro.LONG, 1, stdin);
//            PUSH(p, inteiro);
//        }
    }
    PRINT_STACK(p);
}
