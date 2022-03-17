/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:20:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/17 21:03:53 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	check_inverse_offset_x(t_ray ray, int *texture_offset_x)
{
	if (ray.was_hit_vertical == FALSE
		&& is_ray_facing_down(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
	if (ray.was_hit_vertical == TRUE
		&& is_ray_facing_left(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
}

void	normalize_angle(float *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_some_values_sprites(t_utils_sprite *var, t_cub *cub)
{
	var->fov = 60 * (PI / 180);
	var->i = -1;
	var->visible_sprites = ft_calloc(cub->num_sprites + 1, sizeof(t_sprite));
	var->epsilon = 0.2;
}
