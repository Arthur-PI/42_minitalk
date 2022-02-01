/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:54:57 by apigeon           #+#    #+#             */
/*   Updated: 2022/01/25 20:16:39 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void handler(int signum)
{
	int					size;
	static t_message	m = {0, NULL, 0};

	m.bitsSend++;
	size = (int)sizeof(m.size) * 8 + 1;
	printf("signum = %d; bitsSend = %d\n", signum, m.bitsSend);
	if (m.bitsSend <= size)
	{
		m.size <<= 1;
		if (signum == SIGUSR2)
			m.size += 1;
		if (m.bitsSend == size)
			m.message = malloc(m.size + 1);
	}
	else if (m.bitsSend <= size + m.size * 8)
	{
		if (!m.message)
			exit(1);
		// TODO receive the messeage
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
	pause();
	return (0);
}
