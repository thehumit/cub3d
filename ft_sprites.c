/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:23 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:40:58 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_param *p)
{
	double		distance[p->map->spr];
	int			tmp;
	int			disttmp;
	int			i;

	i = -1;
	while (++i < p->map->spr)
	{
		distance[i] = ((p->pl->pos_x - p->mlx->spr[i].x) *
		(p->pl->pos_x - p->mlx->spr[i].x) + (p->pl->pos_y
		- p->mlx->spr[i].y) * (p->pl->pos_y - p->mlx->spr[i].y));
		p->mlx->spr_order[i] = i;
	}
	i = -1;
	while (++i < p->map->spr - 1)
		if (distance[i] < distance[i + 1])
		{
			disttmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = disttmp;
			tmp = p->mlx->spr_order[i];
			p->mlx->spr_order[i] = p->mlx->spr_order[i + 1];
			p->mlx->spr_order[i + 1] = tmp;
			i = -1;
		}
}

void	sprite_size(t_param *p)
{
	p->spr_tools.spriteheight = abs((int)
	(p->mlx->screen_h / (p->spr_tools.transformy)));
	p->spr_tools.drawstarty = -p->spr_tools.spriteheight / 2
	+ p->mlx->screen_h / 2;
	if (p->spr_tools.drawstarty < 0)
		p->spr_tools.drawstarty = 0;
	p->spr_tools.drawendy = p->spr_tools.spriteheight
	/ 2 + p->mlx->screen_h / 2;
	if (p->spr_tools.drawendy >= p->mlx->screen_h)
		p->spr_tools.drawendy = p->mlx->screen_h;
	p->spr_tools.spritewidth = abs((int)
	(p->mlx->screen_h / (p->spr_tools.transformy)));
	p->spr_tools.drawstartx = -p->spr_tools.spritewidth
	/ 2 + p->spr_tools.spritescreenx;
	if (p->spr_tools.drawstartx < 0)
		p->spr_tools.drawstartx = 0;
	p->spr_tools.drawendx = p->spr_tools.spritewidth
	/ 2 + p->spr_tools.spritescreenx;
	if (p->spr_tools.drawendx >= p->mlx->screen_w)
		p->spr_tools.drawendx = p->mlx->screen_w;
}

int		get_color_spr(t_param *p, int x, int y)
{
	int		color;

	color = p->mlx->tex.i[y * p->mlx->tex.i_w + x];
	return (color);
}

int		spr_param_checker(t_param *p)
{
	if (p->spr_tools.transformy > 0 && p->spr_tools.x >= 0 &&
	p->spr_tools.x < p->mlx->screen_w &&
	p->spr_tools.transformy < (float)p->ray->zbuffer[p->spr_tools.x])
		return (1);
	return (0);
}

void	drawspritelines(t_param *p)
{
	p->spr_tools.x = p->spr_tools.drawstartx;
	while (p->spr_tools.x < p->spr_tools.drawendx)
	{
		p->spr_tools.tex_x = (int)((p->spr_tools.x
		- (-p->spr_tools.spritewidth / 2 +
		p->spr_tools.spritescreenx))
		* p->mlx->tex.i_w / p->spr_tools.spritewidth);
		p->spr_tools.y = p->spr_tools.drawstarty;
		if (spr_param_checker(p))
			while (p->spr_tools.y < p->spr_tools.drawendy)
			{
				p->spr_tools.d = (p->spr_tools.y) *
				256 - p->mlx->screen_h * 128 +
				p->spr_tools.spriteheight * 128;
				p->spr_tools.tex_y = ((p->spr_tools.d * p->mlx->tex.i_h /
				p->spr_tools.spriteheight) / 256);
				if ((get_color_spr(p, p->spr_tools.tex_x, p->spr_tools.tex_y)))
					my_mlx_pixel_put(p, p->spr_tools.x, p->spr_tools.y,
					get_color_spr(p, p->spr_tools.tex_x, p->spr_tools.tex_y));
				p->spr_tools.y++;
			}
		p->spr_tools.x++;
	}
}
