/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:40 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/28 14:50:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <time.h>

# include "libft.h"

# define INTERVAL_WAIT_TIME 50
# define PONG_WAIT_TIME 100000

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_message
{
	char	malloc_now;
	int		length;
	int		bits_send;
	char	*string;
}				t_message;

#endif
