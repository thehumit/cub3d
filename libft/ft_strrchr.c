/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:58:37 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 14:55:52 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int			len_str;
	const char	*ptr_to_str;

	len_str = 0;
	ptr_to_str = str;
	while (*ptr_to_str != '\0')
	{
		ptr_to_str++;
		len_str++;
	}
	while (len_str >= 0)
	{
		if (*ptr_to_str == ch)
		{
			return ((char *)ptr_to_str);
		}
		ptr_to_str--;
		len_str--;
	}
	return (0);
}
