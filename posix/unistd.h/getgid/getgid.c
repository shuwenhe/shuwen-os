#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    gid_t gid;
    gid = getgid();
    printf("uid = %d\n",gid);
}