/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:00:21 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/28 13:07:36 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// void	sprites(t_data *img, void *mlx, char *path)
// {
// 	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
// 			&img->pos.y);
// 	img->addr = mlx_get_data_addr(img->img, &img->bpp,
// 			&img->l_len, &img->endian);
// }

// void	init_sprite(t_cub *cub)
// {
// 	cub->img.img = mlx_new_image(cub->s_mlx.mlx, WIDTH, HEIGHT);
// 	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp, &cub->img.l_len, &cub->img.endian);
// 	sprites(&cub->sprites.ea, cub->s_mlx.mlx, cub->texture_path[0][1]);
// 	sprites(&cub->sprites.player, cub->s_mlx.mlx, cub->texture_path[1][1]);
// }

// void	print_sprite(t_cub *cub, int line, int col)
// {
// 	t_pos	pos;

// 	pos.x = (col * (TILE));
// 	pos.y = (line * (TILE)) ;
// 	if (cub->map[line][col] == '1')
// 		draw_img(cub, &cub->sprites.ea, pos);
// 	if (cub->map[line][col] == 'N')
// 	{
// 		// cub->player.x = line;//4 160
// 		// cub->player.y = col;//26 1040
// 		// // draw_img(cub, &cub->sprites.player, pos);

// 	}
// }