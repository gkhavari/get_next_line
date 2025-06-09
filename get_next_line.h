#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>

char *get_next_line(int fd);
size_t ft_strlen(char *str);
char *ft_substr(char *str, size_t start, size_t end);
char *ft_strjoin(char *str1, char *str2);
int ft_strchr(char *str, char c);

#endif // GET_NEXT_LINE_H