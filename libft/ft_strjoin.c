/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:18:06 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/27 18:11:41 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strconcat(char *s1, const char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = 0;
	return (s1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	*res = 0;
	strconcat(res, s1);
	strconcat(res, s2);
	return (res);
}
