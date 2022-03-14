/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:45:27 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/14 21:16:07 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	render_ray(t_cub *cub)
{
	t_line	line;
	int		i;

	i = 0;
	while (i < NUM_RAYS)
	{
		ft_bzero(&line, sizeof(t_line));
		line.color = REDMLX;
		line.x1 = MINIMAP_SCALE_FACTOR * cub->player.x;
		line.y1 = MINIMAP_SCALE_FACTOR * cub->player.y;
		line.x2 = MINIMAP_SCALE_FACTOR * cub->rays[i].wall_hit_x;
		line.y2 = MINIMAP_SCALE_FACTOR * cub->rays[i].wall_hit_y;
		draw_line(&cub->img, line);
		i++;
	}
}

void	get_ray_distance(t_cub *cub, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == TRUE)
		horz->hit_distance = distance_between_points(
				cub->player.x, cub->player.y, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = INT_MAX;
	if (vert->found_wall_hit == TRUE)
		vert->hit_distance = distance_between_points(
				cub->player.x, cub->player.y, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = INT_MAX;
}

void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert)
{
	if (vert.hit_distance < horz.hit_distance)
	{
		ray->distance = vert.hit_distance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->wall_hit_cotent = vert.wall_content;
		if (utils.is_ray_facing_left == TRUE)
			ray->wall_hit_cotent = WE;
		else
			ray->wall_hit_cotent = EA;
		ray->was_hit_vertical = TRUE;
	}
	else
	{
		ray->distance = horz.hit_distance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
		ray->wall_hit_cotent = horz.wall_content;
		if (utils.is_ray_facing_up == TRUE)
			ray->wall_hit_cotent = NO;
		else
			ray->wall_hit_cotent = SO;
		ray->was_hit_vertical = FALSE;
	}
}

void	cast_ray(float ray_angle, int id, t_cub *cub)
{
	t_utils_ray	utils;
	t_aux_ray	horz;
	t_aux_ray	vert;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub->rays[id], sizeof(t_ray));
	ray_angle = normalize_angle(ray_angle);
	utils.is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils.is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils.is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils.is_ray_facing_left = is_ray_facing_left(ray_angle);
	horz = ray_horizontal(cub, &utils, ray_angle);
	vert = ray_vertical(cub, &utils, ray_angle);
	get_ray_distance(cub, &horz, &vert);
	get_values_of_ray(&cub->rays[id], utils, horz, vert);
	cub->rays[id].ray_angle = ray_angle;
}

void	cast_all_rays(t_cub *cub)
{
	float	ray_angle;
	int		col;

	col = 0;
	while (col < NUM_RAYS)
	{
		ray_angle = cub->player.rotation_angle + atan((col - NUM_RAYS / 2)
				/ cub->dist_proj_plane);
		cast_ray(ray_angle, col, cub);
		col++;
	}
}
