/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cero_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:43:57 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 22:51:54 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"
#include <stdio.h>

int	is_zero(int groups, char **numbers)
{
	if (!numbers[0][1] && !numbers[0][0] && groups == 1)
	{
		return (1);
	}
	return (0);
}

void	cero_handler(char ***dict, int lines)
{
	char	holder[2];

	holder[0] = '0';
	holder[1] = '\0';
	print_key(holder, dict, lines);
}
