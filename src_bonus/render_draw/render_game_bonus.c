/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/15 13:30:05 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static void find_pos_minimap(t_cub *cub)
{
	int px; 
	int py;
	int width;

	py = (int)cub->player.y / TILE;
	px = (int)cub->player.x / TILE;
	width = TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.startx = START_POS_MINIMAP + TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.starty = START_POS_MINIMAP + TILE * MINIMAP_SCALE_FACTOR;
	cub->map_info.endx = START_POS_MINIMAP + ((BOX_MINIMAP * 2) - 1) * width;
	cub->map_info.endy = START_POS_MINIMAP + ((BOX_MINIMAP * 2) - 1) * width;
	if (py - (BOX_MINIMAP - 1) < 0)
		cub->map_info.p_start_x = 0;
	else
		cub->map_info.p_start_x = py - (BOX_MINIMAP - 1);
	if (py + (BOX_MINIMAP - 1) < cub->map_info.height)
		cub->map_info.p_end_x = py + (BOX_MINIMAP - 1);
	else
		cub->map_info.p_end_x = cub->map_info.height;
	if (px - (BOX_MINIMAP - 1) < 0)
		cub->map_info.p_start_y = 0;
	else
		cub->map_info.p_start_y = px - (BOX_MINIMAP - 1);
	printf("manox %i manoy %i\n", px, py);
}

static void print_edges(t_cub *cub)
{
	t_rect rect;
	int endx;
	int endy;

	rect.y = START_POS_MINIMAP;
	rect.width = TILE * MINIMAP_SCALE_FACTOR;
	rect.height = TILE * MINIMAP_SCALE_FACTOR;
	endx = START_POS_MINIMAP + (BOX_MINIMAP * 2) * rect.width;
	endy = START_POS_MINIMAP + (BOX_MINIMAP * 2) * rect.height;
	while(rect.y < endy)
	{
		rect.x = START_POS_MINIMAP;
		while(rect.x < endx)
		{
			if(rect.y == START_POS_MINIMAP || rect.y == endy - (int)(TILE * MINIMAP_SCALE_FACTOR))
			{
				rect.color = BLACK;
				draw_rect(&cub->img, rect);
			}
			if(rect.x == START_POS_MINIMAP || rect.x == endx - (int)(TILE * MINIMAP_SCALE_FACTOR))
			{
				rect.color = BLACK;
				draw_rect(&cub->img, rect);
			}	
			rect.x += TILE * MINIMAP_SCALE_FACTOR;
		}
		rect.y += TILE * MINIMAP_SCALE_FACTOR;
	}
}

void	check_color_in_map(t_cub *cub, int x, int y, t_rect *rect)
{
	printf("x: %i, y: %i\n", x, y);
	if (cub->map[x][y] == '1')
		rect->color = GREY;
	else
		rect->color = GREEN;
	draw_rect(&cub->img, *rect);
}

void	render_map(t_cub *cub)
{
	t_rect rect;
	int	max_posx;
	int	posy;

	find_pos_minimap(cub);
	print_edges(cub);
	rect.y = cub->map_info.starty;
	printf("x: %i, y: %i\n",cub->map_info.p_start_y, cub->map_info.p_end_x);
	while(rect.y < cub->map_info.endy && cub->map_info.p_start_x < cub->map_info.p_end_x)
	{
		printf("entrei\n");
		rect.x = cub->map_info.startx;
		posy = cub->map_info.p_start_y;
		max_posx = (int)ft_strlen(cub->map[cub->map_info.p_start_x]);
		while(rect.x < cub->map_info.endx && posy < max_posx)
		{
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
	t_rect rect;
	
	rect.y = START_POS_MINIMAP + (cub->map_info.endy / 2);
	rect.x = START_POS_MINIMAP + (cub->map_info.endx / 2);
	rect.width = TILE * 0.2;
	rect.height = TILE *0.2;
	rect.color = REDMLX;
	draw_rect(&cub->img, rect);
}

void	draw_gaming(t_cub *cub)
{
	generate3d_projection(cub);
	render_sprite_projection(cub);
	render_map(cub);
	//render_ray(cub);
	render_player(cub);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	build_main_img(cub);
}
