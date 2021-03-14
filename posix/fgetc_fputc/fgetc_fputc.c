#include "memalign.h"

#define MAXLINE 5

int main(int argc, char *argv[])
{
	char buf[MAXLINE];

	while(fgets(buf, MAXLINE, stdin) != NULL)
	  if(fputs(buf, stdout) == EOF)
		  printf("output error");

	if(ferror(stdin))
	  printf("input error");

	exit(0);
}
