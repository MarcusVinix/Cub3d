#ifndef STRUCTS_H

#define STRUCTS_H

#include <defines.h>
#include <stdint.h>

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
	int			textureOffSetY;
	int			texNum;
	int			distanceFromTop;
	uint32_t	texelColor;
}				t_projection;

typedef struct s_aux_ray
{
	int		foundWallHit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		WallContent;
	float	nextTouchX;
	float	nextTouchY;
	float	xToCheck;
	float	yToCheck;
	float	HitDistance;
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
}			t_utils_ray;

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

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction; // -1 for leftl, +1 for right
	int		walk_direction; // -1 for back, +1 for front
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
}					t_rect;

typedef struct s_pos
{
	int	y;
	int	x;
}		t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	t_pos	pos;
}			t_data;

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
	t_data	player;
}			t_img;

typedef struct s_map_info
{
	int	height;
	int	width;
}		t_map_info;

typedef struct s_cub
{
	t_player	player;
	t_ray		rays[NUM_RAYS];
	char	***texture_path;
	char	**colors;
	char	**map;
	t_data	img;
	t_data	img_map;
	t_img	sprites;
	t_mlx	s_mlx;
	uint32_t* textures[NUM_TEXTURES];
	t_map_info	map_info;
}			t_cub;

#endif