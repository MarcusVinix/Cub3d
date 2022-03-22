/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:23 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/22 01:36:47 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	key_release(int key, t_cub *cub)
{
	if (key == RIGHT || key == ARROW_RIGHT)
		cub->player.turn_direction = 0;
	if (key == LEFT || key == ARROW_LEFT)
		cub->player.turn_direction = 0;
	if (key == TOP)
		cub->player.walk_direction = 0;
	if (key == DOWN)
		cub->player.walk_direction = 0;
	return (0);
}

void	start_game(t_cub *cub)
{
	t_data	img_p;

	ft_bzero(&img_p, sizeof(t_data));
	cub->s_mlx.mlx = mlx_init();
	cub->s_mlx.win = mlx_new_window(cub->s_mlx.mlx, WIDTH, HEIGHT, "cub3D");
	build_main_img(cub);
	setup(cub);
	mlx_hook(cub->s_mlx.win, 17, 0, close_win, (void *)cub);
	mlx_hook(cub->s_mlx.win, 2, 1L << 0, action, (void *)cub);
	mlx_hook(cub->s_mlx.win, 3, 1L << 1, key_release, (void *)cub);
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
