#include "memalign.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	  printf("usage : a.out <pathname>\n");
	if(access(argv[1], R_OK) < 0)
	  printf("access error for %s", argv[1]);
	else
	  printf("read access ok\n");
	if(open(argv[1], O_RDONLY) < 0)
	  printf("open error for %s\n", argv[1]);
	else
	  printf("open for reading ok\n");

	exit(0);
}
