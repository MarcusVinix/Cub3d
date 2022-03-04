/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:59:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/04 15:26:24 by mavinici         ###   ########.fr       */
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
		utils.perpDistance = cub->rays[x].distance *
			cos(cub->rays[x].rayAngle - cub->player.rotationAngle);
		utils.projectedWallHeight = (TILE / utils.perpDistance) *
			DIST_PROJ_PLANE;
		utils.wallStripHeight = (int)utils.projectedWallHeight;

		utils.wallTopPixel = (HEIGHT / 2) - (utils.wallStripHeight / 2);
		if (utils.wallTopPixel < 0)
			utils.wallTopPixel = 0;
		utils.wallBottomPixel = (HEIGHT / 2) + (utils.wallStripHeight / 2);
		if (utils.wallBottomPixel > HEIGHT)
			utils.wallBottomPixel = HEIGHT;

		y = 0;
		while (y < utils.wallTopPixel)
			ft_mlx_pixel_put(&cub->img, x, y++, 0xFF283747);

		int textureOffSetX;
		if (cub->rays[x].wasHitVertical == TRUE) {
			textureOffSetX = (int)cub->rays[x].wallHitY % TILE;
		}
		else {
			textureOffSetX = (int)cub->rays[x].wallHitX % TILE;
		}
		int texNum = cub->rays[x].wallHitCotent - 1;

		y = utils.wallTopPixel;
		while (y < utils.wallBottomPixel)
		{
			int	distanceFromTop = y + (utils.wallStripHeight / 2) - (HEIGHT / 2);
			int textureOffSetY = distanceFromTop * ((float)TEXTURE_HEIGHT / utils.wallStripHeight);
			uint32_t texelColor = cub->textures[texNum][(TEXTURE_WIDTH * textureOffSetY) + textureOffSetX];
			ft_mlx_pixel_put(&cub->img, x, y, texelColor);
			y++;
		}
		y = utils.wallBottomPixel;
		while (y < HEIGHT)
			ft_mlx_pixel_put(&cub->img, x, y++, 0xFF616A6B);
		x++;
	}
}
