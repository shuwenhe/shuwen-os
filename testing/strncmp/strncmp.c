#include "memalign.h"
#include <string.h>

int main(int argc, char *argv[])
{
	char *s1 = "st3r234st9r";
	char *s2 = "st3r2";
	int i;

	//i = strncmp(s1, s2, 2);
	//i = strncmp(s1, s2, strlen(s1));
	i = strncmp(s1, s2, strlen(s2));
	if(i > 0)
	  printf("s1 > s2\n");
	else if(i < 0)
	  printf("s1 < s2\n");
	else
	  printf("s1 = s2\n");
}
