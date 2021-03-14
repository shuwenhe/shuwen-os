#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Please input string less 128 bytes:\n");
    int nread; // read的返回值：实际读入的字节数，可能会小于请求的字节数
    char buffer[128];
    // 如果read调用返回0：表示未读入任何数据，已达到了文件尾
    // 系统调用read的作用：从与文件描述符fildes相关联的文件里读入nbytes个字节的数据，并把它们放到数据区buf中
    // ssize_t	 read(int, void *, size_t) __DARWIN_ALIAS_C(read);
    // 第一个参数：fildes文件描述符
    // 第二个参数：*buf放数据区
    // 第三个参数：读入nbytes个字节
    nread = read(0,buffer,128);
    printf("nread = %d\n",nread);
    if (nread == -1) {// 返回-1表示read调用出现错误
    // ssize_t	 write(int __fd, const void * __buf, size_t __nbyte) __DARWIN_ALIAS_C(write);
        write(2,"A read error has occurred\n",26);
    }
    if ((write(1,buffer,nread)) != nread){
        write(2,"A write error has occurred\n",27);
    }
    // void	 exit(int) __dead2;
    exit(0);
}