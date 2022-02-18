/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:23 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/18 02:00:35 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}

void	draw_line(t_data *img, int beginX, int beginY, int len, int color, int sig)
{
	if (sig == 1)
		while (beginY <= len)
			ft_mlx_pixel_put(img, beginX, beginY++, color);
	else
		while (beginX <= len)
			ft_mlx_pixel_put(img, beginX++, beginY, color);
}

void	start_game(t_cub *cub)
{
	t_data img;


	cub->s_mlx.mlx = mlx_init();
	cub->s_mlx.win = mlx_new_window(cub->s_mlx.mlx, 600, 600, "cub3D");
	int xn;
	int yn;
	img.img = mlx_xpm_file_to_image(cub->s_mlx.mlx, "./maps/textures/wall.xpm", &xn, &yn);
	// img.img = mlx_new_image(cub->s_mlx.mlx, 64, 64);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	unsigned int color;

	double x = 50;
	double y = 50;
	double p = 100;
	while (x < 100)
	{
		while (y < p)
		{
			mlx_pixel_put(cub->s_mlx.mlx, cub->s_mlx.win, x, y, 0x00FF0000);
			y++;
		}
		p -= 0.1;
		y = 50 + (0.1 * x);
		x++;
	}
	int xw = 0;
	int yw = 0;
	x = 0.1;
	y = 0.1;
	p = 40;
	// int pi = p;
	// y column
	// x linha
	while (x < 40)
	{
		while (y < p)
		{
			color = get_color(&img, x, y);
			mlx_pixel_put(cub->s_mlx.mlx, cub->s_mlx.win, xw, yw, color);
			y += 0.1;
			yw++;
		}
		y = 0;
		yw = 0 + (0.1 * xw);
		x += 0.1;
		xw++;;
	}
	// int x = 0;
	// int y =0;
	// while (i++ < 63)
	// {
	// 	x++;
	// 	y++;
	// 	draw_line(&img, x, y, 63, 0x00FF0000, 1);
	// 	draw_line(&img, x, y, 63, 0x00FF0000, 2);

	// }
	// i =0;
	// x = 30;
	// y = 30;
	// while (i++ < 35)
	// {
	// 	x++;
	// 	y++;

	// 		draw_line(&img, x, y, 45, 0x0000FF, 1);
	// 		draw_line(&img, x, y, 45, 0x0000FF, 2);

	// }

	//mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, img.img, 0, 0);
	mlx_loop(cub->s_mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (is_invalid_arg(argc, argv) == FALSE)
		return (3);
	if (check_map(argv[1], &cub) == FALSE)
		return (4);
	start_game(&cub);
	free_struct(&cub);
	return (0);
}
