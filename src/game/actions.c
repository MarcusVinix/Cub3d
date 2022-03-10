/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/10 16:59:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	movePlayer(t_cub *cub)
{
	float	moveStep;
	float	newX;
	float	newY;

	cub->player.rotation_angle += cub->player.turn_direction * cub->player.turn_speed;
	moveStep = cub->player.walk_direction * cub->player.walk_speed;
	newX = cub->player.x + cos(cub->player.rotation_angle) * moveStep;
	newY = cub->player.y + sin(cub->player.rotation_angle) * moveStep;

	if (!mapHasWallAt(cub, newX, newY))
	{
		cub->player.x = newX;
		cub->player.y = newY;
	}
	cub->player.turn_direction = 0;
	cub->player.walk_direction = 0;
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
	if (keycode == RIGHT || keycode == ARROW_RIGHT)
		cub->player.turn_direction = +1;
	if (keycode == LEFT || keycode == ARROW_LEFT)
		cub->player.turn_direction = -1;
	if (keycode == TOP)
		cub->player.walk_direction = +1;
	if (keycode == DOWN)
		cub->player.walk_direction = -1;
	return (TRUE);
}
