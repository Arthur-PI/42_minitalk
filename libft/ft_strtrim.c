/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:58:55 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:32:36 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define EMPTY -1

static int	contain(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && contain(set, s1[i]))
		i--;
	return (i);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && contain(set, s1[i]))
		i++;
	if (!s1[i])
		return (EMPTY);
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		start;
	int		end;
	char	*s1_trim;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	if (start == EMPTY)
		return (calloc(1, 1));
	end = get_end(s1, set) + 1;
	s1_trim = malloc((end - start) + 1);
	if (!s1_trim)
		return (NULL);
	i = start;
	while (i < end)
	{
		s1_trim[i - start] = s1[i];
		i++;
	}
	s1_trim[i - start] = 0;
	return (s1_trim);
}
