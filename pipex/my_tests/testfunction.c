void	check_argv(char **argv)
{
	char *testset[30];

	testset[0] = ft_strdup("/usr/bin/awk");
	testset[1] = ft_strdup("{printf\"%s\", $1}");
	testset[2] = NULL;
	while (*argv)
		ft_putendl_fd(*argv++, 1);
	execve("/usr/bin/awk", testset, NULL);
}
