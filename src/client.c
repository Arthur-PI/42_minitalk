/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:48 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/28 14:50:10 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		exit(1);
	if (usleep(PONG_WAIT_TIME) == 0)
	{
		ft_putendl_fd("Error while sending signal to server !", 1);
		exit(1);
	}
	usleep(INTERVAL_WAIT_TIME);
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
	if (spid < 1)
		exit(1);
	message = av[2];
	signal(SIGUSR1, response);
	signal(SIGUSR2, response);
	send_size(spid, ft_strlen(message));
	send_message(spid, (unsigned char *)message);
	return (0);
}
