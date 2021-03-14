#include <stdio.h>

int main(){
    int fd;
    fd = open("demo",O_RDONLY)
    printf("fd = %d",fd)
}