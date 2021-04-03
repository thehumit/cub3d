/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:53:10 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 13:21:00 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin;
	t_list	*buf;

	begin = *lst;
	while (begin)
	{
		buf = begin->next;
		if (del)
			del(begin->content);
		free(begin);
		begin = buf;
	}
	*lst = NULL;
}
