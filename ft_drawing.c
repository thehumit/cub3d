/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:35:36 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:40:43 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color(t_param *p, int x, int y)
{
	int		color;

	color = p->mlx->txt_data[y * p->mlx->text_w + x];
	return (color);
}

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	int		*dst;

	dst = p->mlx->d_ad + x + y * p->mlx->sl / 4;
	*dst = color;
}

void	draw_ceil_and_floor(t_param *p, int x)
{
	int		i;

	i = 0;
	while (i < p->mlx->l_start)
	{
		my_mlx_pixel_put(p, x, i, p->mlx->tex.c);
		i++;
	}
	i = p->mlx->l_end;
	while (i < p->mlx->screen_h)
		my_mlx_pixel_put(p, x, i++, p->mlx->tex.f);
}

int		drawline(t_param *p, int x, int text_x)
{
	int		i;
	double	step;
	double	pos;

	step = 1.0 * p->mlx->text_h / p->mlx->l_height;
	pos = (p->mlx->l_start - p->mlx->screen_h / 2
	+ p->mlx->l_height / 2) * step;
	i = p->mlx->l_start;
	draw_ceil_and_floor(p, x);
	while (i <= p->mlx->l_end)
	{
		my_mlx_pixel_put(p, x, i++, get_color(p, text_x, (int)pos));
		pos += step;
	}
	return (1);
}

void	define_line(t_param *p)
{
	p->mlx->l_height = (int)(p->mlx->screen_h / p->ray->walldist);
	p->mlx->l_start = (p->mlx->l_height * -1) / 2 + p->mlx->screen_h / 2;
	if (p->mlx->l_start < 0)
		p->mlx->l_start = 0;
	p->mlx->l_end = p->mlx->l_height / 2 + p->mlx->screen_h / 2;
	if (p->mlx->l_end >= p->mlx->screen_h)
		p->mlx->l_end = p->mlx->screen_h - 1;
}
