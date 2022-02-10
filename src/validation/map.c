/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/07 21:36:552 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief
 *
 * @return char** Contendo os paths das texturas.
 */
char **texture_file_exist(char **content_map)
{
	char ***textures;
	char **path;
	int i;

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
int valid_texture(char **content_map)
{
	int i;
	char ***textures;
	char *sides[4];

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
char **valid_ceilling_and_floor_color(char **content_map)
{
	char **collors;
	char **key_val;
	char *letters[2];
	int i;

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
 * @param map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_characters(char **map)
{
	int		i;
	int		j;
	char	c;
	int		side;

	j = -1;
	i = -1;
	side = FALSE;
	while(map[++i])
	{
		while(map[i][++j])
		{
			c = map[i][j];
			if (c == '1' || c == '0' || c == ' ' || c == '\t')
				continue ;
			else if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
				if (side == FALSE)
					side = TRUE;
				else
					return (error_msg(ERROR_MORE_THEN_ONE_SIDE, 2));
			else
				return (error_msg(ERROR_CARACTER_INVALID, 2));
		}
		j = 0;
	}
	return (TRUE);
}

int	valid_wall_inside_map(char **map)
{
	int	i;
	size_t	j;

	i = 0;
	j = 0;
	int k = 0;
	while(map[k])
		printf("%s\n", map[k++]);
	while (++i < ft_strlen_split(map) - 1)
	{
		while (++j < ft_strlen(map[i]) - 1)
		{
			if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' ||
				map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
			{
				if (map[i][j] != '1')
				{
					printf("pos i=%i j=%li |%c|%c|%c|%c|%c|\n", i, j, map[i][j], map[i + 1][j], map[i - 1][j], map[i][j + 1], map[i][j - 1]);
					return (error_msg(ERROR_WALL_INSIDE_MAP, 2));
				}
			}
		}
		j = 0;
	}
	return (TRUE);
}

/**
 * @brief Check if the top and the bottom is fulled of number 1.
 *
 * @param map A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int valid_top_bottom(char **map)
{
	int		i;
	int		len;

	len = ft_strlen_split(map) - 1;
	i = -1;
	while(map[0][++i])
	{
		if (map[0][i] == '1' || map[0][i] == ' ' || map[0][i] == '\t')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2));
	}
	i = -1;
	while(map[len][++i])
	{
		if (map[len][i] == '1' || map[len][i] == ' ' || map[len][i] == '\t')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2));
	}
	return (TRUE);
}

/**
 * @brief Check if the wall map of left and right is fulled of number 1.
 * 
 * @param map  A char ** with the content of the map.
 * @return If something its wrong FALSE(0) else TRUE(1).
 */
int	valid_left_right(char **map)
{
	int		i;
	int		len;

	len = ft_strlen(map[0]) - 1;
	i = -1;
	while(map[++i] && map[i][0])
	{
		if (map[i][0] == '1' || map[i][0] == ' ' || map[i][0] == '\t')
			continue ;
		else
			return (error_msg(ERROR_INVALID_EDGE, 2));
	}
	i = -1;
	while(map[++i] && map[i][len])
	{
		if (!(map[i][len] == '1' || map[i][len] == ' ' || map[i][len] == '\t'))
			return (error_msg(ERROR_INVALID_EDGE, 2));
		if (map[i + 1])
			len = ft_strlen(map[i + 1]) - 1;
	}
	return (TRUE);
}

int	valid_edge(char **map)
{
	if (valid_top_bottom(map) == FALSE)
		return (FALSE);
	if (valid_left_right(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Use GNL to store all content of the map into a char **.
 *
 * @param path_map The path where the map its stored.
 * @return If something its wrong NULL else the char ** with the map content.
 */
char **store_content_map(char *path_map)
{
	char **content_map;
	char c;
	int fd;
	int rslt;
	int i;
	int count_line;

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
int count_line_no_empty(char **content_map)
{
	int i;
	int count_line;
	char **line;

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

char **remove_empty_line(char **content_map)
{
	int i;
	int j;
	char **new_map;
	char **line;

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
 * @return char ** with only the blueprint of the map.
 */
char **store_map_blueprint(char **content_map)
{
	char **map;
	int i;
	int j;

	if (!content_map)
		return (NULL);
	map = ft_calloc(ft_strlen_split(content_map) - 5, sizeof(char *));
	i = 6;
	j = 0;
	while (content_map[i])
		map[j++] = ft_strdup(content_map[i++]);
	return (map);
}

/**
 * @brief Check if the map is valid.
 *
 * @param path_map The path where the map its stored.
 * @return If something is wrong return FALSE(0) else TRUE(1).
 */
int check_map(char *path_map)
{
	char **content_map;
	char **texture_path;
	char **colors;
	char **map;

	content_map = remove_empty_line(store_content_map(path_map));
	if (content_map == NULL)
		return (error_msg(ERROR_FILE_MAP_EMPTY, 2));
	map = store_map_blueprint(content_map);
	int j = 0;
	while(map[j])
		printf("%s\n", map[j++]);
	valid_left_right(map);
	valid_characters(map);
	if (valid_texture(content_map) == FALSE)
		return (error_msg(ERROR_TEXTURE, 2));
	texture_path = texture_file_exist(content_map);
	if (texture_path == NULL)
		return (error_msg(ERROR_TEXTURE_FILE_NOT_EXIST, 2));
	colors = valid_ceilling_and_floor_color(content_map);
	if (colors == NULL)
		return (error_msg(ERROR_SKY_GROUND_NOT_EXIST, 2));
	ft_free_split(texture_path);
	ft_free_split(content_map);
	ft_free_split(colors);
	ft_free_split(map);
	return (TRUE);
}
