/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquintan <tquintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:35:25 by tquintan          #+#    #+#             */
/*   Updated: 2021/04/03 12:28:10 by tquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include "stdio.h"
# include "get_next_line/get_next_line.h"
# define MAPW 24
# define MAPH 24

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 8
# define TURN 0.05

typedef struct		s_tex
{
	char			*n_name;
	unsigned int	*n;
	int				n_h;
	int				n_w;
	int				n_sl;
	int				n_sb;
	int				n_eb;
	char			*s_name;
	unsigned int	*s;
	int				s_h;
	int				s_w;
	int				s_sl;
	int				s_sb;
	int				s_eb;
	char			*e_name;
	unsigned int	*e;
	int				e_h;
	int				e_w;
	int				e_sl;
	int				e_sb;
	int				e_eb;
	char			*w_name;
	unsigned int	*w;
	int				w_h;
	int				w_w;
	int				w_sl;
	int				w_sb;
	int				w_eb;
	char			*i_name;
	unsigned int	*i;
	int				i_h;
	int				i_w;
	int				i_sl;
	int				i_sb;
	int				i_eb;
	unsigned int	c;
	unsigned int	f;
}					t_tex;

typedef struct		s_done
{
	int				res;
	int				n;
	int				s;
	int				w;
	int				e;
	int				spr;
	int				c;
	int				f;
}					t_done;

typedef	struct		s_spritetmp
{
	float			x;
	float			y;
}					t_spritetmp;

typedef struct		s_sprtools
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				tex_x;
	int				tex_y;
	int				x;
	int				y;
	int				d;
}					t_sprtools;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*d_ad;
	int				bits;
	int				bpp;
	int				sl;
	int				ed;
	int				l_height;
	int				l_start;
	int				l_end;
	int				color;
	t_tex			tex;
	int				*txt_data;
	int				text_sl;
	int				text_h;
	int				text_w;
	int				text_x;
	int				screen_h;
	int				screen_w;
	int				flag_for_h;
	int				flag_for_w;
	int				x;
	int				sprite_hit;
	int				sprite_x;
	int				spr_h;
	int				spr_start;
	int				spr_end;
	t_spritetmp		*spr;
	t_spritetmp		*sorted_sprites;
	int				*spr_order;
	int				spr_number;
	int				fr;
	int				fg;
	int				fb;
	int				sr;
	int				sg;
	int				sb;
}					t_mlx;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	char			forward;
	char			backward;
	char			left;
	char			right;
	char			leftrot;
	char			rightrot;
	char			pos;
}					t_player;

typedef struct		s_world
{
	double			time;
	double			oldtime;
	int				x;
	int				y;
	int				oldx;
	int				oldy;
	int				step_x;
	int				step_y;
	char			**tab;
	int				spr;
	int				max_x;
	int				max_y;
}					t_world;

typedef struct		s_ray
{
	double			dir_x;
	double			dir_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			walldist;
	double			spritedist;
	char			walldir;
	double			wallx;
	int				wallside;
	double			zbuffer[4000];
}					t_ray;

typedef struct		s_flags
{
	int				mv_forward;
	int				mv_left;
	int				mv_back;
	int				mv_right;
	int				rotate_left;
	int				rotate_right;
}					t_flags;

typedef struct		s_screenshot
{
	int				padsize;
	unsigned int	zero[3];
	int				fd;
}					t_screenshot;

typedef struct		s_param
{
	t_mlx			*mlx;
	t_player		*pl;
	t_world			*map;
	t_ray			*ray;
	t_done			done;
	t_flags			flags;
	t_sprtools		spr_tools;
	t_sprtools		current_spr;
	t_spritetmp		spr_tmp;
	t_screenshot	screenshot_param;
	int				i;
	int				j;
	char			**lines;
	int				screenshot;
	int				flag_for_map;
	int				comma;
}					t_param;

int					run_game(t_param *p);
void				error(char *message, t_param *p, int win);
int					ft_exit(t_param *p);
int					start_all(t_param *p, char **av);
int					get_color(t_param *p, int x, int y);
int					drawline(t_param *p, int x, int text_x);
void				define_line(t_param *p);
void				choose_texture(t_param *p);
void				fov_and_pos(t_param *p, int x);
void				get_step(t_param *p);
void				wallhit(t_param *p);
void				walldist_dir(t_param *p, int x);
void				raycast(t_param *p);
void				int_to_char(unsigned char *c, int i);
int					bmp_header(t_param *p);
int					pixel_put_screenshot(t_param *p, int x, int y);
void				take_screenshot(t_param *p);
void				sort_sprites(t_param *p);
void				sprite_size(t_param *p);
int					get_color_spr(t_param *p, int x, int y);
int					spr_param_checker(t_param *p);
void				drawspritelines(t_param *p);
void				sprite_params(t_param *p, int i);
void				drawsprites(t_param *p);
void				ft_move(t_param *p, double c);
void				ft_strafe(t_param *p, double c);
void				ft_rotate(t_param *p, double c);
int					record_press(int keycode, t_param *p);
int					record_release(int keycode, t_param *p);
void				move_operator(t_param *p);
int					check_right_border(t_param *p, int i, int j);
int					check_left_border(t_param *p, int i, int j);
int					check_top_border(t_param *p, int i, int j);
int					check_bottom_border(t_param *p, int i, int j);
int					check_borders(t_param *p, int i, int j);
int					check_save(char *arg, char *save);
void				helper(t_param *p, char c);
void				ft_pos_helper(t_param *p, char c, int i, int j);
void				ft_pos(t_param *p);
int					ft_slist(t_param *p);
int					done_all(t_param *p);
int					check_line(char *line, t_param *p);
int					parse_params(char *arr, t_param *p);
int					parse_file(int fd, t_param *p);
int					ft_parse(char *file_name, t_param *p);
int					color_helper(char *str);
void				parse_floor(char *str, t_param *p);
void				parse_ceil(char *str, t_param *p);
char				*space_remover(char *str, t_param *p);
void				init_map(t_param *p, t_list *list);
void				check_map1(t_param *p);
void				res_helper(t_param *p, char *line);
void				parse_res(char *line, t_param *p);
void				parse_n_txt(char *line, t_param *p);
void				parse_s_txt(char *line, t_param *p);
void				parse_w_txt(char *line, t_param *p);
void				parse_e_txt(char *line, t_param *p);
void				parse_sprite_txt(char *line, t_param *p);
int					red(char *str, t_param *p, int flag);
int					green(char *str, t_param *p, int flag);
int					blue(char *str, t_param *p, int flag);
void				my_mlx_pixel_put(t_param *p, int x, int y, int color);
void				n_init(t_param *p);
void				s_init(t_param *p);
void				w_init(t_param *p);
void				e_init(t_param *p);
void				spr_init(t_param *p);
void				choose_text_help(t_param *p);
void				free_list(t_list *list);
void				checker2(t_param *p, char *line);
void				line_validator(char *line, t_param *p);
#endif
