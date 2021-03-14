#include "creat.h"

int main()
{
	int fd, w;

	fd = creat("test123.txt", 0777);
	printf("fd = %d\n", fd);

	if(fd < 0)
	  printf("creat error");

	w = write(fd, buf1, 12);
	printf("w = %d\n", w);

	if(w != 12)
	  printf("buf1 write error\n");

	if(lseek(fd, 16, SEEK_SET) == -1)
	  printf("lseek error\n");

	if(write(fd, buf2, 10) != 10)
	  printf("buf2 write error\n");

	exit(0);
}
