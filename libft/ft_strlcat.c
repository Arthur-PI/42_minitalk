/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:43:02 by apigeon           #+#    #+#             */
/*   Updated: 2021/09/08 17:14:57 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst >= dstsize)
		return (lensrc + dstsize);
	i = 0;
	while (src[i] && i < dstsize - lendst - 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	return (lendst + lensrc);
}
