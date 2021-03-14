#include "setsid.h"

int main()
{
	if(fork() != 0)
	 printf("exit success\n");

	if(setsid() == -1)
	  printf("setsid\n");

	printf("PID=%ld, PGID = %ld, SID = %ld\n", (long)getpid(),(long)getpgrp(),(long)getsid(0));

	if(open("/dev/tty", O_RDWR) == -1)
	  printf("open /dev/tty\n");
}
