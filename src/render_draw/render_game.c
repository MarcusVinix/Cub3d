/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/12 16:59:02 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render_map(t_cub *cub)
{
	int		x;
	int		y;
	t_rect	rect;

	x = -1;
	rect.width = TILE * MINIMAP_SCALE_FACTOR;
	rect.height = TILE * MINIMAP_SCALE_FACTOR;
	while (++x < cub->map_info.height)
	{
		y = -1;
		rect.y = x * TILE * MINIMAP_SCALE_FACTOR;
		while (++y < (int)ft_strlen(cub->map[x]))
		{
			if (cub->map[x][y] != ' ')
			{
				rect.x = y * TILE * MINIMAP_SCALE_FACTOR;
				if (cub->map[x][y] == '1')
					rect.color = BLACK;
				else
					rect.color = WHITE;
				draw_rect(&cub->img, rect);
			}
		}
	}
}

void	render_player(t_data *img, t_player player)
{
	t_rect			rect;

	rect.x = player.x * MINIMAP_SCALE_FACTOR;
	rect.y = player.y * MINIMAP_SCALE_FACTOR;
	rect.width = player.width * MINIMAP_SCALE_FACTOR;
	rect.height = player.height * MINIMAP_SCALE_FACTOR;
	rect.color = BLUEMLX;
	draw_rect(img, rect);
}

void	draw_gaming(t_cub *cub)
{
	generate3d_projection(cub);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	build_main_img(cub);
}
