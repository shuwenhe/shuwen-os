#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    char block[1024];
    int in,out;
    int nread;
    // int     open(const char *, int, ...) __DARWIN_ALIAS_C(open);
    in = open("file.in",O_RDONLY);
    out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    // ssize_t	 read(int, void *, size_t) __DARWIN_ALIAS_C(read);
    while ((nread == read(in,block,sizeof(block)))>0)
    // ssize_t	 write(int __fd, const void * __buf, size_t __nbyte) __DARWIN_ALIAS_C(write);
    write(out,block,nread);
}