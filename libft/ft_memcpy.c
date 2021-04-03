/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:55:10 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 13:38:57 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_for_dest;
	const char	*ptr_for_src;

	ptr_for_dest = dest;
	ptr_for_src = src;
	if ((dest == 0) && (src == 0))
		return (0);
	while (n-- > 0)
	{
		*ptr_for_dest++ = *ptr_for_src++;
	}
	return (dest);
}
