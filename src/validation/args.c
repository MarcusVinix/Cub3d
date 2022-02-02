/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:32 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/02 01:23:32 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_extension(char *str, char *extension)
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

static int	file_exist(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (TRUE);
	close(fd);
	return (FALSE);
}

int	is_invalid_arg(int argc, char **argv)
{
	if (argc != 2)
		return (error(1));
	else if (check_extension(argv[1], ".cub") == FALSE)
		return (error(1));
	else if (file_exist(argv[1]))
		return (error(2));
	return (FALSE);
}
