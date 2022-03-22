/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:57:10 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/22 12:56:23 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if all texture file exist.
 *
 * @return On sucess TRUE. FALSE if something its wrong.
 */
int	texture_file_exist(char ***texture)
{
	int	i;

	i = -1;
	while (texture[++i])
		if (file_exist(texture[i][1]) == FALSE ||
			check_extension(texture[i][1], ".xpm") == FALSE)
			return (FALSE);
	return (TRUE);
}

static char	***create_sides(void)
{
	char	***sides;

	sides = ft_calloc(5, sizeof(char *));
	sides[0] = ft_split("NO FILE", ' ');
	sides[1] = ft_split("SO FILE", ' ');
	sides[2] = ft_split("WE FILE", ' ');
	sides[3] = ft_split("EA FILE", ' ');
	return (sides);
}

static void	compare_textures(char ***textures, char ***sides, int *j)
{
	int	i;

	i = -1;
	while ((++i < 6 && textures[i][0]) && *j != 4)
	{
		if (ft_strcmp(textures[i][0], sides[*j][0]) == 0)
		{
			free(sides[*j][1]);
			if (textures[i][1])
			{
				sides[*j][1] = ft_strdup2(textures[i][1]);
				*j += 1;
			}
			i = -1;
		}
	}
}

/**
 * @brief Check if map has all necessary texture.
 * Store the line of each texture inside a triple pointer.
 *
 * @param content_map the content of the map.
 * @return On Sucess a triple pointer with the name and file of texture.
 * Null if something wrong
 */
char	***valid_texture(char **content_map)
{
	int		i;
	int		j;
	char	***textures;
	char	***sides;

	i = -1;
	sides = create_sides();
	textures = ft_calloc(7, sizeof(char *));
	while (++i < 6 && i < ft_strlen_split(content_map))
		textures[i] = ft_split(content_map[i], ' ');
	i = -1;
	j = 0;
	compare_textures(textures, sides, &j);
	ft_free_triple(textures);
	if (j != 4)
	{
		ft_free_triple(sides);
		return (NULL);
	}
	return (sides);
}
