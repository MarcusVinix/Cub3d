/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection3D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:59:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/08 23:29:18 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void get_values_projection(t_cub *cub, t_projection *var)
{
	var->perp_dist = cub->rays[var->x].distance *
		cos(cub->rays[var->x].ray_angle - cub->player.rotation_angle);
	var->proj_wall_height = (TILE / var->perp_dist) *
		DIST_PROJ_PLANE;
	var->wall_strip_height = (int)var->proj_wall_height;
	var->wall_top_pixel = (HEIGHT / 2) - (var->wall_strip_height / 2);
	if (var->wall_top_pixel < 0)
		var->wall_top_pixel = 0;
	var->wall_bottom_pixel = (HEIGHT / 2) + (var->wall_strip_height / 2);
	if (var->wall_bottom_pixel > HEIGHT)
		var->wall_bottom_pixel = HEIGHT;
}

void	draw_celling(t_cub *cub, t_projection var)
{
	var.y = 0;
	while (var.y < var.wall_top_pixel)
		ft_mlx_pixel_put(&cub->img, var.x, var.y++, 0xFF283747);
}

void	draw_floor(t_cub *cub, t_projection var)
{
	var.y = var.wall_bottom_pixel;
	while (var.y < HEIGHT)
		ft_mlx_pixel_put(&cub->img, var.x, var.y++, 0xFF616A6B);
}

void	get_texture_offset(t_cub *cub, t_projection *var)
{
	if (cub->rays[var->x].was_hit_vertical == TRUE)
		var->texture_offset_x = (int)cub->rays[var->x].wall_hit_y % TILE;
	else
		var->texture_offset_x = (int)cub->rays[var->x].wall_hit_x % TILE;
	check_inverse_offset_x(cub->rays[var->x], &var->texture_offset_x);
	var->texNum = cub->rays[var->x].wall_hit_cotent;
}

void	generate3DProjection(t_cub *cub)
{
	t_projection	var;

	ft_bzero(&var, sizeof(t_projection));
	while (var.x < NUM_RAYS)
	{
		get_values_projection(cub, &var);
		draw_celling(cub, var);
		get_texture_offset(cub, &var);
		var.y = var.wall_top_pixel;
		while (var.y < var.wall_bottom_pixel)
		{
			var.distanceFromTop = var.y + (var.wall_strip_height / 2)
					- (HEIGHT / 2);
			var.textureOffSetY = var.distanceFromTop * ((float)TEXTURE_HEIGHT
					/ var.wall_strip_height);
			var.texelColor = cub->textures[var.texNum][(TEXTURE_WIDTH *
					var.textureOffSetY) + var.texture_offset_x];
			if (cub->rays[var.x].was_hit_vertical == TRUE)
				changeColorIntesity(&var.texelColor, 0.7);
			ft_mlx_pixel_put(&cub->img, var.x, var.y, var.texelColor);
			var.y++;
		}
		draw_floor(cub, var);
		var.x++;
	}
}
