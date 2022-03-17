/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_start_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:04:11 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/16 15:52:16 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	save_orientation(t_cub *cub, char c)
{
	if (c == 'N')
		cub->player.orientation = NO;
	else if (c == 'S')
		cub->player.orientation = SO;
	else if (c == 'W')
		cub->player.orientation = WE;
	else if (c == 'E')
		cub->player.orientation = EA;
}

static void	find_player_position(t_cub *cub)
{
	int		x;
	size_t	y;

	x = 0;
	while (x < cub->map_info.height)
	{
		y = 0;
		while (y < ft_strlen(cub->map[x]))
		{
			if (cub->map[x][y] == 'N' || cub->map[x][y] == 'S' ||
				cub->map[x][y] == 'W' || cub->map[x][y] == 'E')
			{
				cub->player.x = y * TILE;
				cub->player.y = x * TILE;
				save_orientation(cub, cub->map[x][y]);
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

static void	save_initial_angle(t_cub *cub)
{
	if (cub->player.orientation == WE)
		cub->player.rotation_angle = TWO_PI / 2;
	else if (cub->player.orientation == EA)
		cub->player.rotation_angle = (TWO_PI * 2) / 2;
	else if (cub->player.orientation == SO)
		cub->player.rotation_angle = PI / 2;
	else if (cub->player.orientation == NO)
		cub->player.rotation_angle = (PI * 3) / 2;
}

static void	start_player(t_cub *cub)
{
	ft_bzero(&cub->player, sizeof(t_player));
	cub->map_info.height = ft_strlen_split(cub->map);
	find_player_position(cub);
	cub->player.width = 5;
	cub->player.height = 5;
	cub->player.turn_direction = 0;
	cub->player.walk_direction = 0;
	save_initial_angle(cub);
	cub->player.walk_speed = 30;
	cub->player.turn_speed = 5 * (PI / 180);
}

void	setup(t_cub *cub)
{
	double	fov;

	fov = 60 * (PI / 180);
	cub->dist_proj_plane = ((WIDTH / 2) / tan(fov / 2));
	start_player(cub);
	start_textures(cub);
	setup_sprites(cub);
	// free_images(cub);
	cub->collors.cell = get_color_mlx(cub->collors.cell_rgb);
	cub->collors.floor = get_color_mlx(cub->collors.floor_rgb);
}
