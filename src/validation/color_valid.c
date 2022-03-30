/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:05:44 by coder             #+#    #+#             */
/*   Updated: 2022/03/30 16:00:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_all_num(char *str)
{
	int	index;
	int	count;

	index = -1;
	count = 0;
	while (str[++index])
	{
		if (str[index] == ' ' && count == 0)
			continue ;
		if (ft_isdigit(str[index]) || str[index] == '-' || str[index] == '+')
			count++;
		else
			return (1);
	}
	if (count > 3)
		return (1);
	return (0);
}

int	verify_collor_char(t_rgb *rgb, char **collors)
{
	int	size;
	int	i;

	size = ft_strlen_split(collors);
	i = 0;
	while (i < size)
	{
		if (is_all_num(collors[i]) == 1)
		{
			ft_free_split(collors);
			rgb->status = FALSE;
			return (1);
		}
		i++;
	}
	return (0);
}
