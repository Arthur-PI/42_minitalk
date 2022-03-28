/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:57 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/28 12:15:33 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_message	g_message = {FALSE, 0, 0, NULL};

static void	handle_size(int signum, int size)
{
	g_message.length <<= 1;
	if (signum == SIGUSR2)
		g_message.length += 1;
	if (g_message.bits_send == size)
		g_message.malloc_now = TRUE;
}

static void	handle_message(int signum, int size)
{
	int	index;

	index = (g_message.bits_send - size - 1) / 8;
	g_message.string[index] <<= 1;
	if (signum == SIGUSR2)
		g_message.string[index] += 1;
}

static void	message_done(int pid)
{
	g_message.string[g_message.length] = 0;
	ft_putstr_fd(g_message.string, 1);
	ft_putchar_fd('\n', 1);
	free(g_message.string);
	g_message.malloc_now = FALSE;
	g_message.bits_send = 0;
	g_message.length = 0;
	g_message.string = NULL;
	usleep(INTERVAL_WAIT_TIME);
	if (kill(pid, SIGUSR2) == -1)
		exit(1);
}

static void	handler(int signum, siginfo_t *si, void *data)
{
	int					size_bits;

	(void)data;
	g_message.bits_send++;
	size_bits = (int) sizeof(g_message.length) * 8 + 1;
	if (g_message.bits_send <= size_bits)
		handle_size(signum, size_bits);
	else if (g_message.bits_send <= size_bits + g_message.length * 8)
		handle_message(signum, size_bits);
	else
		message_done(si->si_pid);
	usleep(INTERVAL_WAIT_TIME);
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
	{
		pause();
		if (g_message.malloc_now == TRUE)
		{
			g_message.string = malloc(g_message.length + 1);
			if (g_message.string == NULL)
				exit(1);
			g_message.malloc_now = FALSE;
		}
	}
	return (0);
}
