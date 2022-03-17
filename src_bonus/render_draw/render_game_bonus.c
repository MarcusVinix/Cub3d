/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/17 21:07:26 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void	find_pos_minimap(t_cub *cub)
{
	int	px;
	int	py;
	int	width;

	py = (int)cub->player.y / TILE;
	px = (int)cub->player.x / TILE;
	width = TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.startx = START_POS_MINIMAP + TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.starty = START_POS_MINIMAP + TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.endx = START_POS_MINIMAP + ((BOX_MINIMAP * 2) - 1) * width;
	cub->map_info.endy = START_POS_MINIMAP + ((BOX_MINIMAP * 2) - 1) * width;
	cub->map_info.p_start_x = py - (BOX_MINIMAP - 1);
	if (py + (BOX_MINIMAP - 1) < cub->map_info.height)
		cub->map_info.p_end_x = py + (BOX_MINIMAP - 1);
	else
		cub->map_info.p_end_x = cub->map_info.height;
	cub->map_info.p_start_y = px - (BOX_MINIMAP - 1);
}

static void	print_edges(t_cub *cub)
{
	t_rect	rect;
	int		endx;
	int		endy;

	rect.y = START_POS_MINIMAP;
	rect.width = TILE * MINIMAP_SCALE_FACTOR;
	rect.height = TILE * MINIMAP_SCALE_FACTOR;
	endx = START_POS_MINIMAP + (BOX_MINIMAP * 2) * rect.width;
	endy = START_POS_MINIMAP + (BOX_MINIMAP * 2) * rect.height;
	while (rect.y < endy)
	{
		rect.x = START_POS_MINIMAP;
		while (rect.x < endx)
		{
			if (rect.y == START_POS_MINIMAP || rect.y == endy
				- (int)(TILE * MINIMAP_SCALE_FACTOR))
				rect.color = BLACK;
			else if (rect.x == START_POS_MINIMAP || rect.x == endx
				- (int)(TILE * MINIMAP_SCALE_FACTOR))
				rect.color = BLACK;
			else
				rect.color = WHITE;
			draw_rect(&cub->img, rect);
			rect.x += TILE * MINIMAP_SCALE_FACTOR;
		}
		rect.y += TILE * MINIMAP_SCALE_FACTOR;
	}
}

void	check_color_in_map(t_cub *cub, int x, int y, t_rect *rect)
{
	if (cub->map[x][y] == '1')
		rect->color = GREY;
	else if (cub->map[x][y] == '0')
		rect->color = GREEN;
	else
		rect->color = WHITE;
	draw_rect(&cub->img, *rect);
}

void	render_map(t_cub *cub)
{
	t_rect	rect;
	int		max_posx;
	int		posy;

	find_pos_minimap(cub);
	print_edges(cub);
	rect.y = cub->map_info.starty;
	while (rect.y < cub->map_info.endy && cub->map_info.p_start_x
		< cub->map_info.p_end_x)
	{
		rect.x = cub->map_info.startx;
		posy = cub->map_info.p_start_y;
		if (cub->map_info.p_start_x >= 0)
			max_posx = (int)ft_strlen(cub->map[cub->map_info.p_start_x]);
		while (rect.x < cub->map_info.endx && cub->map_info.p_start_x
			>= 0 && posy < max_posx)
		{
			if (posy >= 0)
				check_color_in_map(cub, cub->map_info.p_start_x, posy, &rect);
			rect.x += TILE * MINIMAP_SCALE_FACTOR;
			posy++;
		}
		cub->map_info.p_start_x++;
		rect.y += TILE * MINIMAP_SCALE_FACTOR;
	}
}

void	render_player(t_cub *cub)
{
	t_rect	rect;

	rect.y = START_POS_MINIMAP + (cub->map_info.endy / 2 + 8);
	rect.x = START_POS_MINIMAP + (cub->map_info.endx / 2 + 8);
	rect.width = TILE * 0.2;
	rect.height = TILE * 0.2;
	rect.color = REDMLX;
	draw_rect(&cub->img, rect);
}

void	draw_gaming(t_cub *cub)
{
	generate3d_projection(cub);
	render_sprite_projection(cub);
	render_map(cub);
	render_player(cub);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	build_main_img(cub);
}
