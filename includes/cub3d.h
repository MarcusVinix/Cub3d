/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/11 16:07:03 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include	"../libft/libft.h"
# include	"colors.h"
# include	<ft_errors.h>
# include	<map.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	<math.h>
# include	<structs.h>
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
void			draw_line(t_data *img, t_pos pos, int color, int sig);
void			draw_ray(t_data *img, t_pos pos);
void			drawRect(t_data *img, t_rect rect);
void			drawLine(t_data *img, t_line line);

//actions
void			movePlayer(t_cub *cub);
void			update(t_cub *cub);
int				action_loop(t_cub *cub);
int				action(int keycode, t_cub *cub);

//render game
void			draw_background(t_data *img, int color_up, int color_down);
void			render_map(t_cub *cub);
void			render_player(t_data *img, t_player player);
void			draw_gaming(t_cub *cub);
void			renderRays(t_cub *cub);
void			castRay(float ray_angle, int id, t_cub *cub);
void			castAllRays(t_cub *cub);
void			generate3DProjection(t_cub *cub);

//utils
int				mapHasWallAt(t_cub *cub,float x, float y);
int				close_win(t_cub *cub);
void			setup(t_cub *cub);
float			normalizeAngle(float angle);
float			distanceBetweenPoints(float x1, float y1, float x2, float y2);
int				getLenght(t_cub *cub, float	line);
int				isInsideMap(float x, float y, t_cub *cub);
void			changeColorIntesity(uint32_t *color, float factor);
int				is_ray_facing_down(float angle);
int				is_ray_racing_up(float angle);
int				is_ray_facing_right(float angle);
int				is_ray_facing_left(float angle);
void			check_inverse_offset_x(t_ray ray, int *texture_offset_x);
void			build_main_img(t_cub *cub);


#endif
