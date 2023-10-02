#include <stdio.h>
#include <stdlib.h>

int main(){

    //ripasso puntatori

    int* p, q;
    int a, b;

    a = 5;

    p = &a;

    b = *p;

    q = b;

    printf ("%d\n", b);
    printf ("%p %p", p, &b);

    if (q == p){
        printf ("sono uguali")
    }else{

        printf("non sono uguali");

    }


}