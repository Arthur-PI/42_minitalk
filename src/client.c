/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:48 by apigeon           #+#    #+#             */
/*   Updated: 2022/02/01 19:25:55 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sendSize(int pid, int size)
{
	int	i;

	i = sizeof(size) * 8;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((size >> i) % 2));
		usleep(1000);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		spid;
	char	*message;

	if (ac != 3)
		return (1);
	spid = ft_atoi(av[1]);
	message = av[2];
	printf("pid = %d; message = \"%s\" (%zu); sizeof = %zu\n", spid, message, ft_strlen(message), sizeof(int));
	sendSize(spid, ft_strlen(message));
	return (0);
}
