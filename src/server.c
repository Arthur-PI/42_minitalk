/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:57 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/15 17:50:30 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	handler(int signum)
{
	int					size;
	int					tmp;
	static t_message	m = {0, NULL, 0};

	m.bits_send++;
	size = (int) sizeof(m.size) * 8 + 1;
	if (m.bits_send <= size)
	{
		m.size <<= 1;
		if (signum == SIGUSR2)
			m.size += 1;
		if (m.bits_send == size)
			m.message = malloc(m.size + 1);
	}
	else if (m.bits_send <= size + m.size * 8)
	{
		if (!m.message)
			exit(1);
		tmp = (m.bits_send - size - 1) / 8;
		m.message[tmp] <<= 1;
		if (signum == SIGUSR2)
			m.message[tmp] += 1;
	}
	else
	{
		m.message[m.size] = 0;
		write(1, m.message, m.size);
		write(1, "\n", 1);
		m.bits_send = 0;
		m.message = NULL;
		m.size = 0;
	}
	// TODO send confirmation
}

int	main(void)
{
	int					error;
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = 0;
	error = sigaction(SIGUSR1, &sa, NULL);
	error |= sigaction(SIGUSR2, &sa, NULL);
	if (error)
		return (1);
	printf("Je suis le server ! (PID: %d)\n", getpid());
	while (1);
	return (0);
}
