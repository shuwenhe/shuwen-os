#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define _GNU_SOURCE //getopt.h头文件必须与 _GNU_SOURCE一同包含进来，该常量启动getopt_long功能
#include <getopt.h> // getopt_long

int main(int argc,char *argv[]){
    int opt; 
    struct option longopts[] = { // 描述长选项并告诉getopt_long如何处理它们
        {"initialize",0,NULL,'i'},
        {"file",1,NULL,'f'},
        {"list",0,NULL,'1'},
        {"restart",0,NULL,'r'},
        {0,0,0,0},
    };
    while ((opt = getopt_long(argc,argv,":if:lr",longopts,NULL))!=-1){ // NULL是变量指针
        switch (opt)
        {
        case 'i':
        case 'l':
        case 'r':
        printf("option:%c\n",opt);
        break;
        case 'f':
        printf("filename:%s\n",optarg);
        break;
        case':':
        printf("option needs a value\n");
        break;
        case'?':
        printf("unknown option:%c\n",optopt);
        break;
        }
    }
    for (; optind < argc; optind++){
        printf("argument:%s\n",argv[optind]);
        exit(0);
    }
}