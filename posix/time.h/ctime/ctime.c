#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    time_t timeval;
    printf("timeval = %ld\n",timeval);
    (void)time(&timeval);
    printf("timeval = %ld\n",timeval); // 1970=>至今的秒数
    printf("The date is = %s",ctime(&timeval)); // ctime 时间值=>字符串
    exit(0);
}