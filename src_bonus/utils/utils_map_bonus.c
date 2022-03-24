/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:06:57 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/24 20:26:33 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	check_color_in_map(t_cub *cub, int x, int y, t_rect *rect)
{
	if (cub->map[x][y] == '1')
		rect->color = GREY;
	else if (cub->map[x][y] == ' ')
		rect->color = WHITE;
	else
		rect->color = GREEN;
	draw_rect(&cub->img, *rect);
}

int	is_inside_map(float x, float y, t_cub *cub)
{
	if (x >= 0 && x <= get_lenght(cub, y) * TILE && y >= 0
		&& y <= cub->map_info.height * TILE)
		return (TRUE);
	else
		return (FALSE);
}

int	map_has_wall_at(t_cub *cub, float x, float y)
{
	int	map_grid_indexx;
	int	map_grid_indexy;

	if (x < 0 || x >= get_lenght(cub, y) * TILE || y < 0
		|| y >= cub->map_info.height * TILE)
		return (FALSE);
	map_grid_indexx = floor(x / TILE);
	map_grid_indexy = floor(y / TILE);
	if (cub->map[map_grid_indexy][map_grid_indexx] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	get_lenght(t_cub *cub, float line)
{
	if ((int)floor(line / TILE) < 0 || (int)floor(line / TILE)
		> cub->map_info.height)
		return (0);
	else
		return ((int)ft_strlen(cub->map[(int)floor(line / TILE)]));
}
