/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:54:10 by gkhavari          #+#    #+#             */
/*   Updated: 2025/06/10 11:58:40 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*next_line;
	static char	*left_over_chars = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	next_line = fill_line(fd, left_over_chars, buffer);
	free(buffer);
	if (!next_line)
		return (NULL);
	left_over_chars = setup_line(next_line);
	return (next_line);
}

char	*fill_line(int fd, char *new_line, char *buffer)
{
	int	bytes_read;

	bytes_read = 0;
	while (bytes_read >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (new_line);
		else if (bytes_read > 0)
		{
			if (!new_line)
				new_line = ft_strdup(buffer);
			else
			{
				if (ft_strchr(new_line, '\n'))
					break ;
				new_line = ft_strjoin(new_line, buffer);
			}

		}
		else
			return (NULL);
		if (ft_strchr(new_line, '\n'))
			break ;
	}
	return (new_line);
}

char	*setup_line(char *line_buffer)
{
	size_t	i;
	char	*left_over_chars;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\n')
	{
		left_over_chars = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
		if (!left_over_chars)
			return (NULL);	
		line_buffer[i] = '\0';
		return (left_over_chars);
	}
	else if (line_buffer[i] == '\0' || line_buffer[i + 1] == '\0')
		return (NULL);
	else
		return (NULL);
}
