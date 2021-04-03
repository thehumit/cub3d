/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:00:32 by tquintan          #+#    #+#             */
/*   Updated: 2021/03/04 12:42:00 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*operator(char *save, char **line)
{
	int		i;
	int		j;
	char	*retain;

	retain = 0;
	j = 0;
	i = 0;
	if (!save)
	{
		*line = 0;
		return (0);
	}
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i])
		retain = ft_substr1(save, i + 1, (ft_strlen1(save) - i));
	*line = ft_substr1(save, 0, i);
	free(save);
	return (retain);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				read_return;

	read_return = 1;
	if (read(fd, 0, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr1(save))
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		buff[read_return] = '\0';
		save = ft_strjoin1(save, buff);
		if (read_return < 1)
			break ;
	}
	free(buff);
	save = operator(save, line);
	if (read_return == -1)
		return (-1);
	if (read_return == 0)
		return (0);
	return (1);
}
