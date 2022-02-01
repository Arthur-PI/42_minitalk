/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:46:12 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:30:25 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	if (ft_isascii(uc))
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			if (us[i] == uc)
				return ((char *)s + i);
			i--;
		}
	}
	return (NULL);
}
