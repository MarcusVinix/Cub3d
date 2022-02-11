/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:04 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/12 00:37:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	error(int error_sig)
{
	if (error_sig == 1)
		printf("%sInvalid arg:\nExemplo: ./cub3d map.cub%s\n", RED, RESET);
	else if (error_sig == 2)
		printf("%sFile doesn't exist!%s\n", RED, RESET);
	return (FALSE);
}

/**
 * @brief Print a message error.
 * 
 * @param msg error to be printed
 * @param level 1 - (Warning) or 2 - (Error)
 * @return int 1
 */
int	error_msg(char *msg, int level, t_cub *cub)
{
	if (cub != NULL)
		free_struct(cub);
	if (level == 1)
	{
		ft_putstr_fd(YEL, 2);
		ft_putstr_fd(msg, 2);
		ft_putendl_fd(RESET, 2);
	}
	else if (level == 2)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd(msg, 2);
		ft_putendl_fd(RESET, 2);
	}
	return (FALSE);
}
