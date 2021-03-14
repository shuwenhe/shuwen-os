#include "../include/sock.h"

#define BACKLOG 5

int main()
{
	struct sockaddr_un addr;
	int sfd, cfd;
	ssize_t num_read;
	char buf[BUF_SIZE];

	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sfd == -1)
	  printf("sv socket error! sfd == -1 !\n");
	if(remove(SV_SOCK_PATH) == -1)
	  printf("sv socket error!SV_SOCK_PATH == -1 !\n");

	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

	if(bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
	  printf("bind error!\n");
	
	if(listen(sfd, BACKLOG) == -1)
	  printf("listen error!\n");
	
	for(;;){
		cfd = accept(sfd ,NULL, NULL);
		if(cfd == -1)
		  printf("accept error!");

		while((num_read = read(cfd, buf, BUF_SIZE)) > 0)
		  if(write(STDOUT_FILENO, buf, num_read) != num_read)
			  printf("partial/failed write!");
	}
}
