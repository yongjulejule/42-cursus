#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

extern int errno;

int main(int argc, char **argv)
{
	int ret;

	ret = access(argv[1], R_OK);
	printf("R_OK return is :%d\n", ret);
	printf("errno is :%d\n", errno);
	errno = 0;
	ret = access(argv[1], W_OK);
	printf("W_OK return is :%d\n", ret);
	printf("errno is :%d\n", errno);
	errno = 0;
	ret = access(argv[1], X_OK);
	printf("X_OK return is :%d\n", ret);
	perror("error!!!!");
	printf("errno is :%d\n", errno);
	errno = 0;
	ret = access(argv[1], F_OK);
	printf("F_OK return is :%d\n", ret);
	perror("error!!!!");
	printf("errno is :%d\n", errno);
	errno = 0;
	ret = access(argv[1], R_OK | W_OK);
	printf("R_OK | W_OK return is :%d\n", ret);
	perror("error!!!!");
	char *error = strerror(errno);
	printf("%s\n", error);
	printf("errno is :%d\n", errno);
	errno = 0;
	ret = access(argv[1], R_OK | X_OK);
	printf("R_OK | X_OK return is :%d\n", ret);
	printf("R_OK | X_OK return is :%d\n", ret);
	printf("errno is :%d\n", errno);
	unlink(argv[1]);
}
