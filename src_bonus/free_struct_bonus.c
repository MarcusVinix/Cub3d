/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:09:47 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 23:34:54 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	free_buffer(t_cub *cub)
{
	int	i;

	free(cub->sprites.sprite2.buffer);
	i = -1;
	while (++i < 3)
		free(cub->sprites.sprite3[i].buffer);
	free(cub->sprites.sprite4.buffer);
	i = -1;
	while (++i < 4)
		free(cub->sprites.sprite5[i].buffer);
	free(cub->sprites.sprite6.buffer);
}

void	free_images(t_cub *cub)
{
	int	i;

	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.no.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.so.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.we.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.ea.img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.sprite2.img);
	i = -1;
	while (++i < 3)
		mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.sprite3[i].img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.sprite4.img);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.sprite5[i].img);
	mlx_destroy_image(cub->s_mlx.mlx, cub->sprites.sprite6.img);
}

void	free_mlx_all(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
		free(cub->textures[i++]);
	free(cub->sprites_list);
	mlx_destroy_image(cub->s_mlx.mlx, cub->img.img);
	mlx_destroy_window(cub->s_mlx.mlx, cub->s_mlx.win);
	mlx_destroy_display(cub->s_mlx.mlx);
	ft_free_ptr(&cub->s_mlx.mlx);
	free_buffer(cub);
	free(cub->sprites.sprite3);
	free(cub->sprites.sprite5);
}

void	free_struct(t_cub *cub)
{
	if (cub->texture_path != NULL)
		ft_free_triple(cub->texture_path);
	if (cub->colors != NULL)
		ft_free_triple(cub->colors);
	if (cub->map != NULL)
		ft_free_split(cub->map);
	if (cub->content_map != NULL)
		ft_free_split(cub->content_map);
}

/* Free the allocated memory of the map and close the window */
int	close_win(t_cub *cub)
{
	free_struct(cub);
	free_mlx_all(cub);
	exit(0);
}
