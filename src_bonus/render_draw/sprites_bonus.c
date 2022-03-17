/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:20:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/17 21:02:44 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	get_all_visible_sprite(t_utils_sprite *var, t_cub *cub)
{
	while (++var->i < cub->num_sprites)
	{
		normalize_angle(&cub->player.rotation_angle);
		var->angle_sprite_player = cub->player.rotation_angle - atan2(
				cub->sprites_list[var->i].y - cub->player.y,
				cub->sprites_list[var->i].x - cub->player.x);
		if (var->angle_sprite_player > PI)
			var->angle_sprite_player -= TWO_PI;
		if (var->angle_sprite_player < -PI)
			var->angle_sprite_player += TWO_PI;
		var->angle_sprite_player = fabs(var->angle_sprite_player);
		if (var->angle_sprite_player < (var->fov / 2) + var->epsilon)
		{
			cub->sprites_list[var->i].visible = TRUE;
			cub->sprites_list[var->i].angle = var->angle_sprite_player;
			cub->sprites_list[var->i].distance = distance_between_points(
					cub->sprites_list[var->i].x, cub->sprites_list[var->i].y,
					cub->player.x, cub->player.y);
			var->visible_sprites[var->num_visible_sprite]
				= cub->sprites_list[var->i];
			var->num_visible_sprite++;
		}
		else
			cub->sprites_list[var->i].visible = FALSE;
	}
}

void	get_color_and_buffer(t_utils_sprite *var, t_cub *cub)
{
	if (var->sprite.content == '2')
		var->buffer = cub->sprites.sprite2.buffer;
	else if (var->sprite.content == '3')
		var->buffer = cub->sprites.sprite3.buffer;
	else
		var->buffer = cub->sprites.sprite4.buffer;
	var->texel_color = var->buffer[(TEXTURE_WIDTH * var->texture_off_set_y)
		+ var->texture_off_set_x];
}

void	print_sprite_pixels(t_utils_sprite *var, t_cub *cub)
{
	while (var->x < var->sprite_right_x)
	{
		var->texel_width = (TEXTURE_WIDTH / var->sprite_width);
		var->texture_off_set_x = (var->x - var->sprite_left_x)
			* var->texel_width;
		var->y = var->sprite_top_y - 1;
		while (++var->y < var->sprite_bottom_y)
		{
			if (is_inside_map(var->x, var->y, cub) == TRUE)
			{
				var->distance_from_top = var->y + (var->sprite_height / 2)
					- (HEIGHT / 2);
				var->texture_off_set_y = var->distance_from_top
					* (TEXTURE_HEIGHT / var->sprite_height);
				get_color_and_buffer(var, cub);
				if (var->sprite.distance < cub->rays[var->x].distance
					&& var->texel_color != (unsigned int)BLACK
					&& var->texel_color != 0xFF00FF)
					ft_mlx_pixel_put(&cub->img, var->x, var->y,
						var->texel_color);
			}
		}
		var->x++;
	}
}

void	sprite_render(t_utils_sprite *var, t_cub *cub)
{
	var->i = -1;
	while (++var->i < var->num_visible_sprite)
	{
		var->sprite = var->visible_sprites[var->i];
		var->perp_distance = var->sprite.distance * cos(var->sprite.angle);
		var->sprite_height = (TILE / var->perp_distance) * cub->dist_proj_plane;
		var->sprite_width = var->sprite_height;
		var->sprite_top_y = (HEIGHT / 2) - (var->sprite_height / 2);
		if (var->sprite_top_y < 0)
			var->sprite_top_y = 0;
		var->sprite_bottom_y = (HEIGHT / 2) + (var->sprite_height / 2);
		if (var->sprite_bottom_y > HEIGHT)
			var->sprite_bottom_y = HEIGHT;
		var->sprite_angle = atan2(var->sprite.y - cub->player.y, var->sprite.x
				- cub->player.x) - cub->player.rotation_angle;
		var->sprite_screen_posx = tan(var->sprite_angle) * cub->dist_proj_plane;
		var->sprite_left_x = (WIDTH / 2) + var->sprite_screen_posx
			- (var->sprite_width / 2);
		var->sprite_right_x = var->sprite_left_x + var->sprite_width;
		var->x = var->sprite_left_x;
		print_sprite_pixels(var, cub);
	}
}

void	render_sprite_projection(t_cub *cub)
{
	t_utils_sprite	var;

	ft_bzero(&var, sizeof(t_utils_sprite));
	init_some_values_sprites(&var, cub);
	get_all_visible_sprite(&var, cub);
	sort_visible_sprites(&var);
	sprite_render(&var, cub);
	free(var.visible_sprites);
}
