/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:29:38 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:14:10 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub_s;

	if (!s)
		return (NULL);
	i = start;
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, 1));
	sub_s = malloc(min(str_len - start, len) + 1);
	if (!sub_s)
		return (NULL);
	while (s[i] && i - start < len)
	{
		sub_s[i - start] = s[i];
		i++;
	}
	sub_s[i - start] = 0;
	return (sub_s);
}
