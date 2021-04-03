/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:33 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:02:25 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		red(char *str, t_param *p, int flag)
{
	int		i;
	int		r;

	i = 0;
	r = -1;
	r = ft_atoi(str);
	if (r < 0 || r > 255)
		error("ERROR invalid color", p, 0);
	i += color_helper(str) - 1;
	while (str[i] == ' ' || str[i] == ',')
	{
		if (str[i] == ',')
			p->comma++;
		i++;
	}
	if (flag)
		p->mlx->tex.f = 256 * 256 * r;
	else
		p->mlx->tex.c = 256 * 256 * r;
	return (i);
}

int		green(char *str, t_param *p, int flag)
{
	int		i;
	int		g;

	i = 0;
	g = -1;
	g = ft_atoi(str);
	if (g < 0 || g > 255)
		error("ERROR invalid color", p, 0);
	i += color_helper(str) - 1;
	while (str[i] == ' ' || str[i] == ',')
	{
		if (str[i] == ',')
			p->comma++;
		i++;
	}
	if (flag)
		p->mlx->tex.f += 256 * g;
	else
		p->mlx->tex.c += 256 * g;
	return (i);
}

int		blue(char *str, t_param *p, int flag)
{
	int		i;
	int		b;

	i = 0;
	b = -1;
	b = ft_atoi(str);
	if (b < 0 || b > 255)
		error("ERROR invalid color", p, 0);
	while (str[i])
	{
		if (!ft_strchr("1234567890 ", str[i]))
			error("ERROR invalid color", p, 0);
		i++;
	}
	if (flag)
		p->mlx->tex.f += b;
	else
		p->mlx->tex.c += b;
	return (i);
}

void	parse_e_txt(char *line, t_param *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		line += 3;
	else
		error("ERROR, invalid txt", p, 0);
	p->mlx->tex.e_name = ft_strtrim(line, " ");
	p->done.e += 1;
	free(tmp);
}

void	parse_sprite_txt(char *line, t_param *p)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (line[0] == 'S' && line[1] == ' ')
		line += 2;
	else
		error("ERROR, invalid txt", p, 0);
	p->mlx->tex.i_name = ft_strtrim(line, " ");
	p->done.spr += 1;
	free(tmp);
}
