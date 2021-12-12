#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int		fd;
	int		buf;
	int		i;

	i = 0;
	buf = 100;
	 //printf("ff");
	fd = open("beh.txt", O_RDWR);
	// printf("%s", get_next_line(fd));
	// // printf("ff");
	// printf("%s", get_next_line(fd));
	// //printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}