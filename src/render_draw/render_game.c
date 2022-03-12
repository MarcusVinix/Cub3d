/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/12 19:11:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	if (px - (BOX_MINIMAP - 1) < 0)
		cub->map_info.p_start_y = 0;
	else
		cub->map_info.p_start_y = px - (BOX_MINIMAP - 1);
	if (px + (BOX_MINIMAP - 1) < cub->map_info.height)
		cub->map_info.p_end_y = px + (BOX_MINIMAP - 1);
	else
		cub->map_info.p_end_y = cub->map_info.height;
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
				drawRect(&cub->img, rect);
			}
			if(rect.x == START_POS_MINIMAP || rect.x == endx - (int)(TILE * MINIMAP_SCALE_FACTOR))
			{
				rect.color = BLACK;
				drawRect(&cub->img, rect);
			}	
			rect.x += TILE * MINIMAP_SCALE_FACTOR;
		}
		rect.y += TILE * MINIMAP_SCALE_FACTOR;
	}
}

void	check_color_in_map(t_cub *cub, int x, int y, t_rect *rect)
{
	if (cub->map[x][y] == '1')
		rect->color = GREY;
	else
		rect->color = GREEN;
	drawRect(&cub->img, *rect);
}

void	render_map(t_cub *cub)
{
	t_rect rect;
	int	max_posx;
	int	posx;

	find_pos_minimap(cub);
	print_edges(cub);
	rect.x = cub->map_info.starty;
	while(rect.x < cub->map_info.endy && cub->map_info.p_start_y < cub->map_info.p_end_y)
	{
		rect.y = cub->map_info.startx;
		posx = cub->map_info.p_start_x;
		max_posx = (int)ft_strlen(cub->map[cub->map_info.p_start_y]);
		while(rect.y < cub->map_info.endx && cub->map_info.p_start_x < max_posx)
		{
			check_color_in_map(cub, cub->map_info.p_start_y, posx, &rect);
			rect.y += TILE * MINIMAP_SCALE_FACTOR;
			posx++;
		}
		cub->map_info.p_start_y++;
		rect.x += TILE * MINIMAP_SCALE_FACTOR;
	}
}
	// rect.width = TILE * MINIMAP_SCALE_FACTOR;
	// rect.height = TILE * MINIMAP_SCALE_FACTOR;
	// while (cub->map_info.startx < cub->map_info.endx)
	// {
	// 	rect.y = cub->map_info.startx * TILE * MINIMAP_SCALE_FACTOR;
	// 	while (cub->map_info.starty < (int)ft_strlen(cub->map[cub->map_info.startx])
	// 			&& cub->map_info.starty < cub->map_info.endy)
	// 	{
	// 		printf("ry: %i\n", rect.y);
	// 		if (cub->map[cub->map_info.startx][cub->map_info.starty] != ' ')
	// 		{
	// 			rect.x = cub->map_info.starty * TILE * MINIMAP_SCALE_FACTOR;
	// 			if (cub->map[cub->map_info.startx][cub->map_info.starty] == '1')
	// 				rect.color = BLACK;
	// 			else
	// 				rect.color = WHITE;
	// 			drawRect(&cub->img, rect);
	// 		}
	// 		cub->map_info.starty++;
	// 	}
	// 	cub->map_info.startx++;
	// }
	//printf("start x y: %i %i, end: %i %i \n",cub->map_info.startx, cub->map_info.starty, cub->map_info.endx, cub->map_info.endy);

// void	render_player(t_data *img, t_player player)
// {
// 	t_rect			rect;

// 	rect.x = player.x * MINIMAP_SCALE_FACTOR;
// 	rect.y = player.y * MINIMAP_SCALE_FACTOR;
// 	rect.width = player.width * MINIMAP_SCALE_FACTOR;
// 	rect.height = player.height * MINIMAP_SCALE_FACTOR;
// 	rect.color = BLUEMLX;
// 	drawRect(img, rect);
// }

void	draw_gaming(t_cub *cub)
{
	generate3DProjection(cub);
	render_map(cub);
	//render_ray(cub);
	//render_player(&cub->img, cub->player);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	build_main_img(cub);
}
