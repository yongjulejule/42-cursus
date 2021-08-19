#include "../includes/bonus/ft_pipex_bonus.h"

int main(int argc, char **argv, char **envp)
{
	char *test[100];

	test[0] = ft_strdup("/usr/bin/man");
	test[1] = ft_strdup("ls");
	test[2] = NULL;
	execve("/usr/bin/man", test, NULL);
}
