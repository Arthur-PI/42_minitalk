/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:53 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:33:23 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s_cpy;

	if (!s)
		return (NULL);
	s_cpy = malloc(ft_strlen(s) + 1);
	if (!s_cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_cpy[i] = (*f)(i, s[i]);
		i++;
	}
	s_cpy[i] = 0;
	return (s_cpy);
}
