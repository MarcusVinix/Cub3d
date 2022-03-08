/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:45:27 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 01:22:54 by mavinici         ###   ########.fr       */
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
		line.x2 = MINIMAP_SCALE_FACTOR * cub->rays[i].wallHitX;
		line.y2 = MINIMAP_SCALE_FACTOR * cub->rays[i].wallHitY;
		drawLine(&cub->img, line);
		i++;
	}
}

int	isRayFacingDown(float angle)
{
	if (angle > 0 && angle < PI)
		return (TRUE);
	else
		return (FALSE);
}

int	isRayFacingUp(float angle)
{
	if (isRayFacingDown(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}

int	isRayFacingRight(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (TRUE);
	else
		return (FALSE);
}

int	isRayFacingLeft(float angle)
{
	if (isRayFacingRight(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}

void	castRay(float rayAngle, int id, t_cub *cub)
{
	t_utils_ray utils;

	ft_bzero(&utils, sizeof(t_utils_ray));
	ft_bzero(&cub->rays[id], sizeof(t_ray));
	rayAngle = normalizeAngle(rayAngle);

	utils.isRayFacingDown = isRayFacingDown(rayAngle);
	utils.isRayFacingUp = isRayFacingUp(rayAngle);
	utils.isRayFacingRight = isRayFacingRight(rayAngle);
	utils.isRayFacingLeft = isRayFacingLeft(rayAngle);

	// HORIZONTAL RAY-GRID INTERSECTION CODE
	int		foundHorzWallHit = FALSE;
	float	horzWallHitX = 0;
	float	horzWallHitY = 0;
	int		horzWallContent = 0;

	// Find The y-cordinate of the closest horizontal grid intersectionn
	utils.yIntercept = floor(cub->player.y / TILE) * TILE;
	if (utils.isRayFacingDown == TRUE)
		utils.yIntercept += TILE;
	

	// Find the x-coordinate of the closest horizonntal grid intersection
	utils.xIntercept = cub->player.x +
		(utils.yIntercept - cub->player.y) / tan(rayAngle);

	//calculate tthe increment xstep andd ystep
	utils.yStep = TILE;
	if (utils.isRayFacingUp == TRUE)
		utils.yStep *= -1;
	
	utils.xStep = TILE / tan(rayAngle);
	if (utils.isRayFacingLeft == TRUE && utils.xStep > 0)
		utils.xStep *= -1;
	if (utils.isRayFacingRight == TRUE && utils.xStep < 0)
		utils.xStep *= -1;
	
	float	nextHorzTouchX = utils.xIntercept;
	float	nextHorzTouchY = utils.yIntercept;

	//increment xstep and ystep untill we find a wall
	while (isInsideMap(nextHorzTouchX, nextHorzTouchY, cub) == TRUE)
	// while (nextHorzTouchX >= 0 && nextHorzTouchX <= getLenght(cub, nextHorzTouchY) * TILE
	// 	&& nextHorzTouchY >= 0 && nextHorzTouchY <= cub->map_info.height * TILE)
	{
		float	xToCheck = nextHorzTouchX;
		float	yToCheck;
		if (utils.isRayFacingUp == TRUE)
			yToCheck = nextHorzTouchY + -1;
		else
			yToCheck = nextHorzTouchY;
		if (mapHasWallAt(cub, xToCheck, yToCheck)) {
			//fouund  a wall
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = cub->map[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)] - '0';
			// printf("content horz %i  id %i\n ", horzWallContent, id);
			foundHorzWallHit = TRUE;
			break ;
		} else {
			nextHorzTouchX += utils.xStep;
			nextHorzTouchY += utils.yStep;
		}
	}


	/// VERTICAL RAY-GRID INTERSECTION CODE
	int		foundVertWallHit = FALSE;
	float	VertWallHitX = 0;
	float	VertWallHitY = 0;
	int		VertWallContent = 0;

	// Find The x-cordinate of the closest vertical grid intersectionn
	utils.xIntercept = floor(cub->player.x / TILE) * TILE;
	if (utils.isRayFacingRight == TRUE)
		utils.xIntercept += TILE;
	

	// Find the y-coordinate of the closest horizonntal grid intersection
	utils.yIntercept = cub->player.y +
		(utils.xIntercept - cub->player.x) * tan(rayAngle);

	//calculate tthe increment xstep andd ystep
	utils.xStep = TILE;
	if (utils.isRayFacingLeft == TRUE)
		utils.xStep *= -1;
	
	utils.yStep = TILE * tan(rayAngle);
	if (utils.isRayFacingUp == TRUE && utils.yStep > 0)
		utils.yStep *= -1;
	if (utils.isRayFacingDown == TRUE && utils.yStep < 0)
		utils.yStep *= -1;
	
	float	nextVertTouchX = utils.xIntercept;
	float	nextVertTouchY = utils.yIntercept;

	//increment xstep and ystep untill we find a wall
	while (isInsideMap(nextVertTouchX, nextVertTouchY, cub) == TRUE)
	// while (nextVertTouchX >= 0 && nextVertTouchX <= getLenght(cub, nextVertTouchY) * TILE
	// 	&& nextVertTouchY >= 0 && nextVertTouchY <= cub->map_info.height * TILE)
	{
		float	yToCheck = nextVertTouchY;
		float	xToCheck;
		if (utils.isRayFacingLeft == TRUE)
			xToCheck = nextVertTouchX + -1;
		else
			xToCheck = nextVertTouchX;
		if (mapHasWallAt(cub, xToCheck, yToCheck)) {
			//fouund  a wall
			VertWallHitX = nextVertTouchX;
			VertWallHitY = nextVertTouchY;
			VertWallContent = cub->map[(int)floor(yToCheck / TILE)][(int)floor(xToCheck / TILE)] - '0';
			foundVertWallHit = TRUE;
			break ;
		} else {
			nextVertTouchX += utils.xStep;
			nextVertTouchY += utils.yStep;
		}
	}

	// Calculate both horizontal and vertical hit distances and choose the smallest oe
	float	horzHitDistance;
	float	vertHitDistance;

	if (foundHorzWallHit == TRUE)
		horzHitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, horzWallHitX, horzWallHitY);
	else
		horzHitDistance = INT_MAX;
	if (foundVertWallHit == TRUE)
		vertHitDistance = distanceBetweenPoints(
			cub->player.x, cub->player.y, VertWallHitX, VertWallHitY);
	else
		vertHitDistance = INT_MAX;

	if (vertHitDistance < horzHitDistance)
	{
		cub->rays[id].distance = vertHitDistance;
		cub->rays[id].wallHitX = VertWallHitX;
		cub->rays[id].wallHitY = VertWallHitY;
		cub->rays[id].wallHitCotent = VertWallContent;
		cub->rays[id].wasHitVertical = TRUE;
	} else {
		cub->rays[id].distance = horzHitDistance;
		cub->rays[id].wallHitX = horzWallHitX;
		cub->rays[id].wallHitY = horzWallHitY;
		cub->rays[id].wallHitCotent = horzWallContent;
		cub->rays[id].wasHitVertical = FALSE;
	}
	cub->rays[id].rayAngle = rayAngle;
}

void	castAllRays(t_cub *cub)
{
	// start first ray subtracting half of our FOV
	float	rayAngle;
	int		col;

	col = 0;
	while (col < NUM_RAYS)
	{
		rayAngle = cub->player.rotationAngle + atan((col - NUM_RAYS / 2) / DIST_PROJ_PLANE);
		castRay(rayAngle, col, cub);
		col++;
	}
}