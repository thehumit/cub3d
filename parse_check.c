/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:50 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 17:41:10 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_save(char *arg, char *save)
{
	int	i;

	i = 0;
	if (ft_strncmp(arg, save, ft_strlen(arg)))
		return (0);
	return (1);
}

void	move_operator(t_param *p)
{
	if (p->flags.mv_forward == 1)
		ft_move(p, 1);
	if (p->flags.mv_left == 1)
		ft_strafe(p, 1);
	if (p->flags.mv_back == 1)
		ft_move(p, -1);
	if (p->flags.mv_right == 1)
		ft_strafe(p, -1);
	if (p->flags.rotate_left == 1)
		ft_rotate(p, 1);
	if (p->flags.rotate_right == 1)
		ft_rotate(p, -1);
}
