#include <sys/utsname.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// 主机信息
int main(){ 
    char computer[256];
    struct utsname uts;

    if (gethostname(computer,255) != 0 || uname(&uts)){
        fprintf(stderr,"Could not get host information\n");
        exit(1);
    }

    printf("Computer host name is %s\n",computer);
    printf("System is %s on %s hardware\n",uts.sysname,uts.machine);
    printf("Nodename is %s \n",uts.nodename);
    printf("Version is %s,%s\n",uts.release,uts.version);
}