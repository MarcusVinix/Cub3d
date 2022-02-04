/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 21:46:27 by mavinici         ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

//erros 

//validation
int	is_invalid_arg(int argc, char **argv);
int	check_map(char *path_map);

#endif
