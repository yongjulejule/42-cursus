#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>

extern int errno;
int main()
{
	printf("%ld\n", write(1, "jis", 3));
	perror("fitst");
	errno = 0;
	printf("%ld\n", write(-1, "jis", 3));
	perror("second");
	errno = 0;
	printf("%ld\n", write(1, "babo", 4));
	perror("thrid");
	errno = 0;
}
