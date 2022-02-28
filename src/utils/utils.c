/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:20:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/28 18:21:15 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	mapHasWallAt(float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;
	printf("X = %f Y = %f\n", x, y);
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (FALSE);
	mapGridIndexX = floor(x / TILE);
	mapGridIndexY = floor(y / TILE);
	printf("Xx = %d Yy = %d\n", mapGridIndexX, mapGridIndexY);
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
	cub->player.walkSpeed = 5;
	cub->player.turnSpeed = 45 * (PI / 180);
}
