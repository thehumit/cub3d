/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:39 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:35 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	n_init(t_param *p)
{
	void	*img_n;

	img_n = mlx_xpm_file_to_image(p->mlx->ptr,
	p->mlx->tex.n_name, &(p->mlx->tex.n_w), &(p->mlx->tex.n_h));
	if (img_n == NULL)
	{
		free(img_n);
		error("ERROR invalid txt", p, 0);
	}
	p->mlx->tex.n = (unsigned int *)mlx_get_data_addr(img_n,
	&p->mlx->tex.n_sb, &p->mlx->tex.n_sl, &p->mlx->tex.n_eb);
	if (p->mlx->tex.n == NULL)
	{
		free(img_n);
		error("ERROR invalid txt", p, 0);
	}
	free(img_n);
}

void	s_init(t_param *p)
{
	void	*img_s;

	img_s = mlx_xpm_file_to_image(p->mlx->ptr,
	p->mlx->tex.s_name, &(p->mlx->tex.s_w), &(p->mlx->tex.s_h));
	if (img_s == NULL)
	{
		free(img_s);
		error("ERROR invalid txt", p, 0);
	}
	p->mlx->tex.s = (unsigned int *)mlx_get_data_addr(img_s,
	&p->mlx->tex.s_sb, &p->mlx->tex.s_sl, &p->mlx->tex.s_eb);
	if (p->mlx->tex.s == NULL)
	{
		free(img_s);
		error("ERROR invalid txt", p, 0);
	}
	free(img_s);
}

void	w_init(t_param *p)
{
	void	*img_w;

	img_w = mlx_xpm_file_to_image(p->mlx->ptr,
	p->mlx->tex.w_name, &(p->mlx->tex.w_w), &(p->mlx->tex.w_h));
	if (img_w == NULL)
	{
		free(img_w);
		error("ERROR invalid txt", p, 0);
	}
	p->mlx->tex.w = (unsigned int *)mlx_get_data_addr(img_w,
	&p->mlx->tex.w_sb, &p->mlx->tex.w_sl, &p->mlx->tex.w_eb);
	if (p->mlx->tex.w == NULL)
	{
		free(img_w);
		error("ERROR invalid txt", p, 0);
	}
	free(img_w);
}

void	e_init(t_param *p)
{
	void	*img_e;

	img_e = mlx_xpm_file_to_image(p->mlx->ptr,
	p->mlx->tex.e_name, &(p->mlx->tex.e_w), &(p->mlx->tex.e_h));
	if (img_e == NULL)
	{
		free(img_e);
		error("ERROR invalid txt", p, 0);
	}
	p->mlx->tex.e = (unsigned int *)mlx_get_data_addr(img_e,
	&p->mlx->tex.e_sb, &p->mlx->tex.e_sl, &p->mlx->tex.e_eb);
	if (p->mlx->tex.e == NULL)
	{
		free(img_e);
		error("ERROR invalid txt", p, 0);
	}
	free(img_e);
}

void	spr_init(t_param *p)
{
	void	*img_spr;

	img_spr = mlx_xpm_file_to_image(p->mlx->ptr,
	p->mlx->tex.i_name, &(p->mlx->tex.i_w), &(p->mlx->tex.i_h));
	if (img_spr == NULL)
	{
		free(img_spr);
		error("ERROR invalid txt", p, 0);
	}
	p->mlx->tex.i = (unsigned int *)mlx_get_data_addr(img_spr,
	&p->mlx->tex.i_sb, &p->mlx->tex.i_sl, &p->mlx->tex.i_eb);
	if (p->mlx->tex.i == NULL)
	{
		free(img_spr);
		error("ERROR invalid txt", p, 0);
	}
	free(img_spr);
}
