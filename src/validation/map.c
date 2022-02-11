/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/11 23:50:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	count_valid_chars(char *str)
{
	int	count;
	count = 0;
	while (*str)
	{
		if (*str == '1' || *str == '0')
			count++;
		str++;
	}
	return (count);
}

int	valid_size_map(char **map)
{
	int	i;

	i = 0;
	if (ft_strlen_split(map) < 3)
		return (FALSE);
	while (map[i])
		if (count_valid_chars(map[i++]) < 3)
			return (FALSE);	
	return (TRUE);
}

/**
 * @brief Check if the map file and content is valid.
 *
 * @param path_map The path where the map its stored.
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	check_map(char *path_map)
{
	char	**content_map;
	char	***texture_path;
	char	**colors;
	char	**map;

	content_map = remove_empty_line(store_content_map(path_map));
	if (content_map == NULL)
		return (error_msg(ERROR_FILE_MAP_EMPTY, 2));
	texture_path = valid_texture(content_map);
	if (texture_path == NULL)
		return (error_msg(ERROR_TEXTURE, 2));
	if (texture_file_exist(texture_path) == FALSE)
		return (error_msg(ERROR_TEXTURE_FILE_NOT_EXIST, 2));
	colors = valid_ceilling_and_floor_color(content_map);
	if (colors == NULL)
		return (error_msg(ERROR_SKY_GRD_N_EXIST, 2));
	map = store_map_blueprint(content_map);
	if (valid_size_map(map) == FALSE)
		return (error_msg(ERROR_INVALID_SIZE_MAP, 1));
	if (valid_characters(map) == FALSE)
		return (error_msg(ERROR_CARACTER_INVALID, 2));
	if (valid_edge(map) == FALSE)
		return (error_msg(ERROR_INVALID_EDGE, 2));
	ft_free_triple(texture_path);
	ft_free_split(content_map);
	ft_free_split(colors);
	ft_free_split(map);
	return (TRUE);
}
