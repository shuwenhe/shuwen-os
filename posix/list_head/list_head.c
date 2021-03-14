#include <stdio.h>
#include "list_head.h"

int main(int argc, char* argv[])
{
	person_t *tmp;
	struct list_head *pos, *n;
	int age_i, weight_j;
	char sex_k;

	person_t person_head;

	INIT_LIST_HEAD(&person_head.list);
	
	for(age_i = 10, weight_j = 35; age_i < 40; age_i += 5, weight_j += 5){
		tmp =(person_t*)malloc(sizeof(person_t));
		tmp->age = age_i;
		tmp->weight = weight_j;
		list_add(&(tmp->list), &(person_head.list)); 
	}

	printf("print the list\n");

	list_for_each(pos, &person_head.list){
		tmp = list_entry(pos, person_t, list); 
		printf("age:%d,  weight: %d, sex: %s \n", tmp->age, tmp->weight, tmp->sex);
	}

	printf("print list after delete a node which age is 20\n");
	list_for_each_safe(pos, n, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		if(tmp->weight == 50 || tmp->age == 30 || tmp->age == 20 || tmp->age == 10){
			list_del_init(pos);
			free(tmp);
		}
	}

	list_for_each(pos, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		printf("age:%d,  weight: %d, sex: %s \n", tmp->age, tmp->weight, tmp->sex);
	}

	list_for_each_safe(pos, n, &person_head.list){
		tmp = list_entry(pos, person_t, list);
		list_del_init(pos);
		free(tmp);
	}
	return 0;
}
