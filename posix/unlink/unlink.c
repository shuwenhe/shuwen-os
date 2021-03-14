#include "memalign.h"

int main(int argc, char *argv[])
{
	if(open("tempfile", O_RDWR) < 0)
	  printf("open error\n");

	if(unlink("tempfile") < 0)
	  printf("unlink error\n");

	printf("file unlinked \n");
	sleep(15);
	printf("done\n");
	exit(0);
}
