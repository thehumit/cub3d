/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:14 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:01:25 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_helper(char *str)
{
	int i;
	int j;

	j = 0;
	i = ft_atoi(str);
	if (i < 10)
		j++;
	while (i)
	{
		i = i / 10;
		j++;
	}
	j++;
	return (j);
}

void	free_list(t_list *list)
{
	t_list *tmp;
	t_list *head;

	head = list;
	while (head)
	{
		tmp = head->next;
		free(head->content);
		free(head);
		head = tmp;
	}
}

void	parse_floor(char *str, t_param *p)
{
	char *tmp;

	tmp = str;
	p->comma = 0;
	if (str[0] == 'F' && str[1] == ' ')
		str += 2;
	else
		error("ERROR invalid color", p, 0);
	str += red(str, p, 1);
	str += green(str, p, 1);
	str += blue(str, p, 1);
	if (p->comma != 2)
		error("ERROR invalid color", p, 0);
	p->done.f += 1;
	free(tmp);
}

void	parse_ceil(char *str, t_param *p)
{
	char *tmp;

	tmp = str;
	p->comma = 0;
	if (str[0] == 'C' && str[1] == ' ')
		str += 2;
	else
		error("ERROR invalid color", p, 0);
	str += red(str, p, 0);
	str += green(str, p, 0);
	str += blue(str, p, 0);
	if (p->comma != 2)
		error("ERROR invalid color", p, 0);
	p->done.c += 1;
	free(tmp);
}
