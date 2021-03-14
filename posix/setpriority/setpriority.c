#include "setpriority.h"


int main(int argc, char *argv[])
{
	int which, prio;
	id_t who;

	if(argc != 4 || strchr("pgu", argv[1][0]) == NULL)
	  printf("%s{p|g|u} who priority\n");

	which = (argv[1][0] == 'p') ? PRIO_PROCESS :(argv[1][0] == 'g') ? PRIO_PGRP : PRIO_USER;

	who = get_long(argv[2], 0, "who");

	if(setpriority(which, who, prio) == -1)
	  printf("getpriority\n");


}

long get_long(const char *arg, int flags, const char *name)
{
	return get_num("get long", arg, flags, name);
}
