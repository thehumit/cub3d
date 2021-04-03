/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:31 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:03 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_param *p, double c)
{
	p->pl->pos_x += c * (p->pl->dir_x * SPEED / 100);
	if (p->map->tab[(int)floor(p->pl->pos_x)][(int)floor(p->pl->pos_y)] == '1')
		p->pl->pos_x -= c * (p->pl->dir_x * SPEED / 100);
	p->pl->pos_y += c * (p->pl->dir_y * SPEED / 100);
	if (p->map->tab[(int)floor(p->pl->pos_x)][(int)floor(p->pl->pos_y)] == '1')
		p->pl->pos_y -= c * (p->pl->dir_y * SPEED / 100);
}

void	ft_strafe(t_param *p, double c)
{
	p->pl->pos_x -= c * (p->pl->dir_y * SPEED / 100);
	if (p->map->tab[(int)floor(p->pl->pos_x)][(int)floor(p->pl->pos_y)] == '1')
		p->pl->pos_x += c * (p->pl->dir_y * SPEED / 100);
	p->pl->pos_y += c * (p->pl->dir_x * SPEED / 100);
	if (p->map->tab[(int)floor(p->pl->pos_x)][(int)floor(p->pl->pos_y)] == '1')
		p->pl->pos_y -= c * (p->pl->dir_x * SPEED / 100);
}

void	ft_rotate(t_param *p, double c)
{
	double	old_dir;
	double	old_plane;

	old_dir = p->pl->dir_x;
	old_plane = p->pl->plane_x;
	p->pl->dir_x = p->pl->dir_x * cos(c * TURN) - p->pl->dir_y * sin(c * TURN);
	p->pl->dir_y = old_dir * sin(c * TURN) + p->pl->dir_y * cos(c * TURN);
	p->pl->plane_x = p->pl->plane_x * cos(c * TURN)
	- p->pl->plane_y * sin(c * TURN);
	p->pl->plane_y = old_plane * sin(c * TURN) + p->pl->plane_y * cos(TURN);
}

int		record_press(int keycode, t_param *p)
{
	if (keycode == ESC)
	{
		error("", p, 1);
		return (0);
	}
	if (keycode == W)
		p->flags.mv_forward = 1;
	if (keycode == A)
		p->flags.mv_left = 1;
	if (keycode == S)
		p->flags.mv_back = 1;
	if (keycode == D)
		p->flags.mv_right = 1;
	if (keycode == LEFT)
		p->flags.rotate_left = 1;
	if (keycode == RIGHT)
		p->flags.rotate_right = 1;
	return (0);
}

int		record_release(int keycode, t_param *p)
{
	if (keycode == W)
		p->flags.mv_forward = 0;
	if (keycode == A)
		p->flags.mv_left = 0;
	if (keycode == S)
		p->flags.mv_back = 0;
	if (keycode == D)
		p->flags.mv_right = 0;
	if (keycode == LEFT)
		p->flags.rotate_left = 0;
	if (keycode == RIGHT)
		p->flags.rotate_right = 0;
	return (0);
}
