/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:45:27 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 23:02:51 by mavinici         ###   ########.fr       */
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

void	castRay(float ray_angle, int id, t_cub *cub)
{
	t_utils_ray utils;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub->rays[id], sizeof(t_ray));
	ray_angle = normalizeAngle(ray_angle);

	utils.is_ray_facing_down = is_ray_facing_down(ray_angle);
	utils.is_ray_facing_up = is_ray_racing_up(ray_angle);
	utils.is_ray_facing_right = is_ray_facing_right(ray_angle);
	utils.is_ray_facing_left = is_ray_facing_left(ray_angle);

	// HORIZONTAL RAY-GRID INTERSECTION CODE
	int		foundHorzWallHit = FALSE;
	float	horzwall_hit_x = 0;
	float	horzwall_hit_y = 0;
	int		horzWallContent = 0;

	// Find The y-cordinate of the closest horizontal grid intersectionn
	utils.y_intercept = floor(cub->player.y / TILE) * TILE;
	if (utils.is_ray_facing_down == TRUE)
		utils.y_intercept += TILE;
	

	// Find the x-coordinate of the closest horizonntal grid intersection
	utils.x_intercept = cub->player.x +
		(utils.y_intercept - cub->player.y) / tan(ray_angle);

	//calculate tthe increment x_step andd y_step
	utils.y_step = TILE;
	if (utils.is_ray_facing_up == TRUE)
		utils.y_step *= -1;
	
	utils.x_step = TILE / tan(ray_angle);
	if (utils.is_ray_facing_left == TRUE && utils.x_step > 0)
		utils.x_step *= -1;
	if (utils.is_ray_facing_right == TRUE && utils.x_step < 0)
		utils.x_step *= -1;
	
	float	nextHorzTouchX = utils.x_intercept;
	float	nextHorzTouchY = utils.y_intercept;

	//increment x_step and y_step untill we find a wall
	while (isInsideMap(nextHorzTouchX, nextHorzTouchY, cub) == TRUE)
	// while (nextHorzTouchX >= 0 && nextHorzTouchX <= getLenght(cub, nextHorzTouchY) * TILE
	// 	&& nextHorzTouchY >= 0 && nextHorzTouchY <= cub->map_info.height * TILE)
	{
		float	xToCheck = nextHorzTouchX;
		float	yToCheck;
		if (utils.is_ray_facing_up == TRUE)
			yToCheck = nextHorzTouchY + -1;
		else
			yToCheck = nextHorzTouchY;
		if (mapHasWallAt(cub, xToCheck, yToCheck)) {
			//fouund  a wall
			horzwall_hit_x = nextHorzTouchX;
			horzwall_hit_y = nextHorzTouchY;
			horzWallContent = cub->map[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)] - '0';
			// printf("content horz %i  id %i\n ", horzWallContent, id);
			foundHorzWallHit = TRUE;
			break ;
		} else {
			nextHorzTouchX += utils.x_step;
			nextHorzTouchY += utils.y_step;
		}
	}


	/// VERTICAL RAY-GRID INTERSECTION CODE
	int		foundVertWallHit = FALSE;
	float	Vertwall_hit_x = 0;
	float	Vertwall_hit_y = 0;
	int		VertWallContent = 0;

	// Find The x-cordinate of the closest vertical grid intersectionn
	utils.x_intercept = floor(cub->player.x / TILE) * TILE;
	if (utils.is_ray_facing_right == TRUE)
		utils.x_intercept += TILE;
	

	// Find the y-coordinate of the closest horizonntal grid intersection
	utils.y_intercept = cub->player.y +
		(utils.x_intercept - cub->player.x) * tan(ray_angle);

	//calculate tthe increment x_step andd y_step
	utils.x_step = TILE;
	if (utils.is_ray_facing_left == TRUE)
		utils.x_step *= -1;
	
	utils.y_step = TILE * tan(ray_angle);
	if (utils.is_ray_facing_up == TRUE && utils.y_step > 0)
		utils.y_step *= -1;
	if (utils.is_ray_facing_down == TRUE && utils.y_step < 0)
		utils.y_step *= -1;
	
	float	nextVertTouchX = utils.x_intercept;
	float	nextVertTouchY = utils.y_intercept;

	//increment x_step and y_step untill we find a wall
	while (isInsideMap(nextVertTouchX, nextVertTouchY, cub) == TRUE)
	// while (nextVertTouchX >= 0 && nextVertTouchX <= getLenght(cub, nextVertTouchY) * TILE
	// 	&& nextVertTouchY >= 0 && nextVertTouchY <= cub->map_info.height * TILE)
	{
		float	yToCheck = nextVertTouchY;
		float	xToCheck;
		if (utils.is_ray_facing_left == TRUE)
			xToCheck = nextVertTouchX + -1;
		else
			xToCheck = nextVertTouchX;
		if (mapHasWallAt(cub, xToCheck, yToCheck)) {
			//fouund  a wall
			Vertwall_hit_x = nextVertTouchX;
			Vertwall_hit_y = nextVertTouchY;
			VertWallContent = cub->map[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)] - '0';
			foundVertWallHit = TRUE;
			break ;
		} else {
			nextVertTouchX += utils.x_step;
			nextVertTouchY += utils.y_step;
		}
	}

	// Calculate both horizontal and vertical hit distances and choose the smallest oe
	float	horzHitDistance;
	float	vertHitDistance;

	if (foundHorzWallHit == TRUE)
		horzHitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, horzwall_hit_x, horzwall_hit_y);
	else
		horzHitDistance = INT_MAX;
	if (foundVertWallHit == TRUE)
		vertHitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, Vertwall_hit_x, Vertwall_hit_y);
	else
		vertHitDistance = INT_MAX;

	if (vertHitDistance < horzHitDistance)
	{
		cub->rays[id].distance = vertHitDistance;
		cub->rays[id].wall_hit_x = Vertwall_hit_x;
		cub->rays[id].wall_hit_y = Vertwall_hit_y;
		cub->rays[id].wall_hit_cotent = VertWallContent;
		if (utils.is_ray_facing_left == TRUE)
			cub->rays[id].wall_hit_cotent = WE;
		else
			cub->rays[id].wall_hit_cotent = EA;
		cub->rays[id].was_hit_vertical = TRUE;
	} else {
		cub->rays[id].distance = horzHitDistance;
		cub->rays[id].wall_hit_x = horzwall_hit_x;
		cub->rays[id].wall_hit_y = horzwall_hit_y;
		cub->rays[id].wall_hit_cotent = horzWallContent;
		if (utils.is_ray_facing_up == TRUE)
			cub->rays[id].wall_hit_cotent = NO;
		else
			cub->rays[id].wall_hit_cotent = SO;
		cub->rays[id].was_hit_vertical = FALSE;
	}
	cub->rays[id].ray_angle = ray_angle;
}

void	castAllRays(t_cub *cub)
{
	// start first ray subtracting half of our FOV
	float	ray_angle;
	int		col;

	col = 0;
	while (col < NUM_RAYS)
	{
		ray_angle = cub->player.rotation_angle + atan((col - NUM_RAYS / 2) / DIST_PROJ_PLANE);
		castRay(ray_angle, col, cub);
		col++;
	}
}