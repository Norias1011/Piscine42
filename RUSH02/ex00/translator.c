/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:43:13 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 12:05:20 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "helper_functions.h"
#include <stdio.h>

void	hundred_translator(char *numbers, char ***dictionary, int lines)
{
	char	place_holder[4];
	int		last_digits;
	char	cero_key[2];

	last_digits = last_digits_int(numbers[1], numbers[2]);
	set_p_hold(place_holder);
	cero_key[0] = numbers[0];
	cero_key[1] = '\0';
	if (numbers[0] != '0' && numbers[0] != '\0')
		s_init_h(cero_key, dictionary, lines, place_holder);
	if (last_digits >= 1 && last_digits <= 9)
		prt_one_nine(place_holder, numbers, dictionary, lines);
	else if (last_digits >= 10 && last_digits <= 19)
		prt_ten_nineteen(place_holder, numbers, dictionary, lines);
	else if (last_digits >= 20 && last_digits <= 99)
		prt_twenty_ninety(place_holder, numbers, dictionary, lines);
}

void	translator(char **numbers, char ***dic, int n_groups, int lines)
{
	int	k;
	int	i;

	k = n_groups - 1;
	i = n_groups;
	if (is_zero(n_groups, numbers))
		cero_handler(dic, lines);
	else
	{
		while (i > 0)
		{
			hundred_translator(numbers[k], dic, lines);
			if (i != 1)
				get_multiplier_value(i, lines, dic);
			i--;
			k--;
		}
	}
}

void	iterate_group_number(char *number, char **groups, int ng)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	k = arr_len(number);
	while (i < ng)
	{
		j = 2;
		while (j >= 0 && k >= 0)
		{
			if (is_digit(number[k - 1]))
			{
				groups[i][j] = number[k - 1];
			}
			j--;
			k--;
		}
		i++;
	}
}

void	array_by_three(char *number, int ng, char ***dic, int lines)
{
	char	**groups;
	int		i;

	i = 0;
	groups = malloc(sizeof(char *) * ng);
	while (i < ng)
	{
		groups[i] = malloc(sizeof(char) * 3);
		i++;
	}
	iterate_group_number(number, groups, ng);
	translator(groups, dic, ng, lines);
}

void	group_number(char *number, char ***dictionary, int lines)
{
	int		groups;
	int		mod;

	mod = arr_len(number) % 3;
	groups = arr_len(number) / 3;
	if (mod > 0)
		groups++;
	array_by_three(number, groups, dictionary, lines);
}
