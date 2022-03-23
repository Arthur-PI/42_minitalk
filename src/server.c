/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:57 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/23 16:06:53 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	handle_size(int signum, int size, t_message *m)
{
	m->size <<= 1;
	if (signum == SIGUSR2)
		m->size += 1;
	if (m->bits_send == size)
	{
		m->message = malloc(m->size + 1);
		if (m->message == NULL)
			exit(1);
	}
}

static void	handle_message(int signum, int size, t_message *m)
{
	int	index;

	index = (m->bits_send - size - 1) / 8;
	m->message[index] <<= 1;
	if (signum == SIGUSR2)
		m->message[index] += 1;
}

static void	message_done(t_message *m, int pid)
{
	m->message[m->size] = 0;
	ft_putstr_fd(m->message, 1);
	ft_putchar_fd('\n', 1);
	free(m->message);
	m->bits_send = 0;
	m->message = NULL;
	m->size = 0;
	usleep(WAIT_TIME);
	if (kill(pid, SIGUSR2) == -1)
		exit(1);
}

static void	handler(int signum, siginfo_t *si, void *data)
{
	int					size;
	static t_message	m = {0, NULL, 0};

	(void)data;
	m.bits_send++;
	size = (int) sizeof(m.size) * 8 + 1;
	if (m.bits_send <= size)
		handle_size(signum, size, &m);
	else if (m.bits_send <= size + m.size * 8)
		handle_message(signum, size, &m);
	else
		message_done(&m, si->si_pid);
	usleep(WAIT_TIME);
	if (kill(si->si_pid, SIGUSR1) == -1)
		exit(1);
}

int	main(void)
{
	int					error;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	error = sigaction(SIGUSR1, &sa, NULL);
	error |= sigaction(SIGUSR2, &sa, NULL);
	if (error)
		return (1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		continue ;
	return (0);
}
