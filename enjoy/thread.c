#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "printf/libft/libft.h"

int sum = 0;
void *runner(void *param);

void	*runner(void *param)
{
	int j =0;
	int i, upper = atoi(param);
	for (i = 1; i <= upper; i++)
		sum += i;
	while(j < 30)
	{
//		ft_putnbr_fd(j, 1);
		printf("%d\n", j);
		sleep(1);
		j++;
	}

	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_t tid_2;
	pthread_t tid_3;
	pthread_t tid_4;
	pthread_t tid_5;
	pthread_t tid_6;
	pthread_t tid_7;
	pthread_t tid_8;
	pthread_t tid_9;
	pthread_t tid_10;
	pthread_t tid_11;
	pthread_t tid_12;
	pthread_t tid_13;
	pthread_t tid_14;
	pthread_t tid_15;
	pthread_attr_t attr;
	if (argc != 2)
	{
		fprintf(stderr, "usage: a.out <integer value>\n");
	}
	if (atoi(argv[1]) < 0)
	{
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return(-1);
	}
	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_create(&tid_2, &attr, runner, argv[1]);
	pthread_create(&tid_3, &attr, runner, argv[1]);
	pthread_create(&tid_4, &attr, runner, argv[1]);
	pthread_create(&tid_5, &attr, runner, argv[1]);
	pthread_create(&tid_6, &attr, runner, argv[1]);
	pthread_create(&tid_7, &attr, runner, argv[1]);
	pthread_create(&tid_8, &attr, runner, argv[1]);
	pthread_create(&tid_9, &attr, runner, argv[1]);
	pthread_create(&tid_10, &attr, runner, argv[1]);
	pthread_create(&tid_11, &attr, runner, argv[1]);
	pthread_create(&tid_12, &attr, runner, argv[1]);
	pthread_create(&tid_13, &attr, runner, argv[1]);
	pthread_create(&tid_14, &attr, runner, argv[1]);
	pthread_create(&tid_15, &attr, runner, argv[1]);

	pthread_join(tid, NULL);
	pthread_join(tid_2, NULL);
	pthread_join(tid_3, NULL);
	pthread_join(tid_4, NULL);
	pthread_join(tid_5, NULL);
	pthread_join(tid_6, NULL);
	pthread_join(tid_7, NULL);
	pthread_join(tid_8, NULL);
	pthread_join(tid_9, NULL);
	pthread_join(tid_10, NULL);
	pthread_join(tid_11, NULL);
	pthread_join(tid_12, NULL);
	pthread_join(tid_13, NULL);
	pthread_join(tid_14, NULL);
	pthread_join(tid_15, NULL);
	printf("sum = %d\n", sum);

}
