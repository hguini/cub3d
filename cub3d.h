/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:16:27 by hguini            #+#    #+#             */
/*   Updated: 2021/03/26 06:02:52 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct			s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_sprite
{
	float				x;
	float				y;
	float				dis;
}						t_sprite;

typedef struct			s_spr
{
	double				sprite_x;
	double				sprite_y;
	double				tran_x;
	double				tran_y;
	double				inv_det;
	int					spr_screen_x;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					tex_x;
	int					tex_y;
}						t_spr;

typedef struct			s_map
{
	char				*line;
	int					r_x;
	int					r_y;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int					f_r;
	int					f_g;
	int					f_b;
	int					c_r;
	int					c_g;
	int					c_b;
	char				**map;
	char				*str;
	void				*mlx;
	void				*win;
	float				plr_x;
	float				plr_y;
	float				dir_x;
	float				dir_y;
	float				plane_x;
	float				plane_y;
	int					h_cube;
	int					w_cube;
	char				light_side;
	int					sprite_count;
	int					count_line;
	float				camera_x;
	float				raydir_x;
	float				raydir_y;
	int					map_x;
	int					map_y;
	float				sidedist_x;
	float				sidedist_y;
	float				deltadist_x;
	float				deltadist_y;
	float				perpwalldist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	double				step;
	double				texpos;
	int					x;
	int					y;
	int					z;
	int					max;
	int					width;
	int					height;
	t_img				img_win;
	t_img				north_texture;
	t_img				south_texture;
	t_img				west_texture;
	t_img				east_texture;
	t_img				sprite_texture;
	t_sprite			*s_c;
	t_spr				spr;
}						t_map;

void					manage_parse(int fd, t_map *map);
void					ft_if_r(t_map *map);
void					ft_if_no(t_map *map);
void					ft_if_so(t_map *map);
void					ft_if_we(t_map *map);
void					ft_if_ea(t_map *map);
void					ft_if_s(t_map *map);
void					ft_if_f(t_map *map);
void					ft_if_c(t_map *map);
void					ft_if_map(t_map *map);
void					check_map(t_map *map);
void					check_valid(char spec);
int						skipping_symbol(t_map *map, char c, int i);
int						skipping_spaces(t_map *map, int i);
int						scipping_digits(t_map *map, int i);
void					screenshot(t_map *map);
int						check_file(char *str);
void					side_plr(t_map *map);
void					ft_pos_player(t_map *map);
void					check_valid(char spec);
void					sprite(t_map *map, double *zbuffer);
void					sort_sprites(t_map *map);
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int			my_mlx_pixel_take(t_img *img, int x, int y);
unsigned int			threatment_color(int r, int g, int b);
void					sprite_counter(t_map *map);
int						key_hook(int keycode, t_map *map);
void					draw_map(t_map *map);
void					move_w(t_map *map, float movespeed);
void					move_s(t_map *map, float movespeed);
void					move_d(t_map *map, float movespeed);
void					move_a(t_map *map, float movespeed);
void					rotation_right(t_map *map, float rotspeed);
void					rotation_left(t_map *map, float rotspeed);
void					filling_texture_img(t_map *map);
void					map_assign(t_map *map);
void					step_sidedist(t_map *map);
void					check_hit(t_map *map);
void					map_assign_again(t_map *map);
int						close_window(t_map *map);

#endif
