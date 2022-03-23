/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:40 by apigeon           #+#    #+#             */
/*   Updated: 2022/03/23 16:07:02 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <signal.h>
# include <time.h>

# include "libft.h"

# define WAIT_TIME 50

typedef struct s_message
{
	int		size;
	char	*message;
	int		bits_send;
}				t_message;

#endif
