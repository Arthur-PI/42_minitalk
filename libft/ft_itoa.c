/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:55:08 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:44:59 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*get_zero(void)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = 0;
	return (s);
}

static char	*itoa_positive(char *s_nbr, size_t nbr, int nbr_len)
{
	s_nbr[nbr_len + 1] = 0;
	while (nbr != 0)
	{
		s_nbr[nbr_len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (s_nbr);
}

char	*ft_itoa(int n)
{
	int		nbr_len;
	int		is_negative;
	long	nbr;
	char	*s_nbr;

	if (n == 0)
		return (get_zero());
	nbr = n;
	is_negative = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		is_negative = 1;
	}
	nbr_len = number_length(n);
	s_nbr = malloc(nbr_len + is_negative + 1);
	if (!s_nbr)
		return (NULL);
	if (is_negative)
		s_nbr[0] = '-';
	else
		nbr_len--;
	return (itoa_positive(s_nbr, nbr, nbr_len));
}
