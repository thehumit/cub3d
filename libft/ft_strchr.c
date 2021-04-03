/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:57:47 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 14:01:32 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	const char *ptr_to_str;

	ptr_to_str = str;
	while (*ptr_to_str != '\0')
	{
		if (*ptr_to_str == ch)
		{
			return ((char *)ptr_to_str);
		}
		ptr_to_str++;
	}
	if (*ptr_to_str == ch)
	{
		return ((char *)ptr_to_str);
	}
	return (0);
}
