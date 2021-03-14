#include "memalign.h"
#include <string.h>

int main(int argc, char *argv[])
{
	const char src[50] = "http://www.github.com";
	char dest[50];

	//memcpy(dest, src, sizeof(src));
	//memcpy(dest, src, 7);
	memcpy(dest, src, strlen(src));
	printf("dest = %s\n", dest);
	return 0;
}
