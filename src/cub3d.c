/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:23 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/22 23:49:13 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rec(t_data *img, t_pos pos, int color)
{
	int	i;

	i = -1;
	pos.pdx = 0;
	pos.pdy = 0;
	pos.len = WIDTH;
	while (++i < HEIGHT / 2)
	{
		draw_line(img, pos, color, 2);
		pos.y++;
	}
}

void	draw_background(t_data *img, int color_up, int color_down)
{
	t_pos pos;

	pos.x = 0;
	pos.y = 0;
	rec(img, pos, color_up);
	pos.y = HEIGHT / 2;
	rec(img, pos, color_down);
}

void	draw_img(t_cub *cub, t_data *img, t_pos pos)
{
	unsigned int black = BLACK;
	unsigned int	color;
	int x = 0;
	int y = 0;
	// y column
	// x linha
	while (x < TILE)
	{
		while (y < TILE)
		{
			color = get_color(img, x, y);
			if (color != black)
				ft_mlx_pixel_put(&cub->img, pos.x, pos.y, color);
			y++;
			pos.y++;
		}
		pos.y -= y;
		y = 0;
		x++;
		pos.x++;
	}
}

void	print_sprite(t_cub *cub, int line, int col)
{
	t_pos	pos;

	pos.x = (col * (TILE));
	pos.y = (line * (TILE)) ;
	if (cub->map[line][col] == '1')
		draw_img(cub, &cub->sprites.ea, pos);
	if (cub->map[line][col] == 'N')
	{
		// cub->player.x = line;//4 160
		// cub->player.y = col;//26 1040
		// // draw_img(cub, &cub->sprites.player, pos);

	}
}

void	draw_walls(t_cub *cub)
{
	int		line;
	size_t		col;

	line = 0;
	while (line < ft_strlen_split(cub->map))
	{
		col = 0;
		while (col < ft_strlen(cub->map[line]))
		{
			print_sprite(cub, line, col);
			col++;
		}
		line++;
	}
}

void	draw_gaming(t_cub *cub)
{
	draw_background(&cub->img, 0x808080, 0x708090);
	draw_walls(cub);
	draw_img(cub, &cub->sprites.player, cub->player);
	cub->player.len = 20;
	draw_ray(&cub->img, cub->player);
}

void	sprites(t_data *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->pos.x,
			&img->pos.y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_len, &img->endian);
}

void	init_sprite(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->s_mlx.mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp, &cub->img.l_len, &cub->img.endian);
	sprites(&cub->sprites.ea, cub->s_mlx.mlx, cub->texture_path[0][1]);
	sprites(&cub->sprites.player, cub->s_mlx.mlx, cub->texture_path[1][1]);
}

int	action_loop(t_cub *cub)
{
	
	draw_gaming(cub);
	// mlx_clear_window(cub->s_mlx.mlx, cub->s_mlx.win);
	mlx_put_image_to_window(cub->s_mlx.mlx, cub->s_mlx.win, cub->img.img, 0, 0);

	return (1);
}

void move_player(t_cub *cub, int line, int col)
{
	int	y;
	int	x;
	y = cub->player.y;
	x = cub->player.x;
	cub->map[x][y] = '0';
	cub->map[line][col] = 'N';
	cub->player.x = line;
	cub->player.y = col;
}

int	action(int keycode, t_cub *cub)
{
	(void)keycode;
	(void)cub;
	// int x = cub->player.x;
	// int y = cub->player.y;
	if (keycode == RIGHT)
		{
		// cub->move.x += 5;
		cub->player.pa += 0.1;
		if (cub->player.pa > 2 * PI)
			cub->player.pa -= 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	if (keycode == LEFT)
	{
		// cub->move.x -= 5;
		cub->player.pa -= 0.1;
		if (cub->player.pa < 0)
			cub->player.pa += 2 * PI;
		cub->player.pdx = cos(cub->player.pa) * 5;
		cub->player.pdy = sin(cub->player.pa) * 5;
	}
	if (keycode == TOP)
	{
		cub->move.y -= 0.1;
		cub->player.x += cub->player.pdx;
		cub->player.y += cub->player.pdy;
	}
	if (keycode == DOWN)
	{
		cub->move.y += 0.1;
		cub->player.x -= cub->player.pdx;
		cub->player.y -= cub->player.pdy;
	}
	// move_player(cub, x, y);
	return (1);
}	

void	start_game(t_cub *cub)
{
	t_data img_p;

	ft_bzero(&img_p, sizeof(t_data));
	cub->s_mlx.mlx = mlx_init();
	cub->s_mlx.win = mlx_new_window(cub->s_mlx.mlx, WIDTH, HEIGHT, "cub3D");
	init_sprite(cub);
	cub->player.y = 160;
	cub->player.x = 1040;
	cub->player.pdx = cos(cub->player.pa) * 5;
	cub->player.pdy = sin(cub->player.pa) * 5;
	mlx_hook(cub->s_mlx.win, 2, 1L << 0, action, (void *)cub);
	mlx_loop_hook(cub->s_mlx.mlx, action_loop, (void *)cub);
	mlx_loop(cub->s_mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (is_invalid_arg(argc, argv) == FALSE)
		return (3);
	ft_bzero(&cub, sizeof(t_cub));
	if (check_map(argv[1], &cub) == FALSE)
		return (4);
	start_game(&cub);
	free_struct(&cub);
	return (0);
}
