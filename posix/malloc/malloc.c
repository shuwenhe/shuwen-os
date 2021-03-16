#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define A_MEGABYTE (1024*1024)

int main(){
	char *some_memory;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE;

    some_memory = (char *)malloc(megabyte); // malloc函数返回值是一个void *指针，需要类型转换成我们需要的char *类型
	if (some_memory != NULL){
		sprintf(some_memory,"Hello world\n");
		printf("%s",some_memory);
		exit_code = EXIT_SUCCESS;
	}
	exit(exit_code);
}
