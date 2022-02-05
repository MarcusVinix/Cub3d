/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/05 01:28:06 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief 
 * 
 * @return char** Contendo os paths das texturas.
 */
char	**texture_file_exist(char **content_map)
{
	char	***textures;
	char	**path;
	int		i;

	i = -1;
	textures = ft_calloc(5, sizeof(char *));
	path = ft_calloc(5, sizeof(char *));
	while (++i < 4)
	{
		textures[i] = ft_split(content_map[i], ' ');
		path[i] = ft_strdup(textures[i][1]);
		if (file_exist(path[i]) == FALSE || check_extension(path[i], ".xpm") == FALSE)
		{
			ft_free_split(path);
			return ((char **)ft_free_triple(textures));
		}
	}
	path[i] = NULL;
	textures[i] = NULL;
	ft_free_triple(textures);
	return (path);
}

/**
 * @brief Check if the file of texture exist and its passed correctly 
 * at the map file.
 * 
 * @param content_map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_texture(char **content_map)
{
	int		i;
	char	***textures;
	char	*sides[4];

	i = -1;
	sides[0] = "NO";
	sides[1] = "SO";
	sides[2] = "WE";
	sides[3] = "EA";
	textures = ft_calloc(5, sizeof(char *));
	while (++i < 4 && i < ft_strlen_split(content_map))
		textures[i] = ft_split(content_map[i], ' ');
	textures[i] = NULL;
	i = -1;
	while (textures[++i])
	{
		if (ft_strcmp(textures[i][0], sides[i]) != 0)
		{
			ft_free_triple(textures);
			return (FALSE);
		}
	}
	ft_free_triple(textures);
	return (TRUE);
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
	return (TRUE);
}

/**
 * @brief Check if have only the allowed characters on the map.
 * 
 * @param content_map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_characters(char **content_map)
{
	(void)content_map;
	return (TRUE);
}

/**
 * @brief Check if the edge is fulled of number 1.
 * 
 * @param content_map  A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_edge(char **content_map)
{
	(void)content_map;
	return (TRUE);
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
 * @brief Check if the map is valid.
 * 
 * @param path_map The path where the map its stored.
 * @return If something is wrong return FALSE(0) else TRUE(1).
 */
int	check_map(char *path_map)
{
	char	**content_map;
	char	**texture_path;

	content_map = store_content_map(path_map);
	printf("lengh %i\n", ft_strlen_split(content_map));
	if (content_map == NULL)
		return (error_msg(ERROR_FILE_MAP_EMPTY, 2));
	if (valid_texture(content_map) == FALSE)
		return (error_msg(ERROR_TEXTURE, 2));
	if (valid_ceilling_and_floor_color(content_map) == FALSE)
		return (error_msg(ERROR_CEIL_FLOOR_COLOR, 2));
	texture_path = texture_file_exist(content_map);
	if (texture_path == NULL)
		return (error_msg(ERROR_TEXTURE_FILE_NOT_EXIST, 2));
	ft_free_split(texture_path);
	ft_free_split(content_map);
	return (TRUE);
}
