/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:23 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/16 21:55:08 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	start_game(t_cub *cub)
{
	cub->s_mlx.mlx = mlx_init();
	cub->s_mlx.win = mlx_new_window(cub->s_mlx.mlx, 600, 600, "cub3D");
	mlx_loop(cub->s_mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (is_invalid_arg(argc, argv) == FALSE)
		return (3);
	if (check_map(argv[1], &cub) == FALSE)
		return (4);
	start_game(&cub);
	free_struct(&cub);
	return (0);
}
