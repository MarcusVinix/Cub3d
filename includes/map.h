/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 21:26:48 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define ERROR_ARG "Invalid arg:\nExemplo: ./cub3d map.cub"

int		check_map(char *path_map);
char	**store_content_map(char *path_map);
int		valid_ceilling_and_floor_color(char **content_map);
int		valid_texture(char **content_map);

#endif
