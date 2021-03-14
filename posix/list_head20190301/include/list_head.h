#include "list.h"  
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include<linux/sched.h>
#include<linux/sem.h>

typedef struct filter_s{
  int f_i, f_j;
	struct list_head list;

}filter_t;
