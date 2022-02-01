/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:53:43 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/23 08:36:25 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s_dst;
	const char	*s_src;

	i = 0;
	s_dst = dst;
	s_src = src;
	if (!dst && !src)
		return (NULL);
	if (src < dst && (size_t)dst - (size_t)src < len)
	{
		while (--len > 0)
			s_dst[len] = s_src[len];
		s_dst[0] = s_src[0];
	}
	else
	{
		while (i < len)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	return (dst);
}
