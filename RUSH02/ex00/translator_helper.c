/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:59:34 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 19:59:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helper_functions.h"

int	key_is_equal(char *key, char *to_search)
{
	int	i;

	i = 0;
	while (to_search[i])
	{
		if (key[i] != to_search[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_search_key(int groups)
{
	char	*multiplier;
	int		key_size;
	int		i;

	i = 0;
	key_size = ((groups - 1) * 3) + 1;
	multiplier = malloc(sizeof(char) * key_size);
	while (i < key_size)
	{
		if (i == 0)
		{
			multiplier[i] = '1';
		}
		else
		{
			multiplier[i] = '0';
		}
		i++;
	}
	multiplier[i] = '\0';
	return (multiplier);
}

void	get_multiplier_value(int groups, int lines, char ***dictionary)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (key_is_equal(dictionary[i][0], get_search_key(groups)))
		{
			print_str (dictionary[i][1]);
			break ;
		}
		i++;
	}
}

void	print_key(char *key, char ***dictionary, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (key_is_equal(dictionary[i][0], key))
		{
			print_str(dictionary[i][1]);
			break ;
		}
		i++;
	}
}

int	last_digits_int(char decimal, char unity)
{
	int	deca;
	int	unit;

	if (decimal)
	{
		deca = decimal - '0';
		deca = deca * 10;
		unit = unity - '0';
		return (unit + deca);
	}
	else
	{
		return (unity - '0');
	}	
}
