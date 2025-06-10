#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("der_panther", O_RDONLY);
	char *to_print;
	int i = 0;

	while (1)
	{
		to_print = get_next_line(fd);
		if(!to_print)
		{
			printf("It's NULL!");
			break ;
		}
		printf("%s", to_print);
		free(to_print);
		to_print = NULL;
		i++;
	}
	close(fd);
	return(0);
}