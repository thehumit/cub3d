/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:19 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:28:32 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*space_remover(char *str, t_param *p)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		error("ERROR, invalid symbol in map", p, 0);
	while (str[i] && str)
	{
		if (!ft_strchr("NSWE012 ", str[i]))
		{
			error("ERROR, invalid symbol in map", p, 0);
			return (0);
		}
		i++;
	}
	tmp = ft_strdup(str);
	return (tmp);
}

void	init_map(t_param *p, t_list *list)
{
	int i;

	i = 0;
	if (!(p->map->tab = (char **)ft_calloc(p->map->max_y + 1, sizeof(char *))))
		return ;
	while (list)
	{
		if (p->flag_for_map == 0 && ((char *)(list->content))[0] == '\0')
			list = list->next;
		else
		{
			if (i < p->map->max_y)
				p->map->tab[i] = space_remover((char *)list->content, p);
			p->flag_for_map = 1;
			list = list->next;
			i++;
		}
	}
	check_map1(p);
}

void	check_map1(t_param *p)
{
	int i;
	int j;
	int player;

	i = 0;
	j = 0;
	player = 0;
	while (p->map->tab[i] && p->map->tab[i][0] != '\0')
	{
		j = 0;
		while (ft_strchr("012WSEN ", p->map->tab[i][j])
		&& p->map->tab[i][j] != '\0')
		{
			if (ft_strchr("NSEW", p->map->tab[i][j]))
				player++;
			if (ft_strchr("02WSEN", p->map->tab[i][j]))
				if (!check_borders(p, i, j))
					error("ERROR, wrong map", p, 0);
			j++;
		}
		i++;
	}
	if (player != 1)
		error("ERROR, wrong spawn", p, 0);
}

void	checker2(t_param *p, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("1234567890 R", line[i]))
			error("ERROR, invalid resolution", p, 0);
		i++;
	}
}
