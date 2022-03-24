/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:58:01 by coder             #+#    #+#             */
/*   Updated: 2022/03/24 18:23:52 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H

# define STRUCTS_BONUS_H

# include <defines_bonus.h>
# include <stdint.h>

typedef struct s_projection
{
	float		perp_dist;
	float		proj_wall_height;
	int			wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	int			x;
	int			y;
	int			texture_offset_x;
	int			texture_off_sety;
	int			tex_num;
	int			distance_from_top;
	uint32_t	texel_color;
}				t_projection;

typedef struct s_aux_ray
{
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touchx;
	float	next_touchy;
	float	xto_check;
	float	yto_check;
	float	hit_distance;
}			t_aux_ray;

typedef struct s_utils_ray
{
	float		x_intercept;
	float		y_intercept;
	float		x_step;
	float		y_step;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
}				t_utils_ray;

typedef struct s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			was_hit_vertical;
	int			wall_hit_cotent;
}				t_ray;

typedef struct s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				delta_x;
	int				delta_y;
	int				long_side_len;
	float			x_increment;
	float			y_increment;
	float			current_x;
	float			current_y;
	unsigned int	color;

}					t_line;

//turndirection =  -1 for leftl, +1 for right
//walkdirection = -1 for back, +1 for front
typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		orientation;
}			t_player;

typedef struct s_rect
{
	int				x;
	int				y;
	int				width;
	int				height;
	unsigned int	color;
	int				endx;
	int				endy;
}					t_rect;

typedef struct s_pos
{
	int	y;
	int	x;
}		t_pos;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
	t_pos		pos;
	uint32_t	*buffer;
	int			time;
}				t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_img
{
	t_data	no;
	t_data	we;
	t_data	so;
	t_data	ea;
	t_data	sprite2;
	t_data	*sprite3;
	t_data	sprite4;
	t_data	*sprite5;
	t_data	sprite6;
}			t_img;

typedef struct s_map_info
{
	int	height;
	int	width;
	int	startx;
	int	starty;
	int	p_start_y;
	int	p_start_x;
	int	p_end_x;
	int	endx;
	int	endy;
}		t_map_info;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	int		status;
}			t_rgb;

typedef struct s_collor
{
	t_rgb	cell_rgb;
	t_rgb	floor_rgb;
	int		cell;
	int		floor;
	int		status;
}			t_collor;

typedef struct s_sprite {
	float		x;
	float		y;
	float		distance;
	float		angle;
	int			texture;
	int			visible;
	uint32_t	*buffer;
	t_data		img;
	int			content;
}				t_sprite;

typedef struct s_utils_sprite
{
	t_sprite	*visible_sprites;
	int			num_visible_sprite;
	int			i;
	float		angle_sprite_player;
	double		fov;
	int			x;
	int			y;
	t_sprite	sprite;
	float		sprite_height;
	float		sprite_width;
	float		sprite_top_y;
	float		sprite_bottom_y;
	float		sprite_angle;
	float		sprite_screen_posx;
	float		sprite_left_x;
	float		sprite_right_x;
	int			texture_off_set_x;
	int			texture_off_set_y;
	float		texel_width;
	int			distance_from_top;
	float		perp_distance;
	uint32_t	*buffer;
	uint32_t	texel_color;
	float		epsilon;
}				t_utils_sprite;

typedef struct s_cub
{
	t_player	player;
	t_ray		rays[NUM_RAYS];
	char		***texture_path;
	char		***colors;
	char		**map;
	char		**content_map;
	t_data		img;
	t_img		sprites;
	t_mlx		s_mlx;
	uint32_t	*textures[NUM_TEXTURES];
	t_sprite	*sprites_list;
	int			num_sprites;
	t_collor	collors;
	t_map_info	map_info;
	double		dist_proj_plane;
	int			time;
	int			time_check;
}				t_cub;

#endif
