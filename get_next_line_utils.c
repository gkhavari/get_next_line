/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:56:01 by gkhavari          #+#    #+#             */
/*   Updated: 2025/05/19 15:56:22 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	total_size;

	total_size = nmemb * size;
	r = malloc(total_size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, total_size);
	return (r);
}

size_t ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
char *ft_substr(char *str, size_t start, size_t len)
{
	char	*sub;
	size_t	len_str;
	size_t	len_sub;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len_str = ft_strlen(str);
	if (len_str - start > len)
		len_sub = len;
	else
		len_sub = len_str - start;
	sub = (char *)calloc(len_sub + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (start >= len_str)
	{
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while (i < len_sub)
	{
		sub[i] = str[start + i];
		i++;
	}
	return (sub);
}