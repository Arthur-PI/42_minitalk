/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:43:08 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:20:56 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	if (ft_isascii(uc))
	{
		i = 0;
		while (us[i])
		{
			if (us[i] == uc)
				return ((char *)s + i);
			i++;
		}
		if (us[i] == uc)
			return ((char *)s + i);
	}
	return (NULL);
}
