/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:09:47 by coder             #+#    #+#             */
/*   Updated: 2022/03/10 21:51:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_struct(t_cub *cub)
{
	//int	i;
	if (cub->texture_path != NULL)
		ft_free_triple(cub->texture_path);
	if (cub->colors != NULL)
		ft_free_triple(cub->colors);
	if (cub->map != NULL)
		ft_free_split(cub->map);
	//i = 0;
	//while (i < NUM_TEXTURES)
	//	free(cub->textures[i++]);
	//mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.no.img);
	//mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.so.img);
	//mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.we.img);
	//mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.ea.img);
	//mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	//mlx_destroy_window(cub->s_mlx.mlx, cub->s_mlx.win);
}
