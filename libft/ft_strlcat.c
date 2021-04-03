/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:58:05 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 14:07:10 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t allowed_size)
{
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > allowed_size)
		dstlen = allowed_size;
	if (dstlen == allowed_size)
		return (srclen + allowed_size);
	if (srclen < allowed_size - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen + 1);
		dst[dstlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dst + dstlen, src, allowed_size - 1);
		*(dst + (allowed_size - 1)) = '\0';
	}
	return (dstlen + srclen);
}
