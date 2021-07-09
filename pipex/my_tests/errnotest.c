#include "../ft_pipex.h"

int main(void)
{
	pid_t pid;
	errno = 0;

	pid = fork();
	if (pid > 0)
	{
		int status;
		wait(&status);
		printf("pa errno is : %d\n", errno);
	}
	if (pid == 0)
	{
		perror("aa");
		printf("%dch errno is :", errno);
	}
}
