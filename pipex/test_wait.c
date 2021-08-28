#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/errno.h>

int main()
{
	pid_t pid;
	char *tmp[10];
	extern int errno;

	pid = fork();
	if (pid == 0)
	{
		tmp[0] = strdup("/bin/sleep");
		tmp[1] = strdup("3");
		tmp[2] = NULL;
		if (execve(tmp[0], tmp, NULL) == -1)
			perror(strerror(errno));
	}
	else
	{
		fprintf(stderr, "before_wait\n");
		waitpid(-1, NULL, 0);
		fprintf(stderr, "after_wait\n");
	}
}
