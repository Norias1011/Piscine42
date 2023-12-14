/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:27:05 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/11 11:38:34 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	check_zero(int b, char **argv)
{
	if (ft_strcmp(argv[2], "/") == 0 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (ft_strcmp(argv[2], "%") == 0 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}
