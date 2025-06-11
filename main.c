#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int	fd = open("43_no_nl", O_RDONLY);
	char	*ptr;
	int i;

	i = 0;
	while (1)
	{
	ptr = get_next_line(fd);
	if (!ptr)
	{
		close(fd);
		return (1);
	}
	printf("%s", ptr);
	free(ptr);
	ptr = NULL;
	i++;
	}
	close(fd);
	return (0);
	}
