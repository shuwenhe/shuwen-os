#include "include/copy.h"

int main()
{
	int fd, n;
	char *buff = "creat-open-write-read";
	char buff2[4096];

	creat("test.txt", 21);
	fd = open("test.txt", 21);
	write(fd, buff, 21);
	printf("buff = %s\n", buff);
	n = read(fd, buff2, 2);
  printf("buff2 = %s\n", buff2);
}

