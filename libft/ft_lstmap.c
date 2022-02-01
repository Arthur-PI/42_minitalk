/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:23:42 by apigeon           #+#    #+#             */
/*   Updated: 2021/11/28 15:34:01 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elem;

	if (!lst)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (!first)
		return (NULL);
	elem = first;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&elem, ft_lstnew((*f)(lst->content)));
		elem = elem->next;
		if (!elem)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (first);
}
