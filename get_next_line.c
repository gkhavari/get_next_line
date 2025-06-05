/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:54:10 by gkhavari          #+#    #+#             */
/*   Updated: 2025/05/19 15:54:34 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char    *buffer;
    char    *next_line;
    static char *left_over_chars;

    if (fd < 0, BUFFER_SIZE <= 0, read(fd, 0, 0) < 0)
        return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
    next_line = fill_line(fd, left_over_chars, buffer);
    free(buffer);
    if (!next_line)
        return (NULL);
    left_over_chars = setup_line(next_line);
    return (next_line);
}

char    *fill_line(int fd, char *left_over_chars, char *buffer)
{
/*This function fills the line buffer.

- read BUFFER_SIZE characters in each iteration until there's a \n or \0 character in the line buffer.
- Each time through the loop, check if there is already data in the left_c buffer, if there is, it will append the new read characters to it. If not, it will duplicate the content of the read buffer into the left_c buffer.
- If a \n is found, it will break out of the loop and return the left_c buffer after appending the read characters to it.*/
}

char *setup_line(char *line_buffer)
{
/*This function take the line buffer as parameter, it reads in it until a \n or \0 character is found, meaning the end of a line, or the end of the file.

This function sets the line_buffer a \0 at the end of the line inside of it and it returns a substring of the buffer from the end of the line, to the end of the buffer.
This substring is returned as left_c. 
*/
}


