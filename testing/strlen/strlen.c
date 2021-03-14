#include "memalign.h"
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	char *s = "str234st9r";
	char *l = "r";
	char *p;
	char arr[] = "abc123";
	char arr1[] = "abc123";
	char arr2[] = "abc123";
	char str1[15];
	char str2[15];
	int ret;

	if(current->parent)
	  printf("current->parent");
	else
	  printf("error");

	strcpy(str1, "aBc111");
	strcpy(str2, "aBCaaa");

	ret = strncmp(str1, str2, 6);

	if(ret < 0)
	  printf("str1 < str2\n");
	else if(ret > 0)
	  printf("str1 > str2\n");
	else
	  printf("str1 = str2\n");

	p = strstr(s, l);
	i = strlen(arr);
	printf("i = %d\n", i);

	if(!strlen(arr)||
				!strlen(arr1) ||
				!strlen(arr2)
				){
		printf("error\n");
	}else{
		printf("success\n");
	}

	if(p)
	  printf("%s\n", p);
	else
	  printf("not found\n");
}
