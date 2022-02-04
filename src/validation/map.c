/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 21:58:38 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if the file of texture exist and its passed correctly 
 * at the map file.
 * 
 * @param content_map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_texture(char **content_map)
{
	(void)content_map;
	return (FALSE);
}

/**
 * @brief Check if the colors of ceilling and floor its on
 * the right format.
 * 
 * @param content_map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_ceilling_and_floor_color(char **content_map)
{
	(void)content_map;
	return (FALSE);
}

/**
 * @brief Use GNL to store all content of the map into a char **.
 * 
 * @param path_map The path where the map its stored.
 * @return If something its wrong NULL else the char ** with the map content.
 */
char	**store_content_map(char *path_map)
{
	char	**content_map;
	char	c;
	int		fd;
	int		rslt;
	int		i;
	int		count_line;

	i = 0;
	count_line = 0;
	fd = open(path_map, O_RDONLY);
	rslt = read(fd, &c, 1);
	if (rslt == 0)
		return (NULL);
	while (rslt > 0)
	{
		if (c == '\n')
			count_line++;
		rslt = read(fd, &c, 1);
	}
	close(fd);
	fd = open(path_map, O_RDONLY);
	content_map = ft_calloc(count_line + 1, sizeof(char *));
	while (get_next_line(fd, &content_map[i++]))
		;
	content_map[i] = NULL;
	close(fd);
	return (content_map);
}

/**
 * @brief Check if the map is valid.
 * 
 * @param path_map The path where the map its stored.
 * @return If something is wrong return FALSE(0) else TRUE(1).
 */
int	check_map(char *path_map)
{
	char	**content_map;

	content_map = store_content_map(path_map);
	if (content_map == NULL)
		return (error_msg(ERROR_FILE_MAP_EMPTY, 2));
	if (valid_texture(content_map) == TRUE)
		return (error_msg(ERROR_TEXTURE, 2));
	if (valid_ceilling_and_floor_color(content_map) == TRUE)
		return (error_msg(ERROR_CEIL_FLOOR_COLOR, 2));
	return (FALSE);
}
