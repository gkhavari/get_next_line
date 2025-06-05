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
