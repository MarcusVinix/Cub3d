/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:14:49 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/14 20:56:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_gaming(t_cub *cub)
{
	generate3d_projection(cub);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	build_main_img(cub);
}
