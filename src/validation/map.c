/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 02:07:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	valid_texture(char **content_map)
{
	(void)content_map;
	return (FALSE);
}

char	**store_content_map(char *path_map)
{
	char **content_map;
	char c;
	int fd;
	int rslt;
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	fd = open(path_map, O_RDONLY);
	rslt = read(fd, &c, 1);
	if (rslt == 0)
		return (NULL);
	while(rslt > 0)
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

int	check_map(char *path_map)
{
	char **content_map;

	content_map = store_content_map(path_map);
	if (content_map == NULL)
		return (TRUE);
	valid_texture(content_map);
	return (FALSE);
}
