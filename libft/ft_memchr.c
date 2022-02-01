/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:24:53 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:46:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_s;
	unsigned char	uc;

	i = 0;
	s_s = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (s_s[i] == uc)
			return ((void *)s_s + i);
		i++;
	}
	return (NULL);
}
