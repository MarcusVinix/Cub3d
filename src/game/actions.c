/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/01 00:28:49 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	movePlayer(t_cub *cub)
{
	float	moveStep;
	float	newX;
	float	newY;

	cub->player.rotationAngle += cub->player.turnDirection * cub->player.turnSpeed;
	moveStep = cub->player.walkDirection * cub->player.walkSpeed;
	newX = cub->player.x + cos(cub->player.rotationAngle) * moveStep;
	newY = cub->player.y + sin(cub->player.rotationAngle) * moveStep;

	if (!mapHasWallAt(newX, newY))
	{
		cub->player.x = newX;
		cub->player.y = newY;
	}

	cub->player.turnDirection = 0;
	cub->player.walkDirection = 0;
}

void	update(t_cub *cub)
{
	movePlayer(cub);
	castAllRays(cub);
}

int	action_loop(t_cub *cub)
{
	update(cub);
	draw_gaming(cub);
	return (1);
}

int	action(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		close_win(cub);
	if (keycode == RIGHT)
		cub->player.turnDirection = +1;
	if (keycode == LEFT)
		cub->player.turnDirection = -1;
	if (keycode == TOP)
		cub->player.walkDirection = +1;
	if (keycode == DOWN)
		cub->player.walkDirection = -1;
	return (TRUE);
}
