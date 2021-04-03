/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:00:43 by tquintan          #+#    #+#             */
/*   Updated: 2021/03/04 12:42:24 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(a = malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1)))
		return (NULL);
	if (s1)
		while (s1[j] != '\0')
			a[i++] = s1[j++];
	j = 0;
	free(s1);
	if (s2)
		while (s2[j] != '\0')
			a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

int		ft_strchr1(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
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
