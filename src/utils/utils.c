/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:20:46 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/10 14:19:15 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_inverse_offset_x(t_ray ray, int *texture_offset_x)
{
	if (ray.was_hit_vertical == FALSE&& is_ray_facing_down(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
	if (ray.was_hit_vertical == TRUE&& is_ray_facing_left(ray.ray_angle) == TRUE)
		*texture_offset_x = TILE - *texture_offset_x;
}

int	isInsideMap(float x, float y, t_cub *cub)
{
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
	free_struct(cub);
	exit(0);
}

int	getLenght(t_cub *cub, float	line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE) > cub->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub->map[(int)floor(line / TILE)]));
}

void	save_orientation(t_cub *cub, char c)
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

uint32_t	*getTextureBuffer(t_data *img)
{
	int				x;
	int				y;
	uint32_t	*buffer;

	buffer = ft_calloc(TEXTURE_WIDTH * TEXTURE_HEIGHT, sizeof(uint32_t *));
	x = -1;
	while (++x < TEXTURE_HEIGHT)
	{
		y = -1;
		while (++y < TEXTURE_WIDTH)
		{
			buffer[(TEXTURE_WIDTH * y) + x] = (uint32_t)get_color(img, x, y);
		}
	}
	return (buffer);
}

void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
			&img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_len, &img->endian);
}

void	save_initial_angle(t_cub *cub)
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

void	start_player(t_cub *cub)
{
	ft_bzero(&cub->player, sizeof(t_player));
	cub->map_info.height = ft_strlen_split(cub->map);
	findPlayerPosition(cub);
	cub->player.width = 5;
	cub->player.height = 5;
	cub->player.turn_direction = 0;
	cub->player.walk_direction = 0;
	save_initial_angle(cub);
	cub->player.walk_speed = 30;
	cub->player.turn_speed = 5 * (PI / 180);
}

void	start_textures(t_cub *cub)
{
	sprites(&cub->sprites.no, cub->s_mlx.mlx, cub->texture_path[0][1]);
	sprites(&cub->sprites.so, cub->s_mlx.mlx, cub->texture_path[1][1]);
	sprites(&cub->sprites.we, cub->s_mlx.mlx, cub->texture_path[2][1]);
	sprites(&cub->sprites.ea, cub->s_mlx.mlx, cub->texture_path[3][1]);
	cub->textures[0] = getTextureBuffer(&cub->sprites.no);
	cub->textures[1] = getTextureBuffer(&cub->sprites.so);
	cub->textures[2] = getTextureBuffer(&cub->sprites.we);
	cub->textures[3] = getTextureBuffer(&cub->sprites.ea);
}

void	setup(t_cub *cub)
{
	start_player(cub);
	start_textures(cub);
	// int i = 0;
	// while (cub->map[i])
	// 	printf("%s\n", cub->map[i++]);
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
