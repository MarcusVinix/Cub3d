/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:45:27 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/12 01:16:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
		drawLine(&cub->img, line);
		i++;
	}
}

void	find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (isInsideMap(aux->next_touchx, aux->next_touchy, cub) == TRUE)
	{
		aux->xto_check = aux->next_touchx;
		if (utils->is_ray_facing_up == TRUE)
			aux->yto_check = aux->next_touchy + -1;
		else
			aux->yto_check = aux->next_touchy;
		if (mapHasWallAt(cub, aux->xto_check, aux->yto_check)) {
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
				[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = TRUE;
			break ;
		} else {
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

t_aux_ray	ray_horizontal(t_cub *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = FALSE;
	utils->y_intercept = floor(cub->player.y / TILE) * TILE;
	if (utils->is_ray_facing_down == TRUE)
		utils->y_intercept += TILE;
	utils->x_intercept = cub->player.x +
		(utils->y_intercept - cub->player.y) / tan(angle);
	utils->y_step = TILE;
	if (utils->is_ray_facing_up == TRUE)
		utils->y_step *= -1;
	utils->x_step = TILE / tan(angle);
	if (utils->is_ray_facing_left == TRUE && utils->x_step > 0)
		utils->x_step *= -1;
	if (utils->is_ray_facing_right == TRUE && utils->x_step < 0)
		utils->x_step *= -1;

	find_horz_intersection(&aux, utils, cub);
	return (aux);
}

void	find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (isInsideMap(aux->next_touchx, aux->next_touchy, cub) == TRUE)
	{
		aux->yto_check = aux->next_touchy;
		if (utils->is_ray_facing_left == TRUE)
			aux->xto_check = aux->next_touchx + -1;
		else
			aux->xto_check = aux->next_touchx;
		if (mapHasWallAt(cub, aux->xto_check, aux->yto_check)) {
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
				[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = TRUE;
			break ;
		} else {
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

t_aux_ray	ray_vertical(t_cub *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = FALSE;
	utils->x_intercept = floor(cub->player.x / TILE) * TILE;
	if (utils->is_ray_facing_right == TRUE)
		utils->x_intercept += TILE;
	utils->y_intercept = cub->player.y +
		(utils->x_intercept - cub->player.x) * tan(angle);
	utils->x_step = TILE;
	if (utils->is_ray_facing_left == TRUE)
		utils->x_step *= -1;
	utils->y_step = TILE * tan(angle);
	if (utils->is_ray_facing_up == TRUE && utils->y_step > 0)
		utils->y_step *= -1;
	if (utils->is_ray_facing_down == TRUE && utils->y_step < 0)
		utils->y_step *= -1;
	find_vert_intersection(&aux, utils, cub);
	return (aux);
}

void	get_ray_distance(t_cub *cub, t_aux_ray *horz, t_aux_ray *vert)
{
	if (horz->found_wall_hit == TRUE)
		horz->hit_distance = distanceBetweenPoints(
			cub->player.x, cub->player.y, horz->wall_hit_x, horz->wall_hit_y);
	else
		horz->hit_distance = INT_MAX;
	if (vert->found_wall_hit == TRUE)
		vert->hit_distance = distanceBetweenPoints(
			cub->player.x, cub->player.y, vert->wall_hit_x, vert->wall_hit_y);
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
	} else {
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

void	castRay(float ray_angle, int id, t_cub *cub)
{
	t_utils_ray utils;
	t_aux_ray	horz;
	t_aux_ray	vert;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub->rays[id], sizeof(t_ray));
	ray_angle = normalizeAngle(ray_angle);
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

void	castAllRays(t_cub *cub)
{
	float	ray_angle;
	int		col;

	col = 0;
	while (col < NUM_RAYS)
	{
		ray_angle = cub->player.rotation_angle + atan((col - NUM_RAYS / 2)
			/ cub->dist_proj_plane);
		castRay(ray_angle, col, cub);
		col++;
	}
}
