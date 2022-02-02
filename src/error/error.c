/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:22:04 by mavinici          #+#    #+#             */
/*   Updated: 2022/02/02 01:22:08 by mavinici         ###   ########.fr       */
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
