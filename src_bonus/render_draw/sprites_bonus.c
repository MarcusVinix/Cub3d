/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:20:16 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/15 16:12:25 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	render_sprite_projection(t_cub *cub)
{
	t_sprite	visible_sprites[NUM_SPRITES];
	int			num_visible_sprite = 0;
	int			i;
	float		angle_sprite_player;
	double	fov;
	int	x;
	int	y;

	(void)visible_sprites;
	fov = 60 * (PI / 180);
	// Find sprites that are visible (inside the FOV)
	i = -1;
	while (++i < NUM_SPRITES)
	{
		normalize_angle(&cub->player.rotation_angle);
		angle_sprite_player = cub->player.rotation_angle - atan2(
			cub->sprites_list[i].y - cub->player.y, cub->sprites_list[i].x - cub->player.x);
		if (angle_sprite_player > PI)
			angle_sprite_player -= TWO_PI;
		if (angle_sprite_player < -PI)
			angle_sprite_player += TWO_PI;
		angle_sprite_player = fabs(angle_sprite_player);
		// If sprite angle is lees than half the FOV plus a small error marginn
		const float	EPSILON = 0.2;
		if (angle_sprite_player < (fov / 2) + EPSILON)
		{
			cub->sprites_list[i].visible = TRUE;
			cub->sprites_list[i].angle = angle_sprite_player;
			cub->sprites_list[i].distance = distance_between_points(
				cub->sprites_list[i].x,
				cub->sprites_list[i].y,
				cub->player.x,
				cub->player.y
			);
			visible_sprites[num_visible_sprite] = cub->sprites_list[i];
			num_visible_sprite++;
		}
		else
		{
			cub->sprites_list[i].visible = FALSE;
		}
	}

	// Sort sprites by distance usinng a naive bubble-sort algorithm
	for (int i = 0; i < num_visible_sprite - 1; i++)
	{
		for (int j = i + 1; j < num_visible_sprite; j++)
		{
			if (visible_sprites[i].distance < visible_sprites[j].distance)
			{
				t_sprite temp = visible_sprites[i];
				visible_sprites[i] = visible_sprites[j];
				visible_sprites[j] = temp;
			}
		}
	}

	//rennder
	i = -1;
	t_sprite sprite;
	float	sprite_height;
	float	sprite_width;
	float	sprite_top_y;
	float	sprite_bottom_y;
	float	sprite_angle;
	float	sprite_screen_posx;
	float	sprite_left_x;
	float	sprite_right_x;
	int		texture_off_set_x;
	int		texture_off_set_y;
	float	texel_width;
	int		distance_from_top;
	float	perp_distance;
	while (++i < num_visible_sprite)
	{
		sprite = visible_sprites[i];

		// Calculate the perpendicular distance of the sprite to prevent fish-eye effect
		perp_distance = sprite.distance * cos(sprite.angle);
		
		// calculate the sprite projected height and width 
		sprite_height = (TILE / perp_distance) * cub->dist_proj_plane;
		sprite_width = sprite_height;

		//sprite top y
		sprite_top_y = (HEIGHT / 2) - (sprite_height / 2);
		if (sprite_top_y < 0)
			sprite_top_y = 0;

		//sprrite  bottom y
		sprite_bottom_y = (HEIGHT / 2) + (sprite_height / 2);
		if (sprite_bottom_y > HEIGHT)
			sprite_bottom_y = HEIGHT;
		 
		 // Calculate the sprite X position in the projecttion plane
		 sprite_angle = atan2(sprite.y - cub->player.y, sprite.x - cub->player.x) - cub->player.rotation_angle;
		 sprite_screen_posx = tan(sprite_angle) * cub->dist_proj_plane;

		 //spriteLEftX
		 sprite_left_x = (WIDTH / 2) + sprite_screen_posx - (sprite_width / 2);

		 //sprite Rightx
		 sprite_right_x = sprite_left_x + sprite_width;

		x = sprite_left_x;
		while (x < sprite_right_x)
		{
			texel_width = (TEXTURE_WIDTH / sprite_width);
			texture_off_set_x = (x - sprite_left_x) * texel_width;
			y = sprite_top_y;
			while (y < sprite_bottom_y)
			{
				if (is_inside_map(x, y, cub) == TRUE)
				{
					distance_from_top = y + (sprite_height / 2) - (HEIGHT / 2);
					texture_off_set_y = distance_from_top * (TEXTURE_HEIGHT / sprite_height);
					uint32_t texel_color = sprite.buffer[(TEXTURE_WIDTH * texture_off_set_y)
						+ texture_off_set_x ];
					if (sprite.distance < cub->rays[x].distance &&texel_color != (unsigned int)BLACK)
						ft_mlx_pixel_put(&cub->img, x, y, texel_color);
				}
				y++;
			}
			x++;
		}
	}
}
