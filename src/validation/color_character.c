/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:59:24 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/10 21:52:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if the colors of ceilling and floor its on
 * the right format.
 *
 * @param content_map The content of the map.
 * @return On sucess the colors of ceilling and floor inside a double pointer.
 * NULL if something its wrong.
 */
char	***valid_ceilling_and_floor_color(char **content_map)
{
	char	***collors;
	char	**key_val;
	int		i;
	int		index_let;

	i = -1;
	index_let = 0;
	collors = ft_calloc(3, sizeof(char *));
	while (++i < 6)
	{
		key_val = ft_split(content_map[i], ' ');
		if (ft_strcmp(key_val[0], "F") == 0 || ft_strcmp(key_val[0], "C") == 0)
			collors[index_let++] = ft_split(content_map[i], ' ');
		ft_free_split(key_val);
	}
	if (ft_strcmp(collors[0][0], collors[1][0]) == 0)
	{
		ft_free_triple(collors);
		ft_free_split(content_map);
		return (NULL);
	}
	return (collors);
}

/**
 * @brief Check if have only the allowed characters on the map.
 *
 * @param map The map.
 * @return On sucess TRUE. False if something its wrong.
 */
int	valid_characters(char **map)
{
	int		i;
	int		j;
	int		side;

	j = -1;
	i = -1;
	side = FALSE;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == ' ')
				continue ;
			else if ((map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == 'E') && side == FALSE)
			{
				if (side == FALSE)
					side = TRUE;
				else
					return (error_msg(ERROR_MORE_THEN_ONE_SIDE, 2, NULL));
			}
			else
				return (error_msg(ERROR_CARACTER_INVALID, 2, NULL));
		}
		j = -1;
	}
	if (side == FALSE)
		return (FALSE);
	return (TRUE);
}
