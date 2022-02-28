#ifndef STRUCTS_H

#define STRUCTS_H

typedef struct s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				deltaX;
	int				deltaY;
	int				longestSideLength;
	float			xIncrement;
	float			yIncrement;
	float			currentX;
	float			currentY;
	unsigned int	color;

}					t_line;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection; // -1 for leftl, +1 for right
	int		walkDirection; // -1 for back, +1 for front
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
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
	double	pdx;
	double	pdy;
	double	pa;
	double	len;
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

typedef struct s_cub
{
	char	***texture_path;
	char	**colors;
	char	**map;
	t_player	player;
	t_pos	move;
	double	x;
	double y;
	t_data	img;
	t_img	sprites;
	t_mlx	s_mlx;
}			t_cub;

#endif