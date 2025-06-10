#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int i = 0;

	fd = open("der_panter", O_RDONLY);
	char *to_print = get_next_line(fd);
	while (to_print)
	{
		printf("%s\n", to_print);
		free(to_print);
		to_print = get_next_line(fd);
		i++;
	}
}
