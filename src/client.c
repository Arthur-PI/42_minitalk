/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:48 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/23 15:57:39 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	send_signal(int pid, int signal)
{
	int	i;

	i = 1;
	if (kill(pid, signal) == -1)
		exit(1);
	while (usleep(WAIT_TIME * 100) == 0)
	{
		if (i == 3 || kill(pid, signal) == -1)
			exit(1);
		i++;
	}
	usleep(WAIT_TIME);
}

static void	send_size(int pid, int size)
{
	int	i;

	i = sizeof(size) * 8;
	while (i >= 0)
	{
		send_signal(pid, SIGUSR1 + ((size >> i) % 2));
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
			send_signal(pid, SIGUSR1 + ((m[i] >> j) % 2));
			j--;
		}
		i++;
	}
	send_signal(pid, SIGUSR1);
}

static void	response(int signum)
{
	if (signum == SIGUSR2)
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
	signal(SIGUSR2, response);
	send_size(spid, ft_strlen(message));
	send_message(spid, (unsigned char *)message);
	return (0);
}
