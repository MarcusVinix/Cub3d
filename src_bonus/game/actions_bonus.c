/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:19:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/24 20:35:11 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	move_player(t_cub *cub)
{
	float	move_step;
	float	side_step;
	float	newx;
	float	newy;

	cub->player.rotation_angle += cub->player.turn_direction
		* cub->player.turn_speed;
	normalize_angle(&cub->player.rotation_angle);
	side_step = cub->player.side_direction * cub->player.walk_speed;
	move_step = cub->player.walk_direction * cub->player.walk_speed;
	newx = cub->player.x + cos(cub->player.rotation_angle) * move_step;
	newy = cub->player.y + sin(cub->player.rotation_angle) * move_step;
	newx = newx - sin(-cub->player.rotation_angle) * side_step;
	newy = newy - cos(-cub->player.rotation_angle) * side_step;
	if (map_has_wall_at(cub, newx, newy) == FALSE)
	{
		cub->player.x = newx;
		cub->player.y = newy;
	}
}

void	update(t_cub *cub)
{
	move_player(cub);
	cast_all_rays(cub);
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
		cub->player.side_direction = -1;
	if (keycode == ARROW_RIGHT)
		cub->player.turn_direction = +1;
	if (keycode == LEFT)
		cub->player.side_direction = +1;
	if (keycode == ARROW_LEFT)
		cub->player.turn_direction = -1;
	if (keycode == TOP)
		cub->player.walk_direction = +1;
	if (keycode == DOWN)
		cub->player.walk_direction = -1;
	return (TRUE);
}
