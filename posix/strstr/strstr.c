#include "memalign.h"
#include <string.h>

int main(int argc, char *argv[])
{
	char *s = "st1r234st9r";
	char *l = "1r234";
	char *p;
	char string[] = {"string123"};

	printf("string = %s\n", string);


	p = strstr(s, l);

	printf("s = %s\n", s);
	printf("l = %s\n", l);

	if(p)
	  printf("p = %s\n", p);
	else
	  printf("not found\n");
}
