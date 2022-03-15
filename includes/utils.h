/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:40 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/15 22:36:29 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <time.h>

# include "libft.h"

# define WAIT_TIME 20

typedef struct s_message
{
	int		size;
	char	*message;
	int		bits_send;
}				t_message;

#endif
