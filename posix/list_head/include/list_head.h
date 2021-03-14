#include "list.h"  
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include<linux/sched.h>
#include<linux/sem.h>

typedef struct person_s{
	int age;
	int weight;
	char sex;
	struct list_head list;
}person_t;
