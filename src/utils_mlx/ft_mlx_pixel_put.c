/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:18:50 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/23 00:42:56 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_mlx_pixel_put(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y *img_data->l_len + x * (img_data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}

void	draw_line(t_data *img, t_pos pos, int color, int sig)
{
	int	i;
	double x;
	double y;

	i = 0;
	x = pos.pdx;
	y = pos.pdy;
	if (sig == 1)
	{
		printf(" playerx = %f, playery = %f counnt x = |%f| counnt y = |%f|\n", x, y, (pos.x + pos.pdx * 5), (pos.y + pos.pdy * 5));
		while (i++ < 50)
		{
			ft_mlx_pixel_put(img, pos.x + x, pos.y + y, color);
			y *= 1.05;
			x *= 1.05;
		}
	}
	else if (sig == 3)
	{
		while (i++ <= pos.len)
		{
			ft_mlx_pixel_put(img, pos.x, pos.y++, color);
		}
	}
	else
		while (i++ <= pos.len)
			ft_mlx_pixel_put(img, pos.x++ + pos.pdx * 5, pos.y + pos.pdy * 5, color);
}

void	draw_ray(t_data *img, t_pos pos)
{
	// draw_line(img, pos, 0x00FF0000, 3);
	pos.len = 20;
	draw_line(img, pos, 0x00FF0000, 1);
}

// 1
//  1
//   1
//    1
//     1