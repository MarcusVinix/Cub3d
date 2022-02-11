/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:00:21 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/11 17:40:36 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Use GNL to store all content of the map into a char **.
 *
 * @param path_map The path where the map its stored.
 * @return On Sucess the content of the map. Null if something wrong.
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
	count_line = 1;
	fd = open(path_map, O_RDONLY);
	rslt = read(fd, &c, 1);
	if (rslt == 0)
		return (NULL);
	while (rslt > 0)
	{
		if (c == '\n' || c == EOF)
			count_line++;
		rslt = read(fd, &c, 1);
	}
	close(fd);
	fd = open(path_map, O_RDONLY);
	content_map = malloc((count_line + 1) * sizeof(char *));
	while (get_next_line(fd, &content_map[i++]))
		;
	content_map[i] = NULL;
	close(fd);
	return (content_map);
}

/**
 * @brief Count the lines of the content map except the empty lines.
 *
 * @param content_map The content of the map
 * @return int the count of lines.
 */
int	count_line_no_empty(char **content_map)
{
	int		i;
	int		count_line;
	char	**line;

	if (!content_map)
		return (0);
	i = 0;
	count_line = 0;
	while (content_map[i])
	{
		line = ft_split(content_map[i], ' ');
		if (*line != NULL)
			count_line++;
		ft_free_split(line);
		i++;
	}
	return (count_line);
}

/**
 * @brief Remove all empty line on the content map.
 * 
 * @param content_map The content of the map
 * @return On Sucess the content of map without empty line.
 *  Null if something wrong
 */
char	**remove_empty_line(char **content_map)
{
	int		i;
	int		j;
	char	**new_map;
	char	**line;

	if (!content_map)
		return (NULL);
	i = 0;
	j = 0;
	new_map = ft_calloc(count_line_no_empty(content_map) + 1, sizeof(char *));
	while (content_map[i])
	{
		line = ft_split(content_map[i], ' ');
		if (*line != NULL)
			new_map[j++] = ft_strdup(content_map[i]);
		ft_free_split(line);
		i++;
	}
	ft_free_split(content_map);
	content_map = NULL;
	return (new_map);
}

/**
 * @brief Store and return only the blueprint of the map.
 *
 * @param content_map All content of the map.
 * @return On Sucess the blueprint of map. Null if something wrong.
 */
char	**store_map_blueprint(char **content_map)
{
	char	**map;
	int		i;
	int		j;

	if (!content_map)
		return (NULL);
	map = ft_calloc(ft_strlen_split(content_map) - 5, sizeof(char *));
	i = 6;
	j = 0;
	while (content_map[i])
		map[j++] = ft_strdup(content_map[i++]);
	return (map);
}
