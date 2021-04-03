/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:34:39 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/01 20:05:37 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		run_game(t_param *p)
{
	move_operator(p);
	raycast(p);
	drawsprites(p);
	if (!p->screenshot)
		mlx_put_image_to_window(p->mlx->ptr, p->mlx->win, p->mlx->img, 0, 0);
	return (0);
}

void	error(char *message, t_param *p, int win)
{
	int i;

	i = 0;
	write(2, message, ft_strlen(message));
	if (p->map->tab)
	{
		while (p->map->tab[i])
		{
			free(p->map->tab[i]);
			i++;
		}
		free(p->map->tab);
	}
	free(p->mlx->tex.n_name);
	free(p->mlx->tex.s_name);
	free(p->mlx->tex.e_name);
	free(p->mlx->tex.w_name);
	free(p->mlx->tex.i_name);
	if (win == 1)
		mlx_destroy_window(p->mlx->ptr, p->mlx->win);
	exit(EXIT_SUCCESS);
}

int		ft_exit(t_param *p)
{
	int i;

	i = 0;
	if (p->map->tab)
	{
		while (p->map->tab[i])
		{
			free(p->map->tab[i]);
			i++;
		}
		free(p->map->tab);
	}
	free(p->mlx->tex.n_name);
	free(p->mlx->tex.s_name);
	free(p->mlx->tex.e_name);
	free(p->mlx->tex.w_name);
	free(p->mlx->tex.i_name);
	free(p->mlx->spr_order);
	free(p->mlx->spr);
	mlx_destroy_window(p->mlx->ptr, p->mlx->win);
	exit(EXIT_SUCCESS);
	return (1);
}

int		start_all(t_param *p, char **av)
{
	ft_parse(av[1], p);
	p->mlx->ptr = mlx_init();
	n_init(p);
	s_init(p);
	w_init(p);
	e_init(p);
	spr_init(p);
	p->mlx->img = mlx_new_image(p->mlx->ptr, p->mlx->screen_w,
				p->mlx->screen_h);
	p->mlx->d_ad = (int *)mlx_get_data_addr(p->mlx->img,
				&(p->mlx->bits), &(p->mlx->sl), &(p->mlx->ed));
	if (p->screenshot == 1)
		take_screenshot(p);
	p->mlx->win = mlx_new_window(p->mlx->ptr, p->mlx->screen_w,
		p->mlx->screen_h, "cub3D");
	mlx_hook(p->mlx->win, 2, 1, record_press, (void *)p);
	mlx_key_hook(p->mlx->win, record_release, (void *)p);
	mlx_loop_hook(p->mlx->ptr, run_game, (void *)p);
	mlx_hook(p->mlx->win, 17, 0, ft_exit, p);
	mlx_loop(p->mlx->ptr);
	return (1);
}

int		main(int ac, char **av)
{
	t_param		p;
	t_mlx		mlx;
	t_player	one;
	t_world		map;
	t_ray		ray;

	p.mlx = &mlx;
	p.pl = &one;
	p.map = &map;
	p.ray = &ray;
	p.mlx->spr = NULL;
	p.screenshot = 0;
	if (ac == 3 && check_save(av[2], "--save"))
	{
		p.screenshot = 1;
		start_all(&p, av);
	}
	if (ac == 2)
		start_all(&p, av);
}
