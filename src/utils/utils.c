/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:20:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 02:17:12 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// int	heightLine(t_cub *cub, float x, float y)
// {
// 	int	i;

// 	while ()
// }

int	isInsideMap(float x, float y, t_cub *cub)
{
	//while (nextVertTouchX >= 0 && nextVertTouchX <= getLenght(cub, nextVertTouchY) * TILE
	// 	&& nextVertTouchY >= 0 && nextVertTouchY <= cub->map_info.height * TILE)
	if (x >= 0 && x <= getLenght(cub, y) * TILE && y >= 0 && y <= cub->map_info.height * TILE)
		return (TRUE);
	else
		return (FALSE);
}

int	mapHasWallAt(t_cub *cub, float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;
	if (x < 0 || x >= getLenght(cub, y) * TILE || y < 0 || y >= cub->map_info.height * TILE)
		return (FALSE);
	mapGridIndexX = floor(x / TILE);
	mapGridIndexY = floor(y / TILE);
	return (cub->map[mapGridIndexY][mapGridIndexX] != '0');
}

/* Free the allocated memory of the map and close the window */
int	close_win(t_cub *cub)
{
	(void)cub;
	//free_map(game->map.map, &game->map);
	exit(0);
}

int	getLenght(t_cub *cub, float	line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE) > cub->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub->map[(int)floor(line / TILE)]));
}

void	findPlayerPosition(t_cub *cub)
{
	int	x;
	size_t	y;

	x = 0;
	while (x < cub->map_info.height)
	{
		y = 0;
		while (y < ft_strlen(cub->map[x]))
		{
			if (cub->map[x][y] == 'N')
			{
				cub->player.x = y * TILE;
				cub->player.y = x * TILE;
				cub->map[x][y] = '0';
				break ;
			}
			y++;
		}
		if (cub->player.x != 0)
			break ;
		x++;
	}
}

void	setup(t_cub *cub)
{
	ft_bzero(&cub->player, sizeof(t_player));
	cub->map_info.height = ft_strlen_split(cub->map);
	findPlayerPosition(cub);
	cub->player.width = 5;
	cub->player.height = 5;
	cub->player.turnDirection = 0;
	cub->player.walkDirection = 0;
	cub->player.rotationAngle = PI / 2;
	cub->player.walkSpeed = 30;
	cub->player.turnSpeed = 5 * (PI / 180);

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
