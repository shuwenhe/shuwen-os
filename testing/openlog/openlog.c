#include "memalign.h"
#include <syslog.h>

int main(int argc, char *argv[])
{
	openlog("test_log", LOG_CONS | LOG_PID, LOG_USER);
	syslog(LOG_INFO, "This is a massage just for test\n");
	closelog();
	return 0;
}
