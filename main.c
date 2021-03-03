//
//  main.c
//  LA_ficha2
//
//  Created by Diogo Neto on 23/02/2021.

#include <stdio.h>
#include <assert.h>
#include <math.h>

int main (){
    int a,b,c;
    printf("Insira o tamanho dos lados do triangulo:\n");
    assert(scanf("%d%d%d", &a, &b, &c) == 3 );
    
    int perimetro = a + b + c;
    double sp = perimetro/2; // Sp = semiperimetro
    double area = sqrt(sp*(sp-a)*(sp-b)*(sp-c));  // Teorema de Heron

    if (((a+b) > c) && ((a+c) > b) && ((b + c) > a)) { // condição necessaria da existencia do triangulo
        
        //  verificação do TIPO do triangulo
        if (a == b && a == c) {printf("EQUILATERO "); }
        else if (a == b || a == c || b == c) { printf("ISOSCELES "); }
        else if ((a*a)==((b*b)+(c*c))||(b*b)==((a*a)+(c*c))||(c*c)==((a*a)+(b*b))) { printf("RETANGULO "); }
        else if ((a != b) && (a!=c) && (b!=c)) { printf("ESCALENO "); }
   
      printf ("%d %.2f\n", perimetro, area);
        
    }else{
        printf("INVALIDO\n");
    }
    return 0;
    }
