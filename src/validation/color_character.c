/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:59:24 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/30 16:05:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_rgb	check_rgb_color(char **str)
{
	char	*color;
	char	**color_spl;
	t_rgb	rgb;

	rgb.status = TRUE;
	color = ft_split_rev(str);
	color_spl = ft_split(color + 2, ',');
	free(color);
	if (ft_strlen_split(color_spl) != 3)
	{
		ft_free_split(color_spl);
		rgb.status = FALSE;
		return (rgb);
	}
	if (verify_collor_char(&rgb, color_spl) == 1)
		return (rgb);
	rgb.red = ft_atoi(color_spl[0]);
	rgb.green = ft_atoi(color_spl[1]);
	rgb.blue = ft_atoi(color_spl[2]);
	ft_free_split(color_spl);
	if (rgb.blue < 0 || rgb.green < 0 || rgb.red < 0
		|| rgb.blue > 255 || rgb.green > 255 || rgb.red > 255)
		rgb.status = FALSE;
	return (rgb);
}

t_collor	check_color(char ***colors)
{
	t_collor	collor;

	collor.status = TRUE;
	if (ft_strcmp(colors[0][0], "F") == 0)
	{
		collor.cell_rgb = check_rgb_color(colors[1]);
		collor.floor_rgb = check_rgb_color(colors[0]);
	}
	else
	{
		collor.cell_rgb = check_rgb_color(colors[0]);
		collor.floor_rgb = check_rgb_color(colors[1]);
	}
	if (collor.cell_rgb.status == FALSE || collor.floor_rgb.status == FALSE)
		collor.status = FALSE;
	return (collor);
}

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
	if (collors[0] == NULL || collors[1] == NULL
		|| ft_strlen_split(collors[0]) < 2 || ft_strlen_split(collors[0]) < 2
		|| ft_strcmp(collors[0][0], collors[1][0]) == 0)
	{
		ft_free_triple(collors);
		return (NULL);
	}
	return (collors);
}

static int	check_player(char pos)
{
	if (pos == 'N' || pos == 'W' || pos == 'S' || pos == 'E')
		return (1);
	return (0);
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
	side = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == ' ')
				continue ;
			else if (check_player(map[i][j]))
				side++;
			else
				return (error_msg(ERROR_CARACTER_INVALID, 2, NULL));
		}
		j = -1;
	}
	if (side == 0)
		return (FALSE);
	else if (side > 1)
		return (error_msg(ERROR_MORE_THEN_ONE_SIDE, 2, NULL));
	return (TRUE);
}
