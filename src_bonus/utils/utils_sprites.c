/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:45:45 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/30 17:22:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	sort_visible_sprites(t_utils_sprite *var)
{
	int			j;
	t_sprite	temp;

	var->i = -1;
	while (++var->i < var->num_visible_sprite - 1)
	{
		j = var->i + 1;
		while (j < var->num_visible_sprite)
		{
			if (var->visible_sprites[var->i].distance
				< var->visible_sprites[j].distance)
			{
				temp = var->visible_sprites[var->i];
				var->visible_sprites[var->i] = var->visible_sprites[j];
				var->visible_sprites[j] = temp;
			}
			j++;
		}
	}
}

void	get_num_sprites(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	cub->num_sprites = 0;
	while (cub->map[++x])
	{
		y = -1;
		while (cub->map[x][++y])
		{
			if (cub->map[x][y] == '2' || cub->map[x][y] == '3'
				|| cub->map[x][y] == '4' || cub->map[x][y] == '5'
				|| cub->map[x][y] == '6')
			{
				cub->num_sprites++;
			}
		}
	}
}

void	get_sprite_x_y(t_cub *cub)
{
	int	x;
	int	y;
	int	num;

	x = -1;
	num = 0;
	while (cub->map[++x] && num < cub->num_sprites)
	{
		y = -1;
		while (cub->map[x][++y] && num < cub->num_sprites)
		{
			if (cub->map[x][y] == '2' || cub->map[x][y] == '3'
				|| cub->map[x][y] == '4' || cub->map[x][y] == '5'
				|| cub->map[x][y] == '6')
			{
				cub->sprites_list[num].x = y * TILE;
				cub->sprites_list[num].y = x * TILE;
				cub->sprites_list[num].content = cub->map[x][y];
				num++;
			}
		}
	}
}

void	start_sprites(t_cub *cub)
{
	sprites(&cub->sprites.sprite2, cub->s_mlx.mlx, SPRITE2);
	start_guard(cub);
	sprites(&cub->sprites.sprite4, cub->s_mlx.mlx, SPRITE4);
	start_ghost(cub);
	sprites(&cub->sprites.sprite6, cub->s_mlx.mlx, SPRITE6);
	cub->sprites.sprite2.buffer = get_texture_buffer(&cub->sprites.sprite2);
	cub->sprites.sprite4.buffer = get_texture_buffer(&cub->sprites.sprite4);
	cub->sprites.sprite6.buffer = get_texture_buffer(&cub->sprites.sprite6);
}

void	setup_sprites(t_cub *cub)
{
	get_num_sprites(cub);
	cub->sprites_list = ft_calloc(cub->num_sprites + 1, sizeof(t_sprite));
	start_sprites(cub);
	get_sprite_x_y(cub);
}
