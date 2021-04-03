/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:52:54 by tquintan          #+#    #+#             */
/*   Updated: 2020/11/06 13:18:50 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int		ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	if (n < 0)
		n = -n;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		n_copy;
	int		count;

	n_copy = n;
	count = 0;
	count = ft_count(n_copy);
	if (!(arr = malloc(count + 1)))
		return (0);
	arr[count] = '\0';
	if (n < 0)
		arr[0] = '-';
	if (n == 0)
		arr[0] = '0';
	while (ft_abs(n))
	{
		count--;
		arr[count] = 48 + ft_abs(n % 10);
		n /= 10;
	}
	return (arr);
}
