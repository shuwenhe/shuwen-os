#include "select.h"

int main(int argc, char *argv[])
{
	int ret, i;
	char c;
	int keyboard;
	fd_set readfd;
	struct timeval timeout;

	keyboard = open("/dev/tty", O_RDONLY);
	ret = select(keyboard, &readfd, NULL, NULL, &timeout);

	printf("ret = %d\n", ret);

	if(ret == -1)
	  printf("error\n");
	else if(ret)
	if(FD_ISSET(keyboard, &readfd)){
		i = read(keyboard, &c, 1);
		if('\n' == c)
		  printf("the input is %c\n",c);
		if('q' == c)
		  printf("q = c");
	}
	else
    printf("time out\n");
}


