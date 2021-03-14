#include <stdio.h>
#include "list_head.h"

int main(int argc, char* argv[])
{
	filter_t *tmp;
	struct list_head *pos, *n;
	filter_t filter_head;
	int filter_i, filter_j;

	INIT_LIST_HEAD(&filter_head.list);

	for(filter_i = 10, filter_j = 35; filter_i < 40; filter_i += 5, filter_j +=5){
		tmp = (filter_t*)malloc(sizeof(filter_t));
		tmp->f_i = filter_i;
		tmp->f_j = filter_j;
		list_add(&(tmp->list), &(filter_head.list));
	}

	printf("printf the filter\n");

	list_for_each(pos, &filter_head.list){
		tmp = list_entry(pos, filter_t, list);
		printf("filter_i:%d, filter_j:%d\n", tmp->f_i, tmp->f_j);
	}

	list_for_each_safe(pos, n, ){
		
	}
}
