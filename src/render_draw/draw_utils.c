/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:19 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 23:08:19 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	drawLine(t_data *img, t_line line)
{
	int	i;

	line.delta_x = (line.x2 - line.x1);
	line.delta_y = (line.y2 - line.y1);
	if (abs(line.delta_x) >= abs(line.delta_y))
		line.long_side_len = abs(line.delta_x);
	else
		line.long_side_len = abs(line.delta_y);
	line.x_increment = line.delta_x / (float)line.long_side_len;
	line.y_increment = line.delta_y / (float)line.long_side_len;
	line.current_x = line.x1;
	line.current_y = line.y1;
	i = 0;
	while (i < line.long_side_len)
	{
		ft_mlx_pixel_put(img, round(line.current_x),
			round(line.current_y), line.color);
		line.current_x += line.x_increment;
		line.current_y += line.y_increment;
		i++;
	}
}

void	drawRect(t_data *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.x;
	while (i <= (rect.x + rect.width))
	{
		j = rect.y;
		while (j <= (rect.y + rect.height))
		{
			ft_mlx_pixel_put(img, i, j, rect.color);
			j++;
		}
		i++;
	}
}

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

/**
 * @brief Change the color intensity based on a factor value between 0 and 1
 * 
 * @param color 
 * @param factor 
 */
void	changeColorIntesity(uint32_t *color, float factor)
{
	uint32_t a = (*color & 0xFF000000);
	uint32_t r = (*color & 0x00FF0000) * factor;
	uint32_t g = (*color & 0x0000FF00) * factor;
	uint32_t b = (*color & 0x000000FF) * factor;
	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}
