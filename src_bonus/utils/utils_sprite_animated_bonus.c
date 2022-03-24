/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite_animated_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:21:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/24 18:53:56 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

uint32_t	*get_animeted_guard(t_cub *cub)
{
	if (cub->time < 50 && cub->sprites.sprite3[0].time != 1)
		return (cub->sprites.sprite3[0].buffer);
	else if ((cub->time > 50 || cub->sprites.sprite3[0].time == 1)
		&& cub->time < 75)
	{
		cub->sprites.sprite3[0].time = 1;
		return (cub->sprites.sprite3[1].buffer);
	}
	else
		return (cub->sprites.sprite3[2].buffer);
}

uint32_t	*get_animeted_fire(t_cub *cub)
{
	int	time;

	time = cub->sprites.sprite5[0].time;
	if (time < 25)
		return (cub->sprites.sprite5[0].buffer);
	else if (time > 25 && time < 50)
		return (cub->sprites.sprite5[1].buffer);
	else if (time > 50 && time < 100)
		return (cub->sprites.sprite5[2].buffer);
	else
		return (cub->sprites.sprite5[3].buffer);
}

void	change_time_sprite(t_cub *cub)
{
	if (cub->time_check == 0)
	{
		if (cub->sprites.sprite5[0].time >= 125)
			cub->time_check = 1;
		else
			cub->sprites.sprite5[0].time += 3;
	}
	else if (cub->time_check == 1)
	{
		if (cub->sprites.sprite5[0].time == 0)
			cub->time_check = 0;
		else
			cub->sprites.sprite5[0].time -= 3;
	}
}

void	start_guard(t_cub *cub)
{
	cub->sprites.sprite3 = ft_calloc(4, sizeof(t_data));
	sprites(&cub->sprites.sprite3[0], cub->s_mlx.mlx,
		"assets/sprites/animated/guard1.xpm");
	sprites(&cub->sprites.sprite3[1], cub->s_mlx.mlx,
		"assets/sprites/animated/guard2.xpm");
	sprites(&cub->sprites.sprite3[2], cub->s_mlx.mlx,
		"assets/sprites/animated/guard3.xpm");
	cub->sprites.sprite3[0].buffer = get_texture_buffer(
			&cub->sprites.sprite3[0]);
	cub->sprites.sprite3[1].buffer = get_texture_buffer(
			&cub->sprites.sprite3[1]);
	cub->sprites.sprite3[2].buffer = get_texture_buffer(
			&cub->sprites.sprite3[2]);
}

void	start_ghost(t_cub *cub)
{
	cub->sprites.sprite5 = ft_calloc(5, sizeof(t_data));
	sprites(&cub->sprites.sprite5[0], cub->s_mlx.mlx,
		"assets/sprites/animated/ghost1.xpm");
	sprites(&cub->sprites.sprite5[1], cub->s_mlx.mlx,
		"assets/sprites/animated/ghost2.xpm");
	sprites(&cub->sprites.sprite5[2], cub->s_mlx.mlx,
		"assets/sprites/animated/ghost3.xpm");
	sprites(&cub->sprites.sprite5[3], cub->s_mlx.mlx,
		"assets/sprites/animated/ghost4.xpm");
	cub->sprites.sprite5[0].buffer = get_texture_buffer(
			&cub->sprites.sprite5[0]);
	cub->sprites.sprite5[1].buffer = get_texture_buffer(
			&cub->sprites.sprite5[1]);
	cub->sprites.sprite5[2].buffer = get_texture_buffer(
			&cub->sprites.sprite5[2]);
	cub->sprites.sprite5[3].buffer = get_texture_buffer(
			&cub->sprites.sprite5[3]);
}
