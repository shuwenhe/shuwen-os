#include "include/copy.h"

int main()
{
	int fd;
	char buff[8];

	fd = open("test.txt", 8);
	read(fd, buff, 8);
  printf("buff = %s", buff);
}

