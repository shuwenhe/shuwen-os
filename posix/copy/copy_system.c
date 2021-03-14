#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    char c;
    int in,out;
    // int     open(const char *, int, ...) __DARWIN_ALIAS_C(open);
    in = open("file.in",O_RDONLY); // 只读方式打开
    out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);// 只写的方式打开；创建文件；读权限文件属主
    // ssize_t	 read(int, void *, size_t) __DARWIN_ALIAS_C(read);
    while (read(in,&c,1) == 1)
    // ssize_t	 write(int __fd, const void * __buf, size_t __nbyte) __DARWIN_ALIAS_C(write);
    write(out,&c,1);
    // void	 exit(int) __dead2;
    exit(0);
}