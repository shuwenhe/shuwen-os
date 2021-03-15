#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    uid_t uid;
    uid = getuid();
    printf("uid = %d\n",uid);
}