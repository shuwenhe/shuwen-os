#include<stdlib.h>
#include<stdio.h>

extern char **environ;

int main(){
    char **env = environ; // 一个以null结尾的字符串数组

    while (*env){ // 遍历environ变量
        printf("%s\n",*env); // 打印出整个环境
        env++;
    }
    exit(0);
}