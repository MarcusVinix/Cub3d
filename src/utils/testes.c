// void teste(void)
// {
// 		img_p.img = mlx_xpm_file_to_image(cub->s_mlx.mlx, "./maps/textures/wall.xpm", &xn, &yn);
// 	img_p.addr = mlx_get_data_addr(img_p.img, &img_p.bpp, &img_p.l_len, &img_p.endian);
// 	unsigned int color;

// 	// double x = 50;
// 	double y = 50;
// 	double p = 100;
// 	while (x < 100)
// 	{
// 		while (y < p)
// 		{
// 			ft_mlx_pixel_put(&cub->img, x, y, 0x00FF0000);
// 			y++;
// 		}
// 		p -= 0.1;
// 		y = 50 + (0.1 * x);
// 		x++;
// 	}
// 	int xw = 0;
// 	int yw = 0;
// 	x = 0.1;
// 	y = 0.1;
// 	p = 40;
// 	unsigned int black = BLACK;
// 	// y column
// 	// x linha
// 	while (x < 40)
// 	{
// 		while (y < p)
// 		{
// 			color = get_color(&img_p, x, y);
// 			if (color != black)
// 				ft_mlx_pixel_put(&cub->img, xw - ( 5* x), yw + (5), color);
// 			y += 0.1;
// 			yw++;
// 		}
// 		printf("yw = |%d|\n", yw);
// 		y = 0;
// 		yw = 0;
// 		x += 0.1;
// 		xw++;;
// 	}

// }