/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:38 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:07 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_right_border(t_param *p, int i, int j)
{
	while (p->map->tab[i][++j])
	{
		if (ft_strchr("02SWEN", p->map->tab[i][j]))
			continue ;
		else if (p->map->tab[i][j] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

int		check_left_border(t_param *p, int i, int j)
{
	while (p->map->tab[i][--j])
	{
		if (ft_strchr("02SWEN", p->map->tab[i][j]))
			continue ;
		else if (p->map->tab[i][j] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

int		check_top_border(t_param *p, int i, int j)
{
	while (p->map->tab[--i][j])
	{
		if (ft_strchr("02SWEN", p->map->tab[i][j]))
			continue ;
		else if (p->map->tab[i][j] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

int		check_bottom_border(t_param *p, int i, int j)
{
	while (p->map->tab[++i][j])
	{
		if (ft_strchr("02SWEN", p->map->tab[i][j]))
			continue ;
		else if (p->map->tab[i][j] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}

int		check_borders(t_param *p, int i, int j)
{
	int k;

	k = 0;
	if (!check_left_border(p, i, j))
		return (0);
	if (!check_right_border(p, i, j))
		return (0);
	if (!check_top_border(p, i, j))
		return (0);
	if (!check_bottom_border(p, i, j))
		return (0);
	return (1);
}
