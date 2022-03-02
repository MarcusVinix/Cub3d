/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:59:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/02 01:11:24 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	generate3DProjection(t_cub *cub)
{
	t_projection	utils;
	int				i;
	int				j;

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
		j = utils.wallTopPixel;
		while (j < utils.wallBottomPixel)
		{
			if (cub->rays[i].wasHitVertical)
				ft_mlx_pixel_put(&cub->img, i, j, 0xFFFFFFF);
			else
				ft_mlx_pixel_put(&cub->img, i, j, 0xFFCCCCCC);
			j++;
		}
		i++;
	}
}
