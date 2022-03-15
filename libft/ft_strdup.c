/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:33:16 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/15 16:52:26 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
