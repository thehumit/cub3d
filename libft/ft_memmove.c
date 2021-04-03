/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:55:19 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 16:43:58 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*ptr_for_src;
	unsigned char			*ptr_for_dest;

	ptr_for_src = (const unsigned char *)src;
	ptr_for_dest = (unsigned char *)dest;
	i = 0;
	if ((ptr_for_dest == NULL) && (ptr_for_src == NULL))
		return (dest);
	if (dest < src)
	{
		while (n--)
			*(ptr_for_dest++) = *(ptr_for_src++);
	}
	else
	{
		while (n > 0)
		{
			ptr_for_dest[n - 1] = ptr_for_src[n - 1];
			n--;
		}
	}
	return (dest);
}
