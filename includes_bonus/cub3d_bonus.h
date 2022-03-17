/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/17 21:03:05 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H

# define CUB3D_BONUS_H

# include	"../libft/libft.h"
# include	"colors_bonus.h"
# include	<ft_errors_bonus.h>
# include	<map_bonus.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	<math.h>
# include	<structs_bonus.h>
# include	<limits.h>

//validation
int				is_invalid_arg(int argc, char **argv);
int				file_exist(char *map_path);
int				check_extension(char *str, char *extension);
int				check_map(char *path_map, t_cub *cub);
t_collor		check_color(char ***colors);

int				error_msg(char *msg, int level, t_cub *cub);
//free
void			free_struct(t_cub *cub);
void			free_images(t_cub *cub);
void			free_mlx_all(t_cub *cub);

// draw
void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);
void			draw_ray(t_data *img, t_pos pos);
void			draw_rect(t_data *img, t_rect rect);
void			draw_line(t_data *img, t_line line);

//actions
void			move_player(t_cub *cub);
void			update(t_cub *cub);
int				action_loop(t_cub *cub);
int				action(int keycode, t_cub *cub);

//render game
void			draw_background(t_data *img, int color_up, int color_down);
void			render_map(t_cub *cub);
void			render_player(t_cub *cub);
void			draw_gaming(t_cub *cub);
void			render_ray(t_cub *cub);
void			cast_ray(float ray_angle, int id, t_cub *cub);
void			cast_all_rays(t_cub *cub);
void			generate3d_projection(t_cub *cub);
void			find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub *cub);
t_aux_ray		ray_horizontal(t_cub *cub, t_utils_ray *utils, float angle);
void			find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils,
					t_cub *cub);
t_aux_ray		ray_vertical(t_cub *cub, t_utils_ray *utils, float angle);
void			render_sprite_projection(t_cub *cub);
void			render_map_sprites(t_cub *cub);

//utils
int				map_has_wall_at(t_cub *cub, float x, float y);
int				map_has_sprite(t_cub *cub, float x, float y);
int				close_win(t_cub *cub);
void			setup(t_cub *cub);
void			normalize_angle(float *angle);
float			distance_between_points(float x1, float y1, float x2, float y2);
int				get_lenght(t_cub *cub, float line);
int				is_inside_map(float x, float y, t_cub *cub);
void			change_color_intesity(uint32_t *color, float factor);
int				is_ray_facing_down(float angle);
int				is_ray_racing_up(float angle);
int				is_ray_facing_right(float angle);
int				is_ray_facing_left(float angle);
void			check_inverse_offset_x(t_ray ray, int *texture_offset_x);
void			build_main_img(t_cub *cub);
void			start_textures(t_cub *cub);
int				get_color_mlx(t_rgb color);
void			sprites(t_data *img, void *mlx, char *path);
uint32_t		*get_texture_buffer(t_data *img);
void			start_sprites(t_cub *cub);
void			setup_sprites(t_cub *cub);
void			init_some_values_sprites(t_utils_sprite *var, t_cub *cub);
void			sort_visible_sprites(t_utils_sprite *var);

#endif
