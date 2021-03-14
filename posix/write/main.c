#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    long size;
    if (write(1,"Here is some data\n",18) != 18){
        size = write(1,"hello\n",5);
        printf("size = %d\n",size);
        write(2,"A write error has occurred on file descriptor 1\n",46);
    }
    exit(0);
}