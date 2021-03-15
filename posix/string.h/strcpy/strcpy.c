#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>m

int main(){
    struct tm *tm_ptr,timestruct;
    time_t the_time;
    char buf[256];
    char *result;

    (void) time(&the_time);
    tm_ptr = localtime(&the_time);
    strftime(buf,256,"%A %d %B, %H:%M:%S %p",tm_ptr);//%A星期几全称%B月份全称
    printf("strftime gives = %s\n",buf);
    strcpy(buf,"Thu 26 March 2021,17:53 will do fine");
}