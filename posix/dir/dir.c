#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

// 目录浏览器
void printdir(char *dir,int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp = opendir(dir)) == NULL){// 检查指定目录是否存在
        fprintf(stderr,"cannot open directory:%s\n",dir);
        return;
    }
    chdir(dir); // 进入指定目录,当前目录.
    while ((entry = readdir(dp)) != NULL){ // 如果readdir返回不为空，如果是目录就递归遍历
        lstat(entry->d_name,&statbuf);
        if (S_ISDIR(statbuf.st_mode)){ // 检查是否是一个目录
            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0) // 跳过当前目录和上一级目录
            continue;
            printf("%*s%s/\n",depth,"",entry->d_name); // 如果不是，根据depth打印文件项的数据内容
            printdir(entry->d_name,depth+4); // 
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dp); // 关闭目录确保打开的目录流数目不超出其需要
}

int main(int argc, char *argv[]){
    char *topdir = "."; // 当前目录
    printf("Directory scan of %s\n",topdir);
    printdir(topdir,0);
    printf("done.\n");
    exit(0);
}