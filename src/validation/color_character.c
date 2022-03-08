/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:59:24 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 01:33:56 by mavinici         ###   ########.fr       */
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
char	**valid_ceilling_and_floor_color(char **content_map)
{
	char	**collors;
	char	**key_val;
	char	*letters[2];
	int		i;

	i = 3;
	letters[0] = "F";
	letters[1] = "C";
	collors = ft_calloc(3, sizeof(char *));
	while (++i <= 5)
	{
		key_val = ft_split(content_map[i], ' ');
		if (ft_strcmp(key_val[0], letters[i - 4]) != 0)
		{
			ft_free_split(key_val);
			ft_free_split(content_map);
			return (NULL);
		}
		collors[i - 4] = ft_strdup(key_val[1]);
		ft_free_split(key_val);
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
