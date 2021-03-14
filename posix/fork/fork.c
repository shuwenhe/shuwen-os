#include "memalign.h"

int main()
{
	pid_t pid;

	pid = fork();

	printf("pid = %d\n", pid);

	if(pid = fork() < 0)
	  printf("error\n");
	else{
		usleep(500000);
	  printf("success\n");
	}
	printf("pid = %d\n", pid);
}
