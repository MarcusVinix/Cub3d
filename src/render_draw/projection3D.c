/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:59:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/04 01:30:21 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	generate3DProjection(t_cub *cub)
{
	t_projection	utils;
	int				i;
	int				j;
	int				c;
	int				f;

	ft_bzero(&utils, sizeof(t_projection));
	i = 0;
	while (i < NUM_RAYS)
	{
		utils.perpDistance = cub->rays[i].distance *
			cos(cub->rays[i].rayAngle - cub->player.rotationAngle);
		utils.distanceProjPlane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		utils.projectedWallHeight = (TILE / utils.perpDistance) *
			utils.distanceProjPlane;
		utils.wallStripHeight = (int)utils.projectedWallHeight;

		utils.wallTopPixel = (HEIGHT / 2) - (utils.wallStripHeight / 2);
		if (utils.wallTopPixel < 0)
			utils.wallTopPixel = 0;
		utils.wallBottomPixel = (HEIGHT / 2) + (utils.wallStripHeight / 2);
		if (utils.wallBottomPixel > HEIGHT)
			utils.wallBottomPixel = HEIGHT;

		c = 0;
		while (c < utils.wallTopPixel)
			ft_mlx_pixel_put(&cub->img, i, c++, 0xFF283747);

		int textureOffSetX;
		if (cub->rays[i].wasHitVertical == TRUE) {
			textureOffSetX = (int)cub->rays[i].wallHitY % TILE;
		}
		else {
			textureOffSetX = (int)cub->rays[i].wallHitX % TILE;
		}
		int texNum = cub->rays[i].wallHitCotent - 1;

		j = utils.wallTopPixel;
		while (j < utils.wallBottomPixel)
		{
			int	distanceFromTop = j + (utils.wallStripHeight / 2) - (HEIGHT / 2);
			int textureOffSetY = distanceFromTop * ((float)TEXTURE_HEIGHT / utils.wallStripHeight);
			uint32_t texelColor = cub->textures[texNum][(TEXTURE_WIDTH * textureOffSetY) + textureOffSetX];
			ft_mlx_pixel_put(&cub->img, i, j, texelColor);
			j++;
		}
		f = utils.wallBottomPixel;
		while (f < HEIGHT)
			ft_mlx_pixel_put(&cub->img, i, f++, 0xFF616A6B);
		i++;
	}
}
