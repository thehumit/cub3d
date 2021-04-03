/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:37:07 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:28:24 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		done_all(t_param *p)
{
	if (p->done.c == 1 && p->done.f == 1 && p->done.n == 1 && p->done.s == 1
	&& p->done.e == 1 && p->done.res == 1 && p->done.w == 1 && p->done.spr == 1)
		return (1);
	if (p->done.c > 1 || p->done.f > 1 || p->done.n > 1 || p->done.s > 1
	|| p->done.e > 1 || p->done.res > 1 || p->done.w > 1 || p->done.spr > 1)
		error("ERROR, more than one key", p, 0);
	return (0);
}

int		check_line(char *line, t_param *p)
{
	int		i;
	int		flag;
	int		x_counter;

	i = 0;
	flag = 0;
	x_counter = 0;
	line_validator(line, p);
	while (line[i])
	{
		if (ft_strchr("012WSNE", line[i]))
		{
			flag = 1;
			x_counter++;
		}
		i++;
	}
	if (flag == 0)
		return (1);
	else
		p->map->max_y++;
	if (x_counter > p->map->max_x && flag == 1)
		p->map->max_x = x_counter;
	return (1);
}

int		parse_params(char *arr, t_param *p)
{
	char	*tmp;

	tmp = arr;
	if (tmp[0] == '\0' && !done_all(p))
		free(tmp);
	while (*arr == ' ')
		arr++;
	if (arr[0] == 'R')
		parse_res(arr, p);
	else if (arr[0] == 'N' && arr[1] == 'O')
		parse_n_txt(arr, p);
	else if (arr[0] == 'S' && arr[1] == 'O')
		parse_s_txt(arr, p);
	else if (arr[0] == 'W' && arr[1] == 'E')
		parse_w_txt(arr, p);
	else if (arr[0] == 'E' && arr[1] == 'A')
		parse_e_txt(arr, p);
	else if (arr[0] == 'S')
		parse_sprite_txt(arr, p);
	else if (arr[0] == 'F')
		parse_floor(arr, p);
	else if (arr[0] == 'C')
		parse_ceil(arr, p);
	return (0);
}

int		parse_file(int fd, t_param *p)
{
	t_list		*head_for_map;
	char		*line;
	int			ret;

	line = NULL;
	p->map->max_x = 0;
	p->map->max_y = 0;
	ret = 1;
	head_for_map = NULL;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (done_all(p))
		{
			if (check_line(line, p))
				ft_lstadd_back(&head_for_map, ft_lstnew(line));
		}
		parse_params(line, p);
	}
	init_map(p, head_for_map);
	ft_pos(p);
	ft_slist(p);
	free_list(head_for_map);
	return (0);
}

int		ft_parse(char *file_name, t_param *p)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		error("ERROR, wrong file descriptor", p, 0);
	parse_file(fd, p);
	return (1);
}
