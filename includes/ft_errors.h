/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:33:52 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/09 22:51:08 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H

# define FT_ERRORS_H

# define ERROR_ARG "Error:\nInvalid arg:\nExemplo: ./cub3d map.cub"
# define ERROR_FILE_MAP_N_EXIST "Error:\nMap file doesn't exist!"
# define ERROR_FILE_MAP_EMPTY "Error:\nEmpty map file!"
# define ERROR_FILE_EXTENSION "Error:\nWrong extension of the file map!"
# define ERROR_TEXTURE "Error:\nInvalid textures!"
# define ERROR_CEIL_FLOOR_COLOR "Error:\nCeiiling and floor color its wrong format."
# define ERROR_TEXTURE_FILE_NOT_EXIST "Error:\nTexture files doesn't exist!"
# define ERROR_SKY_GROUND_NOT_EXIST "Error:\nSky and ground colors doesn't exist in map file!"
# define ERROR_CARACTER_INVALID "Error:\nCharacter invalid!"
# define ERROR_MORE_THEN_ONE_SIDE "Error\nOnly one side of position is allowed!"
# define ERROR_INVALID_EDGE "Error:\nThe bord of the map must be 1."
# define ERROR_WALL_INSIDE_MAP "Error:\nThe wall inside the map must be 1."

int	error_msg(char *msg, int level);
int	error(int error_sig);

#endif