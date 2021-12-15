//#include "get_next_line.h"
#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int	*fd;

	fd[0] = open("gnlTester/files/41_with_nl", O_RDWR);
	fd[1] = open("gnlTester/files/42_with_nl", O_RDWR);
	fd[2] = open("gnlTester/files/43_with_nl", O_RDWR);
	fd[3] = open("gnlTester/files/nl", O_RDWR);

	printf("%s", get_next_line(fd[0]));
	// printf("%s", get_next_line(fd[1]));
	// printf("%s", get_next_line(fd[2]));
	// printf("%s", get_next_line(fd[3]));
	// printf("%s\n", get_next_line(fd[0]));
	// printf("%s\n", get_next_line(fd[1]));
	// printf("%s\n", get_next_line(fd[2]));
	// printf("%s", get_next_line(fd[3]));
	// // printf("%s", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// check_leaks();
	return (0);
}