#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int i;
    
    time_t the_time; // 以秒数计算的时间和日期

    for (i = 0; i < 10; i++){ // 共调用10次
        the_time = time((time_t *)0); // 用空指针参数调用time函数
        printf("The time is %ld\n",the_time); // 从1970年Unix系统元年开始的秒数表示时间和日期
        sleep(1); // 休眠1秒
    }
}