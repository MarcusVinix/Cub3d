/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:09:47 by coder             #+#    #+#             */
/*   Updated: 2022/02/12 00:40:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_struct(t_cub *cub)
{
	if (cub->texture_path != NULL)
		ft_free_triple(cub->texture_path);
	if (cub->colors != NULL)
		ft_free_split(cub->colors);
	if (cub->map != NULL)
		ft_free_split(cub->map);
}
