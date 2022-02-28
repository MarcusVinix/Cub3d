/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:18:19 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/28 18:18:24 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	drawLine(t_data *img, t_line line)
{
	int	i;
	// diferença entre o inicio e fim da linha
	line.deltaX = (line.x2 - line.x1);
	line.deltaY = (line.y2 - line.y1);
	
	// o lado mais longo da linha;
	if (abs(line.deltaX) >= abs(line.deltaY))
		line.longestSideLength = abs(line.deltaX);
	else
		line.longestSideLength = abs(line.deltaY);
	
	// tamanhos de incremento x e y
	line.xIncrement = line.deltaX / (float)line.longestSideLength;
	line.yIncrement = line.deltaY / (float)line.longestSideLength;

	// start point
	line.currentX = line.x1;
	line.currentY = line.y1;

	// iteração de zero até o lado mais lonngo da linha
	i = 0;
	while (i < line.longestSideLength)
	{
		//desenha um pixel, arrenndodamennto para inteiro para pegar o pixel mais proximo
		ft_mlx_pixel_put(img, round(line.currentX), round(line.currentY), line.color);

		// incremennt the slop to get tthe next pixel
		line.currentX += line.xIncrement;
		line.currentY += line.yIncrement;
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
		while (j < (rect.y + rect.height))
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
