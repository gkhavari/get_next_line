#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int i = 0;

	fd = open("der_panter", O_RDONLY);
	while (i < 10)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
}
