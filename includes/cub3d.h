/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/12 00:50:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include	"../libft/libft.h"
# include	"colors.h"
# include	<ft_errors.h>
# include	<map.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# define TRUE 0
# define FALSE 1

typedef struct s_cub
{
	char	***texture_path;
	char	**colors;
	char	**map;
}			t_cub;

//erros 

//validation
int		is_invalid_arg(int argc, char **argv);
int		file_exist(char *map_path);
int		check_extension(char *str, char *extension);
int		check_map(char *path_map, t_cub *cub);

int		error_msg(char *msg, int level, t_cub *cub);
//free
void	free_struct(t_cub *cub);

#endif
