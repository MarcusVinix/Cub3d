/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:45:27 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/10 13:35:08 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	renderRays(t_cub *cub)
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
	aux->nextTouchX = utils->x_intercept;
	aux->nextTouchY = utils->y_intercept;
	while (isInsideMap(aux->nextTouchX, aux->nextTouchY, cub) == TRUE)
	{
		aux->xToCheck = aux->nextTouchX;
		if (utils->is_ray_facing_up == TRUE)
			aux->yToCheck = aux->nextTouchY + -1;
		else
			aux->yToCheck = aux->nextTouchY;
		if (mapHasWallAt(cub, aux->xToCheck, aux->yToCheck)) {
			aux->wall_hit_x = aux->nextTouchX;
			aux->wall_hit_y = aux->nextTouchY;
			aux->WallContent = cub->map[(int)floor(aux->yToCheck / TILE)]
				[(int)floor(aux->xToCheck / TILE)] - '0';
			aux->foundWallHit = TRUE;
			break ;
		} else {
			aux->nextTouchX += utils->x_step;
			aux->nextTouchY += utils->y_step;
		}
	}
}

t_aux_ray	ray_horizontal(t_cub *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.foundWallHit = FALSE;
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
	aux->nextTouchX = utils->x_intercept;
	aux->nextTouchY = utils->y_intercept;
	while (isInsideMap(aux->nextTouchX, aux->nextTouchY, cub) == TRUE)
	{
		aux->yToCheck = aux->nextTouchY;
		if (utils->is_ray_facing_left == TRUE)
			aux->xToCheck = aux->nextTouchX + -1;
		else
			aux->xToCheck = aux->nextTouchX;
		if (mapHasWallAt(cub, aux->xToCheck, aux->yToCheck)) {
			aux->wall_hit_x = aux->nextTouchX;
			aux->wall_hit_y = aux->nextTouchY;
			aux->WallContent = cub->map[(int)floor(aux->yToCheck / TILE)]
				[(int)floor(aux->xToCheck / TILE)] - '0';
			aux->foundWallHit = TRUE;
			break ;
		} else {
			aux->nextTouchX += utils->x_step;
			aux->nextTouchY += utils->y_step;
		}
	}
}

t_aux_ray	ray_vertical(t_cub *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.foundWallHit = FALSE;
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
	if (horz->foundWallHit == TRUE)
		horz->HitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, horz->wall_hit_x, horz->wall_hit_y);
	else
		horz->HitDistance = INT_MAX;
	if (vert->foundWallHit == TRUE)
		vert->HitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, vert->wall_hit_x, vert->wall_hit_y);
	else
		vert->HitDistance = INT_MAX;
}

void	get_values_of_ray(t_ray *ray, t_utils_ray utils,
	t_aux_ray horz, t_aux_ray vert)
{
	if (vert.HitDistance < horz.HitDistance)
	{
		ray->distance = vert.HitDistance;
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->wall_hit_cotent = vert.WallContent;
		if (utils.is_ray_facing_left == TRUE)
			ray->wall_hit_cotent = WE;
		else
			ray->wall_hit_cotent = EA;
		ray->was_hit_vertical = TRUE;
	} else {
		ray->distance = horz.HitDistance;
		ray->wall_hit_x = horz.wall_hit_x;
		ray->wall_hit_y = horz.wall_hit_y;
		ray->wall_hit_cotent = horz.WallContent;
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
			/ DIST_PROJ_PLANE);
		castRay(ray_angle, col, cub);
		col++;
	}
}
