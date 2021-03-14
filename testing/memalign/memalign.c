#include "memalign.h"

int main()
{
	mystruct_t *p;

	p = calloc(1000, sizeof(struct mystruct_s)); 
	if(p == NULL)
	  printf("error\n");
  else
	  printf("calloc\n");
}
