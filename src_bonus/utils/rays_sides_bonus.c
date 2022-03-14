/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_sides_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:59:42 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/14 21:16:04 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	is_ray_facing_down(float angle)
{
	if (angle > 0 && angle < PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_racing_up(float angle)
{
	if (is_ray_facing_down(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}

int	is_ray_facing_right(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_facing_left(float angle)
{
	if (is_ray_facing_right(angle) == TRUE)
		return (FALSE);
	else
		return (TRUE);
}
