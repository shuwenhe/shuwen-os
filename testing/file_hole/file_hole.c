#include "memalign.h"
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
	int fd, r;
	char *buf3;

	//if((fd = creat("file.hole", FILE_MODE)) < 0) //?
	if((fd = creat("file.hole", 0777)) < 0)
	  printf("create error");
	else
	  printf("creat file.hole success\n");

	if(write(fd, buf1, 10) != 10)
	  printf("buf1 write error\n");

	if(lseek(fd, 16384, SEEK_SET) == -1)
	  printf("lseek error\n");

	if(write(fd, buf2, 10) != 10)
	  printf("buf2 write error\n");

	r = read(fd, buf3, 10);

  printf("r = %d\n", r);

	exit(0);
}
