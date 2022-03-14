/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:58:12 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/14 21:15:51 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

/**
 * @brief Check if the current position of the map is space. 
 * Looking up, down, left, right.
 * 
 * @param map The map.
 * @param line Current line.
 * @param col Current column
 * @return On sucess TRUE. FAlSE if fail.
 */
static int	check_around(char **map, int line, int col)
{
	int	len_up;
	int	len_down;

	len_up = ft_strlen(map[line - 1]);
	len_down = ft_strlen(map[line + 1]);
	if (map[line][col - 1])
		if (col < len_up && map[line - 1][col] == ' ')
			return (TRUE);
	if (map[line][col + 1])
		if (map[line][col + 1] == ' ')
			return (TRUE);
	if (col < len_up)
		if (map[line - 1][col] == ' ')
			return (TRUE);
	if (col < len_down)
		if (map[line + 1][col] == ' ')
			return (TRUE);
	if (col > len_up - 1 || col > len_down - 1)
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Check if the wall inside the map is valid.
 * 
 * @param map the map.
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	valid_wall_inside_map(char **map)
{
	int		line;
	size_t	col;

	line = 0;
	col = 0;
	while (++line < ft_strlen_split(map) - 1)
	{
		while (++col < ft_strlen(map[line]) - 1)
		{
			if (check_around(map, line, col) == TRUE)
			{
				if (map[line][col] != '1' && map[line][col] != ' ')
					return (error_msg(ERROR_WALL_INSIDE_MAP, 2, NULL));
			}
		}
		col = 0;
	}
	return (TRUE);
}

/**
 * @brief Check if the top and the bottom is fulled of number 1.
 *
 * @param map The map.
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	valid_top_bottom(char **map)
{
	int		i;
	int		len;

	len = ft_strlen_split(map) - 1;
	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] == '1' || map[0][i] == ' ' || map[0][i] == '\t')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2, NULL));
	}
	i = -1;
	while (map[len][++i])
	{
		if (map[len][i] == '1' || map[len][i] == ' ' || map[len][i] == '\t')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2, NULL));
	}
	return (TRUE);
}

/**
 * @brief Check if the wall map of left and right is fulled of number 1.
 * 
 * @param map The map.
 * @return On sucess TRUE. False if something its wrong.
 */
int	valid_left_right(char **map)
{
	int		i;
	int		len;

	len = ft_strlen(map[0]) - 1;
	i = -1;
	while (map[++i] && map[i][0])
	{
		if (map[i][0] == '1' || map[i][0] == ' ')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2, NULL));
	}
	i = -1;
	while (map[++i] && map[i][len])
	{
		if (!(map[i][len] == '1' || map[i][len] == ' '))
			return (error_msg(ERROR_INVALID_EDGE, 2, NULL));
		if (map[i + 1])
			len = ft_strlen(map[i + 1]) - 1;
	}
	return (TRUE);
}

/**
 * @brief Check if the edge of the map is valid.
 * 
 * @param map The map.
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	valid_edge(char **map)
{
	if (valid_top_bottom(map) == FALSE)
		return (FALSE);
	if (valid_left_right(map) == FALSE)
		return (FALSE);
	if (valid_wall_inside_map(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
