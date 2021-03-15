#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct tm *tm_ptr,timestruct;
    time_t the_time;
    char buf[256];
    char *result;

    (void) time(&the_time); // 
    printf("time=>1970->至今的秒数=%ld\n",the_time);
    tm_ptr = localtime(&the_time); // 通过调用time与localtime得到当前的本地时间
    strftime(buf,256,"%A %d %B, %H:%M:%S %p",tm_ptr);//%A星期几全称%B月份全称
    printf("strftime gives = %s\n",buf);
    strcpy(buf,"Thu 26 March 2021,17:53 will do fine");
    printf("calling strptime with :%s\n",buf);
    tm_ptr = &timestruct;

    result = strptime(buf,"%a %d %b %Y,%R",tm_ptr);
    printf("strptime consumed up to:%s\n",result);

    printf("strptime gives:\n");
    printf("date:%02d/%02d/%02d\n",tm_ptr->tm_year % 100,tm_ptr->tm_mon+1,tm_ptr->tm_mday);
}