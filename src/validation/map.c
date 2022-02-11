/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/11 17:49:40 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	map = store_map_blueprint(content_map);
	valid_left_right(map);
	valid_characters(map);
	valid_wall_inside_map(map);
	texture_file_exist(texture_path);
	if (texture_path == NULL)
		return (error_msg(ERROR_TEXTURE_FILE_NOT_EXIST, 2));
	colors = valid_ceilling_and_floor_color(content_map);
	if (colors == NULL)
		return (error_msg(ERROR_SKY_GRD_N_EXIST, 2));
	ft_free_triple(texture_path);
	ft_free_split(content_map);
	ft_free_split(colors);
	ft_free_split(map);
	return (TRUE);
}
