/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:59 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:13 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	helper(t_param *p, char c)
{
	if (c == 'E')
	{
		p->pl->dir_x = 0;
		p->pl->dir_y = 1;
		p->pl->plane_x = 0.66;
		p->pl->plane_y = 0;
	}
	if (c == 'W')
	{
		p->pl->dir_x = 0;
		p->pl->dir_y = -1;
		p->pl->plane_x = -0.66;
		p->pl->plane_y = 0;
	}
	if (c == 'S')
	{
		p->pl->dir_x = 1;
		p->pl->dir_y = 0;
		p->pl->plane_x = 0;
		p->pl->plane_y = -0.66;
	}
}

void	ft_pos_helper(t_param *p, char c, int i, int j)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		p->pl->pos_x = (double)i + 0.5;
		p->pl->pos_y = (double)j + 0.5;
		helper(p, c);
		if (c == 'N')
		{
			p->pl->dir_x = -1;
			p->pl->dir_y = 0;
			p->pl->plane_x = 0;
			p->pl->plane_y = 0.66;
		}
	}
	if (c == '2')
		p->map->spr++;
}

void	ft_pos(t_param *p)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < p->map->max_y)
	{
		while (++j < p->map->max_x)
		{
			c = p->map->tab[i][j];
			ft_pos_helper(p, c, i, j);
		}
		j = -1;
	}
}

int		ft_slist(t_param *p)
{
	int		i;
	int		j;
	int		k;

	if (!(p->mlx->spr = malloc(sizeof(t_spritetmp) * p->map->spr)))
		return (-1);
	if (!(p->mlx->spr_order = malloc(sizeof(int) * p->map->spr)))
		return (-1);
	i = 0;
	j = 0;
	while (j < p->map->max_y)
	{
		k = 0;
		while (k < p->map->max_x)
		{
			if (p->map->tab[j][k] == '2')
			{
				p->mlx->spr[i].y = k;
				p->mlx->spr[i++].x = j;
			}
			k++;
		}
		j++;
	}
	return (1);
}
