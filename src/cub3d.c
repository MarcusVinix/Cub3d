/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:23 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/12 17:55:22 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
