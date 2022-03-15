/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:48 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/16 02:15:10 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	send_size(int pid, int size)
{
	int	i;

	i = sizeof(size) * 8;
	while (i >= 0)
	{
		kill(pid, SIGUSR1 + ((size >> i) % 2));
		usleep(WAIT_TIME);
		i--;
	}
}

static void	send_message(int pid, unsigned char *m)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 7;
		while (j >= 0)
		{
			kill(pid, SIGUSR1 + ((m[i] >> j) % 2));
			usleep(WAIT_TIME);
			j--;
		}
		i++;
	}
	kill(pid, SIGUSR1);
}

static void	response(int signum)
{
	(void)signum;
	ft_putstr_fd("Message Received !\n", 1);
}

int	main(int ac, char **av)
{
	int					spid;
	char				*message;

	if (ac != 3)
		return (1);
	spid = ft_atoi(av[1]);
	message = av[2];
	signal(SIGUSR1, response);
	send_size(spid, ft_strlen(message));
	send_message(spid, (unsigned char *)message);
	pause();
	return (0);
}
