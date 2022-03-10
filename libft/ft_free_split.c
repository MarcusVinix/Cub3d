/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:29:22 by mavinici          #+#    #+#             */
/*   Updated: 2022/03/10 21:58:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Free a char **
char	*ft_free_split(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count])
		free(str[count++]);
	free(str);
	return (NULL);
}
