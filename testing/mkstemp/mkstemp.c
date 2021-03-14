#include "memalign.h"


int main(int argc, char *argv[])
{
	char good_template[] = "/tmp/dir123";
	char *bad_template = "/tmp/dir123";

	printf("trying to create first temp file...\n");
	make_temp(good_template);
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
	exit(0);
}

void make_temp(char *template)
{
	int fd;
	struct stat sbuf;

	if((fd = mkstemp(template)) < 0)
	  printf("can't create temp file\n");

	printf("temp name = %s\n", template);
	close(fd);
	if(stat(template, &sbuf) < 0){
		if(errno == ENOENT)
		  printf("file doesn't exist\n");
		else
		  printf("stat failed\n");
	}else{
		printf("file exists\n");
		unlink(template);
	}
}
