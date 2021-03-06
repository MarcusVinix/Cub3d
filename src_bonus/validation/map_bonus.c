/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/24 18:43:17 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	has_character(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == ' '
			|| map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '4'
			|| map[i][j] == '5' || map[i][j] == '6')
		return (TRUE);
	else
		return (FALSE);
}

int	valid_size_map(char **map)
{
	if (ft_strlen_split(map) < 3)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Check if the map file and content is valid.
 *
 * @param path_map The path where the map its stored.
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	check_map(char *path_map, t_cub *cub)
{
	cub->content_map = remove_empty_line(store_content_map(path_map));
	if (cub->content_map == NULL)
		return (error_msg(ERROR_FILE_MAP_EMPTY, 2, NULL));
	cub->colors = valid_ceilling_and_floor_color(cub->content_map);
	if (cub->colors == NULL)
		return (error_msg(ERROR_SKY_GRD_N_EXIST, 2, cub));
	cub->collors = check_color(cub->colors);
	if (cub->collors.status == FALSE)
		return (error_msg(ERROR_SKY_GRD_N_EXIST, 2, cub));
	cub->texture_path = valid_texture(cub->content_map);
	if (cub->texture_path == NULL)
		return (error_msg(ERROR_TEXTURE, 2, cub));
	if (texture_file_exist(cub->texture_path) == FALSE)
		return (error_msg(ERROR_TEXTURE_FILE_NOT_EXIST, 2, cub));
	cub->map = store_map_blueprint(cub->content_map);
	if (valid_size_map(cub->map) == FALSE)
		return (error_msg(ERROR_INVALID_SIZE_MAP, 1, cub));
	if (valid_characters(cub->map) == FALSE)
		return (error_msg(ERROR_CARACTER_INVALID, 2, cub));
	if (valid_edge(cub->map) == FALSE)
		return (error_msg(ERROR_INVALID_EDGE, 2, cub));
	return (TRUE);
}
