#include "include/copy.h"

int main(int argc, char *argv[])
{
	int input_fd, output_fd, open_flags;
	mode_t file_perms;
	ssize_t num_read;
	char buf[BUF_SIZE];

	if(argc != 3 || strcmp(argv[1], "--help") == 0)
	  printf("%s old file new file \n", argv[0]);
	
	input_fd = open("test.txt", O_RDONLY);

	if(input_fd == -1)
	  printf("opening file %s\n", argv[1]);

	open_flags = open("test.txt", open_flags, file_perms);
	if(output_fd == -1)
	  printf("opening file %s", argv[2]);

	while((num_read = read(input_fd, buf, BUF_SIZE)) > 0 )
	  if(write(output_fd, buf, num_read) != num_read)
		  printf("couldn't write whole buffer\n");

	if(num_read == -1)
	  printf("read error\n");

	if(close(input_fd) == -1)
	  printf("close input error\n");

	if(close(output_fd) == -1)
	  printf("close output error\n");
}

