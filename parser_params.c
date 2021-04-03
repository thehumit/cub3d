/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:25 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:01:05 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	res_helper(t_param *p, char *line)
{
	int		i;

	checker2(p, line);
	i = -1;
	while (line[++i])
	{
		if ((line[i] >= '0' && line[i] <= '9') && p->mlx->flag_for_h == 0)
		{
			p->mlx->screen_h = ft_atoi(line);
			p->mlx->flag_for_h = 1;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
		if ((line[i] >= '0' && line[i] <= '9') && p->mlx->flag_for_h == 1)
		{
			p->mlx->screen_w = ft_atoi(line + i);
			p->mlx->flag_for_w = 1;
			break ;
		}
	}
}

void	parse_res(char *line, t_param *p)
{
	char	*tmp;

	tmp = line;
	line++;
	p->mlx->flag_for_h = 0;
	p->mlx->flag_for_w = 0;
	res_helper(p, line);
	if (p->mlx->screen_w > 0 && p->mlx->screen_w <= 100)
		p->mlx->screen_w = 100;
	if (p->mlx->screen_h > 0 && p->mlx->screen_h <= 100)
		p->mlx->screen_w = 100;
	if (p->mlx->screen_w <= 0 || p->mlx->screen_h <= 0
	|| !p->mlx->flag_for_h || !p->mlx->flag_for_w)
		error("ERROR, invalid resolution", p, 0);
	else
		p->done.res += 1;
	if (p->mlx->screen_w > 2560)
		p->mlx->screen_w = 2560;
	if (p->mlx->screen_h > 1440)
		p->mlx->screen_h = 1440;
	free(tmp);
}

void	parse_n_txt(char *line, t_param *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		line += 3;
	else
		error("ERROR, invalid txt", p, 0);
	p->mlx->tex.n_name = ft_strtrim(line, " ");
	p->done.n += 1;
	free(tmp);
}

void	parse_s_txt(char *line, t_param *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		line += 3;
	else
		error("ERROR, invalid txt", p, 0);
	p->mlx->tex.s_name = ft_strtrim(line, " ");
	p->done.s += 1;
	free(tmp);
}

void	parse_w_txt(char *line, t_param *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		line += 3;
	else
		error("ERROR, invalid txt", p, 0);
	p->mlx->tex.w_name = ft_strtrim(line, " ");
	p->done.w += 1;
	free(tmp);
}
