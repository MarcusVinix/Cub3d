/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:33:52 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 21:53:42 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H

# define FT_ERRORS_H

# define ERROR_ARG "Invalid arg:\nExemplo: ./cub3d map.cub"
# define ERROR_FILE_MAP_N_EXIST "Map file doesn't exist!"
# define ERROR_FILE_MAP_EMPTY "Empty map file!"
# define ERROR_FILE_EXTENSION "Wrong extension of the file map!"
# define ERROR_TEXTURE "Invalid textures!"
# define ERROR_CEIL_FLOOR_COLOR "Ceiiling and floor color its wrong format."

int	error_msg(char *msg, int level);
int	error(int error_sig);

#endif