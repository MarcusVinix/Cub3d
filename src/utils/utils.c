/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:20:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/04 15:39:16 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	mapHasWallAt(float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;
	if (x < 0 || x >= MAP_NUM_COLS * TILE || y < 0 || y >= MAP_NUM_ROWS * TILE)
		return (FALSE);
	mapGridIndexX = floor(x / TILE);
	mapGridIndexY = floor(y / TILE);
	return (map[mapGridIndexY][mapGridIndexX] != 0);
}

/* Free the allocated memory of the map and close the window */
int	close_win(t_cub *cub)
{
	(void)cub;
	//free_map(game->map.map, &game->map);
	exit(0);
}

void	setup(t_cub *cub)
{
	cub->player.x = WIDTH / 2;
	cub->player.y = HEIGHT / 2;
	cub->player.width = 5;
	cub->player.height = 5;
	cub->player.turnDirection = 0;
	cub->player.walkDirection = 0;
	cub->player.rotationAngle = PI / 2;
	cub->player.walkSpeed = 15;
	cub->player.turnSpeed = 15 * (PI / 180);

    	//load textures from textures.h
	cub->textures[0] = (uint32_t*)REDBRICK_TEXTURE;
	cub->textures[1] = (uint32_t*)PURPLESTONE_TEXTURE;
	cub->textures[2] = (uint32_t*)MOSSYSTONE_TEXTURE;
	cub->textures[3] = (uint32_t*)GRAYSTONE_TEXTURE;
	cub->textures[4] = (uint32_t*)COLORSTONE_TEXTURE;
	cub->textures[5] = (uint32_t*)BLUESTONE_TEXTURE;
	cub->textures[6] = (uint32_t*)WOOD_TEXTURE;
	cub->textures[7] = (uint32_t*)EAGLE_TEXTURE;
}

float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 -y1)));
}
