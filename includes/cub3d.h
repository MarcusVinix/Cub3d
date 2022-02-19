/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:20:26 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/19 02:10:25 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include	"../libft/libft.h"
# include	"colors.h"
# include	<ft_errors.h>
# include	<map.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<mlx.h>
#include <math.h>

# define TRUE 0
# define FALSE 1
# define TOP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ESC 0xff1b
# define BLACK -16777216
# define WIDTH 900
# define HEIGHT 900
# define TILE 40

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

typedef struct s_cub
{
	char	***texture_path;
	char	**colors;
	char	**map;
	t_pos	player;
	t_pos	move;
	double	x;
	double y;
	t_data	img;
	t_img	sprites;
	t_mlx	s_mlx;
}			t_cub;

//erros 

//validation
int		is_invalid_arg(int argc, char **argv);
int		file_exist(char *map_path);
int		check_extension(char *str, char *extension);
int		check_map(char *path_map, t_cub *cub);

int		error_msg(char *msg, int level, t_cub *cub);
//free
void	free_struct(t_cub *cub);

void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);
void	draw_line(t_data *img, int beginX, int beginY, int color, int sig);



#endif
