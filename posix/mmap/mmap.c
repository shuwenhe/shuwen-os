#include "mmap.h"

int main()
{
	char *addr;
	int fd;
	struct stat sb;

	addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	printf("addr = %p\n", &addr);

	printf("current string = %.*s\n", MEM_SIZE, addr);
	
}
