#include "../include/sock.h"

int main()
{
	struct sockaddr_un addr;
	int sfd;
	ssize_t num_read;
	char buf[BUF_SIZE];

	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sfd == -1)
	  printf("socket error\n");

	memset(&addr, 0 ,sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

	if(connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
	  printf("connect error！\n");

	while((num_read = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	  if(num_read == -1)
		  printf("partial/failed write!\n");
	exit(EXIT_SUCCESS);

}
