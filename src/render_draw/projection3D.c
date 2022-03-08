/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:59:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 23:02:46 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	generate3DProjection(t_cub *cub)
{
	t_projection	utils;
	int				x;
	int				y;

	ft_bzero(&utils, sizeof(t_projection));
	x = 0;
	while (x < NUM_RAYS)
	{
		utils.perp_dist = cub->rays[x].distance *
			cos(cub->rays[x].ray_angle - cub->player.rotation_angle);
		utils.proj_wall_height = (TILE / utils.perp_dist) *
			DIST_PROJ_PLANE;
		utils.wall_strip_height = (int)utils.proj_wall_height;
		utils.wall_top_pixel = (HEIGHT / 2) - (utils.wall_strip_height / 2);
		if (utils.wall_top_pixel < 0)
			utils.wall_top_pixel = 0;
		utils.wall_bottom_pixel = (HEIGHT / 2) + (utils.wall_strip_height / 2);
		if (utils.wall_bottom_pixel > HEIGHT)
			utils.wall_bottom_pixel = HEIGHT;
		y = 0;
		while (y < utils.wall_top_pixel)
			ft_mlx_pixel_put(&cub->img, x, y++, 0xFF283747);
		int texture_offset_x;
		if (cub->rays[x].was_hit_vertical == TRUE) {
			texture_offset_x = (int)cub->rays[x].wall_hit_y % TILE;
		}
		else {
			texture_offset_x = (int)cub->rays[x].wall_hit_x % TILE;
		}
		check_inverse_offset_x(cub->rays[x], &texture_offset_x);
		int texNum = cub->rays[x].wall_hit_cotent;
		y = utils.wall_top_pixel;
		while (y < utils.wall_bottom_pixel)
		{
			int	distanceFromTop = y + (utils.wall_strip_height / 2) - (HEIGHT / 2);
			int textureOffSetY = distanceFromTop * ((float)TEXTURE_HEIGHT / utils.wall_strip_height);
			uint32_t texelColor = cub->textures[texNum][(TEXTURE_WIDTH * textureOffSetY) + texture_offset_x];
			if (cub->rays[x].was_hit_vertical == TRUE)
				changeColorIntesity(&texelColor, 0.7);
			ft_mlx_pixel_put(&cub->img, x, y, texelColor);
			y++;
		}
		y = utils.wall_bottom_pixel;
		while (y < HEIGHT)
			ft_mlx_pixel_put(&cub->img, x, y++, 0xFF616A6B);
		x++;
	}
}
