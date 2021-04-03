/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:35:49 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:40:48 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fov_and_pos(t_param *p, int x)
{
	p->pl->camera_x = 2 * x / (double)p->mlx->screen_w - 1;
	p->ray->dir_x = p->pl->dir_x + p->pl->plane_x * p->pl->camera_x;
	p->ray->dir_y = p->pl->dir_y + p->pl->plane_y * p->pl->camera_x;
	p->map->x = (int)(p->pl->pos_x);
	p->map->y = (int)(p->pl->pos_y);
	p->ray->delta_x = fabs(1 / p->ray->dir_x);
	p->ray->delta_y = fabs(1 / p->ray->dir_y);
}

void	get_step(t_param *p)
{
	if (p->ray->dir_x < 0)
	{
		p->map->step_x = -1;
		p->ray->side_x = (p->pl->pos_x - p->map->x) * p->ray->delta_x;
	}
	else
	{
		p->map->step_x = 1;
		p->ray->side_x = (p->map->x + 1.0 - p->pl->pos_x) * p->ray->delta_x;
	}
	if (p->ray->dir_y < 0)
	{
		p->map->step_y = -1;
		p->ray->side_y = (p->pl->pos_y - p->map->y) * p->ray->delta_y;
	}
	else
	{
		p->map->step_y = 1;
		p->ray->side_y = (p->map->y + 1.0 - p->pl->pos_y) * p->ray->delta_y;
	}
}

void	wallhit(t_param *p)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (p->ray->side_x < p->ray->side_y)
		{
			p->ray->side_x += p->ray->delta_x;
			p->map->x += p->map->step_x;
			p->ray->wallside = 0;
		}
		else
		{
			p->ray->side_y += p->ray->delta_y;
			p->map->y += p->map->step_y;
			p->ray->wallside = 1;
		}
		if (p->map->tab[p->map->x][p->map->y] == '1')
			hit = 1;
	}
}

void	walldist_dir(t_param *p, int x)
{
	if (p->ray->wallside == 1)
	{
		if (p->map->y < p->pl->pos_y)
			p->ray->walldir = 'W';
		else
			p->ray->walldir = 'E';
		p->ray->walldist = (p->map->y - p->pl->pos_y +
		(1 - p->map->step_y) / 2) / p->ray->dir_y;
		p->ray->wallx = p->pl->pos_x + p->ray->walldist * p->ray->dir_x;
	}
	else
	{
		if (p->map->x < p->pl->pos_x)
			p->ray->walldir = 'N';
		else
			p->ray->walldir = 'S';
		p->ray->walldist = (p->map->x - p->pl->pos_x +
		(1 - p->map->step_x) / 2) / p->ray->dir_x;
		p->ray->wallx = p->pl->pos_y + p->ray->walldist * p->ray->dir_y;
	}
	p->ray->zbuffer[x] = p->ray->walldist;
}

void	raycast(t_param *p)
{
	int		x;

	x = 0;
	while (x < p->mlx->screen_w)
	{
		fov_and_pos(p, x);
		get_step(p);
		wallhit(p);
		walldist_dir(p, x);
		define_line(p);
		choose_texture(p);
		p->ray->wallx -= floor(p->ray->wallx);
		p->mlx->text_x = p->ray->wallx * (p->mlx->text_sl / 4);
		if (p->ray->wallside == 0 && p->ray->dir_x > 0)
			p->mlx->text_x = (p->mlx->text_sl / 4) - p->mlx->text_x - 1;
		else if (p->ray->wallside == 1 && p->ray->dir_y < 0)
			p->mlx->text_x = (p->mlx->text_sl / 4) - p->mlx->text_x - 1;
		drawline(p, x, p->mlx->text_x);
		x++;
	}
}
