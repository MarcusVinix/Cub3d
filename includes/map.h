/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/11 23:10:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

char	**store_content_map(char *path_map);
char	**valid_ceilling_and_floor_color(char **content_map);
char	***valid_texture(char **content_map);
int		texture_file_exist(char ***texture);
int		valid_characters(char **content_map);
int		valid_edge(char **content_map);
char	**store_map_blueprint(char **content_map);
char	**remove_empty_line(char **content_map);
int		valid_characters(char **map);
int		valid_edge(char **map);
int		valid_left_right(char **map);
int		valid_top_bottom(char **map);
int		valid_wall_inside_map(char **map);
int		valid_size_map(char **map);

#endif