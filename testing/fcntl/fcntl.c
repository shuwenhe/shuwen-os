#include "read.h"

#define BUFFSIZE 4096

int main()
{
	int r, w;
	char buf[BUFFSIZE];

	r = read(STDIN_FILENO, buf, BUFFSIZE);
	w = write(STDOUT_FILENO, buf, r);

	while(r > 0)
	  if(w != r)
		  printf("write error");
	if(r < 0)
	  printf("read error\n");
	exit(0);
}
