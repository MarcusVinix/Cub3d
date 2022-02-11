/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:32 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/12 00:32:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Check if the file has the same extension passed.
 * 
 * @param str file to check.
 * @param extension to compare with the file.
 * @return If the extensio is right TRUE(1) else FALSE(0).
 */
int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

/**
 * @brief Check if the file exists.
 * 
 * @param map_path path of the map.
 * @return If the file exists TRUE(1) else FALSE(0).
 */
int	file_exist(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

/**
 * @brief Check if the args is valid.
 * 
 * @param argc Passed, if is diferent of 2 its wrong.
 * @param argv Check the index 1 to valid the map file.
 * @return If something its wrong FALSE(0) else TRUE(1). 
 */
int	is_invalid_arg(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg(ERROR_ARG, 2, NULL));
	else if (check_extension(argv[1], ".cub") == FALSE)
		return (error_msg(ERROR_FILE_EXTENSION, 2, NULL));
	else if (file_exist(argv[1]))
		return (error_msg(ERROR_FILE_MAP_N_EXIST, 2, NULL));
	return (TRUE);
}
