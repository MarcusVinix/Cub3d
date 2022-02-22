/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:18:50 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/22 01:10:04 by mavinici         ###   ########.fr       */
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

	i = 0;
	if (sig == 1)
		while (i++ <= pos.len)
			ft_mlx_pixel_put(img, pos.x + pos.pdx * 5 , pos.y++ + pos.pdy * 5, color);
	else
		while (i++ <= pos.len)
			ft_mlx_pixel_put(img, pos.x++ + pos.pdx * 5, pos.y + pos.pdy * 5, color);
}
