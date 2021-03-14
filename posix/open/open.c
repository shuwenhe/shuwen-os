#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 7

int main()
{
	int fd;
	int flags = 7;
	char *buff = "test123";
	char buff1[SIZE];
	//char *buff1;
	size_t count = 7;

//	creat("test123.txt", 00700);
	fd = open("test123.txt", O_RDWR);
//	write(fd, buff, 7);
//	sleep(2);
	read(fd, buff1, count);
	printf("buff1 = %s\n", buff1);
}
