/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 01:41:31 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_background(t_data *img, int color_up, int color_down)
{
	t_rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.height = HEIGHT / 2;
	rect.width = WIDTH;
	rect.color = color_up;
	drawRect(img, rect);
	rect.y = HEIGHT / 2;
	rect.color = color_down; 
	drawRect(img, rect);
}

void	render_map(t_cub *cub)
{
	int	i;
	size_t	j;
	t_rect rect;

	i = 0;
	while (i < cub->map_info.height)
	{
		j = 0;
		while (j < ft_strlen(cub->map[i]))
		{
			if (cub->map[i][j] != ' ')
			{
				rect.x = j * TILE * MINIMAP_SCALE_FACTOR;
				rect.y = i * TILE * MINIMAP_SCALE_FACTOR;
				rect.width = TILE * MINIMAP_SCALE_FACTOR;
				rect.height = TILE * MINIMAP_SCALE_FACTOR;
				rect.color = cub->map[i][j] != '0' ? BLACK : WHITE;
				drawRect(&cub->img, rect);
			}
			j++;
		}
		i++;
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
	drawRect(img, rect);
}

void	draw_gaming(t_cub *cub)
{
	// mlx_clear_window(cub->s_mlx.mlx, cub->s_mlx.win);
	// draw_background(&cub->img, 0xFF283747, 0xFF616A6B);
	generate3DProjection(cub);
	render_map(cub);
	renderRays(cub);
	render_player(&cub->img, cub->player);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
}