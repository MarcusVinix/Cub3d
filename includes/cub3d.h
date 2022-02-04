/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 01:10:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include	"../libft/libft.h"
# include	"colors.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# define TRUE 1
# define FALSE 0

//erros 
int	error(int error_sig);

//validation
int	is_invalid_arg(int argc, char **argv);
int	check_map(char *path_map);

#endif
