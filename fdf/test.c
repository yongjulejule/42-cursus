#include <semaphore.h>

int main()
{
	sem_t *sem;
	
	sem = sem_open("name", O_CREAT);
	sem_post(sem);
}
