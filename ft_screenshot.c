/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:13 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 19:54:15 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int		bmp_header(t_param *p)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (p->mlx->screen_w * 3 * p->mlx->screen_h)
	+ (p->screenshot_param.padsize * p->mlx->screen_h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, p->mlx->screen_w);
	int_to_char(header + 22, p->mlx->screen_h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(p->screenshot_param.fd, header, 54) < 0));
}

int		pixel_put_screenshot(t_param *p, int x, int y)
{
	int				pixel;

	pixel = *(p->mlx->d_ad + x + y * p->mlx->sl / 4);
	if (write(p->screenshot_param.fd, &pixel, 3) < 0)
		return (0);
	if (p->screenshot_param.padsize > 0 && write(p->screenshot_param.fd,
	&p->screenshot_param.zero, p->screenshot_param.padsize) < 0)
		return (0);
	return (0);
}

void	take_screenshot(t_param *p)
{
	int				x;
	int				y;

	run_game(p);
	p->screenshot_param.padsize = (4 - ((int)p->mlx->screen_w * 3) % 4) % 4;
	if ((p->screenshot_param.fd = open("screenshot.bmp", O_WRONLY |
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		return ;
	bmp_header(p);
	y = p->mlx->screen_h - 1;
	ft_bzero(p->screenshot_param.zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < p->mlx->screen_w)
		{
			pixel_put_screenshot(p, x, y);
			x++;
		}
		y--;
	}
	close(p->screenshot_param.fd);
	printf("Screenshot's made\n");
	error("", p, 0);
}
