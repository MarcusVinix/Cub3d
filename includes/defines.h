/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:46:45 by coder             #+#    #+#             */
/*   Updated: 2022/03/12 19:08:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H

# define DEFINES_H
# include <math.h>

# define TRUE 0
# define FALSE 1
# define TOP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ESC 0xff1b
# define TILE 64
# define BLACK 16777216
# define REDMLX 0x00FF0000
# define WHITE 0xFFFAFA
# define GREEN 0x8EF5BF
# define GREY  0xA0A0A0 
# define BLUEMLX 0x0000FF
# define HEXA "0123456789ABCDEF"

# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 25

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define NUM_TEXTURES 4

# define WIDTH 1200
# define HEIGHT 800

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MINIMAP_WIDTH 150
# define MINIMAP_HEIGHT 150

# define PI 3.14159265
# define TWO_PI 6.28318530
# define MINIMAP_SCALE_FACTOR 0.2
# define NUM_RAYS WIDTH
# define BOX_MINIMAP 10
# define START_POS_MINIMAP 10

# define FPS 30

#endif