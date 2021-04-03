/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:53:54 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:27:48 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	choose_text_help(t_param *p)
{
	if (p->ray->walldir == 'N')
	{
		p->mlx->txt_data = (int *)p->mlx->tex.n;
		p->mlx->text_sl = p->mlx->tex.n_sl;
		p->mlx->text_h = p->mlx->tex.n_h;
		p->mlx->text_w = p->mlx->tex.n_w;
		p->mlx->bpp = p->mlx->tex.n_sb;
	}
	else if (p->ray->walldir == 'S')
	{
		p->mlx->txt_data = (int *)p->mlx->tex.s;
		p->mlx->text_sl = p->mlx->tex.s_sl;
		p->mlx->text_h = p->mlx->tex.s_h;
		p->mlx->text_w = p->mlx->tex.s_w;
		p->mlx->bpp = p->mlx->tex.s_sb;
	}
}

void	choose_texture(t_param *p)
{
	if (p->ray->walldir == 'N' || p->ray->walldir == 'S')
		choose_text_help(p);
	else if (p->ray->walldir == 'E')
	{
		p->mlx->txt_data = (int *)p->mlx->tex.e;
		p->mlx->text_sl = p->mlx->tex.e_sl;
		p->mlx->text_h = p->mlx->tex.e_h;
		p->mlx->text_w = p->mlx->tex.e_w;
		p->mlx->bpp = p->mlx->tex.e_sb;
	}
	else
	{
		p->mlx->txt_data = (int *)p->mlx->tex.w;
		p->mlx->text_sl = p->mlx->tex.w_sl;
		p->mlx->text_h = p->mlx->tex.w_h;
		p->mlx->text_w = p->mlx->tex.w_w;
		p->mlx->bpp = p->mlx->tex.w_sb;
	}
}

void	sprite_params(t_param *p, int i)
{
	p->spr_tmp = p->mlx->spr[p->mlx->spr_order[i++]];
	p->current_spr.spritex = (p->spr_tmp.x + 0.5) - p->pl->pos_x;
	p->current_spr.spritey = (p->spr_tmp.y + 0.5) - p->pl->pos_y;
	p->current_spr.invdet = 1.0 / (p->pl->plane_x *
	p->pl->dir_y - p->pl->dir_x * p->pl->plane_y);
	p->spr_tools.transformx = p->current_spr.invdet * (p->pl->dir_y *
	p->current_spr.spritex - p->pl->dir_x * p->current_spr.spritey);
	p->spr_tools.transformy = p->current_spr.invdet *
	(-p->pl->plane_y * p->current_spr.spritex +
	p->pl->plane_x * p->current_spr.spritey);
	p->spr_tools.spritescreenx = (int)((p->mlx->screen_w / 2) *
	(1 + p->spr_tools.transformx / p->spr_tools.transformy));
}

void	drawsprites(t_param *p)
{
	int			i;

	i = 0;
	sort_sprites(p);
	while (i < p->map->spr)
	{
		sprite_params(p, i);
		sprite_size(p);
		drawspritelines(p);
		i++;
	}
}

void	line_validator(char *line, t_param *p)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_strchr("012WSEN ", line[i]))
			error("ERROR, invalid line in map", p, 0);
	}
}
