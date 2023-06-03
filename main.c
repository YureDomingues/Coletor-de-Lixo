#include "contref.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a = (int*) malloc2(sizeof(int));
    int *b;
    while(1){
        b = malloc2(sizeof(int));
        atrib2(&b, a);
        print_lixo();
        dump();
    }

    return 0;
};