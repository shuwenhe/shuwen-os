#include <stdio.h>

int main(int argc, char const *argv[]){
    int i;

    for (i = 0; i < 10; i++)
        printf("%d %d %d\n",i,power(2,i),power(-3,i));
    
    return 0;
}

int power(int base, int n){
    int i, p = 1;

    for (i = 0; i < n; i++)
        p *= base;    

    return p;
}