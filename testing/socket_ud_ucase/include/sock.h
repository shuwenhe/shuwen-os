#include <sys/un.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SV_SOCK_PATH "/tmp/ud_ucase"

#define BUF_SIZE 100
