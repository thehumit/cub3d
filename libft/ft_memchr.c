/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:55:01 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 13:36:32 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char *ptr_to_arr;

	ptr_to_arr = (unsigned char *)arr;
	while (n-- > 0)
	{
		if (*ptr_to_arr == (unsigned char)c)
			return ((void *)ptr_to_arr);
		ptr_to_arr++;
	}
	return (NULL);
}
