/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:46:45 by coder             #+#    #+#             */
/*   Updated: 2022/03/22 00:03:52 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_BONUS_H

# define DEFINES_BONUS_H
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
# define BLACK -16777216
# define PINK 0xFF00FF
# define REDMLX 0x00FF0000
# define WHITE 0xFFFAFA
# define GREEN 0x58E64F
# define GREY  0xA0A0A0 
# define BLUEMLX 0x0000FF

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define NUM_TEXTURES 4
# define NUM_SPRITES 1
# define LINES 6

# define WIDTH 1200
# define HEIGHT 800

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MINIMAP_WIDTH 150
# define MINIMAP_HEIGHT 150

# define PI 3.14159265
# define TWO_PI 6.28318530
# define MINIMAP_SCALE_FACTOR 0.3
# define NUM_RAYS WIDTH
# define BOX_MINIMAP 5
# define START_POS_MINIMAP 10

# define SPRITE2 "maps/sprites/armor.xpm"
# define SPRITE3 "maps/sprites/animated"
# define SPRITE4 "maps/sprites/table_lamp.xpm"
# define SPRITE6 "maps/sprites/barrel.xpm"

#endif