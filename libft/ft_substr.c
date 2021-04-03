/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:58:55 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 14:28:26 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;

	j = 0;
	i = 0;
	if (!(a = malloc(len + 1)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (len > 0 && s[j] != '\0')
	{
		if (j >= start)
		{
			a[i++] = s[start++];
			len--;
		}
		j++;
	}
	a[i] = '\0';
	return (a);
}
