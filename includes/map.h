/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/05 01:30:05 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		check_map(char *path_map);
char	**store_content_map(char *path_map);
int		valid_ceilling_and_floor_color(char **content_map);
int		valid_texture(char **content_map);
char	**texture_file_exist(char **content_map);
int		valid_characters(char **content_map);
int		valid_edge(char **content_map);

#endif
