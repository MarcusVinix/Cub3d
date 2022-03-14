/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:00:20 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/14 21:16:03 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static uint32_t	*get_texture_buffer(t_data *img)
{
	int			x;
	int			y;
	uint32_t	*buffer;

	buffer = ft_calloc(TEXTURE_WIDTH * TEXTURE_HEIGHT, sizeof(uint32_t *));
	x = -1;
	while (++x < TEXTURE_HEIGHT)
	{
		y = -1;
		while (++y < TEXTURE_WIDTH)
		{
			buffer[(TEXTURE_WIDTH * y) + x] = (uint32_t)get_color(img, x, y);
		}
	}
	return (buffer);
}

void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
			&img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_len, &img->endian);
}

void	build_main_img(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->s_mlx.mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
			&cub->img.l_len, &cub->img.endian);
}

void	start_textures(t_cub *cub)
{
	sprites(&cub->sprites.no, cub->s_mlx.mlx, cub->texture_path[0][1]);
	sprites(&cub->sprites.so, cub->s_mlx.mlx, cub->texture_path[1][1]);
	sprites(&cub->sprites.we, cub->s_mlx.mlx, cub->texture_path[2][1]);
	sprites(&cub->sprites.ea, cub->s_mlx.mlx, cub->texture_path[3][1]);
	cub->textures[0] = get_texture_buffer(&cub->sprites.no);
	cub->textures[1] = get_texture_buffer(&cub->sprites.so);
	cub->textures[2] = get_texture_buffer(&cub->sprites.we);
	cub->textures[3] = get_texture_buffer(&cub->sprites.ea);
}

int	get_color_mlx(t_rgb color)
{
	return (color.red << 16 | color.green << 8 | color.blue);
}
