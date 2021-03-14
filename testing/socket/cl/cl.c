#include "../include/sock.h"

int main(int argc, char *argv[])
{
	struct sockaddr_un svaddr, claddr;
	int sfd, j;
	size_t msg_len;
	ssize_t num_bytes;
	char resp[BUF_SIZE];

	if(argc < 2 || strcmp(argv[1], "--help") == 0)
	  printf("%s msg...\n", argv[0]);


	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if(sfd == -1)
	  printf("socket error\n");

	memset(&claddr, 0, sizeof(struct sockaddr_un));
	claddr.sun_family = AF_UNIX;
	snprintf(claddr.sun_path, sizeof(claddr.sun_path), "/tmp/ud_ucase_cl.%ld", (long)getpid());

	if(bind(sfd, (struct sockaddr *)&claddr, sizeof(struct sockaddr_un)) == -1)
	  printf("bind error！\n");

	memset(&svaddr, 0, sizeof(struct sockaddr_un));
	svaddr.sun_family = AF_UNIX;
	strncpy(svaddr.sun_path, SV_SOCK_PATH, sizeof(svaddr.sun_path) - 1);

	for(j = 1; j < argc; j++){
		msg_len = strlen(argv[j]);
		if(sendto(sfd,argv[j], msg_len, 0, (struct sockaddr *) &svaddr, sizeof(struct sockaddr_un)) != msg_len)
		  printf("sendto error");
		num_bytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
		if(num_bytes == -1)
		  printf("recvfrom error\n");
		printf("response %d:%.*s\n, j, (int)num_bytes, resp");
	}

	remove(claddr.sun_path);
	exit(EXIT_SUCCESS);

}
