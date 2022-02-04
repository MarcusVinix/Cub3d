/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:04 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/04 21:43:27 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	error(int error_sig)
{
	if (error_sig == 1)
		printf("%sInvalid arg:\nExemplo: ./cub3d map.cub%s\n", RED, RESET);
	else if (error_sig == 2)
		printf("%sFile doesn't exist!%s\n", RED, RESET);
	return (TRUE);
}

/**
 * @brief Print a message error.
 * 
 * @param msg error to be printed
 * @param level 1 - (Warning) or 2 - (Error)
 * @return int 1
 */
int error_msg(char *msg, int level)
{
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
	return (TRUE);
}
