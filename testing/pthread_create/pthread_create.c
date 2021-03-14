#include "pthread_create.h"

void thread_func()
{

}

int main()
{
	pthread_t t1;
	int s;

	s = pthread_create(&t1, NULL, thread_func, "hello\n");
}

