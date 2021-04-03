/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:57:56 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 14:05:30 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(a = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j] != '\0')
		a[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}
