/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:05:44 by coder             #+#    #+#             */
/*   Updated: 2022/04/01 00:07:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_all_num(char *str)
{
	int		index;
	int		count;
	int		spaces;
	char	*new_str;

	spaces = 0;
	index = -1;
	count = 0;
	new_str = ft_strtrim(str, " ");
	while (new_str[++index])
	{
		if (ft_isdigit(new_str[index]) || new_str[index] == '-'
			|| new_str[index] == '+')
			count++;
		else
			spaces++;
	}
	free(new_str);
	if (count > 3 || spaces != 0)
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
