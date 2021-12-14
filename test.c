#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int		fd;
	int		buf;
	int	i;

	i = 0;
	buf = 100;
	 //printf("ff");
	// check_leaks();
	fd = open("beh.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// check_leaks();
	return (0);
}