/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:50:11 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:31:15 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;
	size_t	j;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < size)
		{
			p[i * size + j] = 0;
			j++;
		}
		i++;
	}
	return (p);
}
