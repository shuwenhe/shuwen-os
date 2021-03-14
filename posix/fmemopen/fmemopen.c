#include "memalign.h"

#define BSZ 48

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ-2);
	buf[BSZ - 2] = '\0';
	buf[BSZ - 1] = 'x';
	if((fp = fmemopen(buf, BSZ, "w+")) == NULL)
	  printf("fmemopen failed\n");
	printf("initial buffer contents: %s\n",buf);
	fprintf(fp, "hello, world");
	//printf("before flush : %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	//memset(buf, 'b', BSZ - 2);
	//buf[BSZ - 2] = '\0';
	//buf[BSZ - 1] = 'X';
	//printf(fp, "hello, world");
}

