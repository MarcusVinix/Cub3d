/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/10 22:02:46 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		check_map(char *path_map);
char	**store_content_map(char *path_map);
char	**valid_ceilling_and_floor_color(char **content_map);
char	***valid_texture(char **content_map);
char	**texture_file_exist(char **content_map);
int		valid_characters(char **content_map);
int		valid_edge(char **content_map);
char	**store_map_blueprint(char **content_map);
char	**remove_empty_line(char **content_map);
int		valid_characters(char **map);
int		valid_edge(char **map);
int		valid_left_right(char **map);
int		valid_top_bottom(char **map);
int		valid_wall_inside_map(char **map);

#endif