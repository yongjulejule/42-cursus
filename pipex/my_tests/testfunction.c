#include "../includes/mandatory/ft_pipex.h"

//void	check_argv(char **argv)
//{
//	char *testset[30];
//	testset[0] = ft_strdup("/usr/bin/find");
//	testset[1] = ft_strdup(".");
//	testset[2] = ft_strdup("-type");
//	testset[3] = ft_strdup("f");
//	testset[4] = ft_strdup("\( -name \"#*#\" -o name \"*~\" -o name \"#\" \)");
//	testset[5] = ft_strdup("exec rm -v {};");
//	testset[6] = NULL;
//	while (*argv)
//		ft_putendl_fd(*argv++, 1);
//	execve("/usr/bin/find", testset, NULL);
//}
int main(int argc, char **argv, char **envp)
{
	while (*envp)
		ft_putendl_fd(*envp++, 1);
//	check_argv(argv);
}
