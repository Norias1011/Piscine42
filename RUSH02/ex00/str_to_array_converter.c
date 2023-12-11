/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_array_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:56:47 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 18:37:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helper_functions.h"

void	group_number(char *number, char ***dictionary, int lines);

char	**splits_allocator(int **ranges, int lines, char *dictionary_data)
{
	char	**splits;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	splits = malloc(sizeof(char *) * lines);
	while (i < lines)
	{
		j = k;
		while (dictionary_data[k] && dictionary_data[k] != '\n')
			k++;
		ranges[i][0] = j;
		ranges[i][1] = k;
		k++;
		i++;
	}
	return (splits);
}

void	splits_i_allo(char **splits, char *dict_data, int **ranges, int lines)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < lines)
	{
		splits[i] = malloc(sizeof(char) * 500);
		j = ranges[i][0];
		k = 0;
		while (j < ranges[i][1])
		{
			splits[i][k] = dict_data[j];
			k++;
			j++;
		}
		splits[i][k] = '\0';
		i++;
	}
}

void	data_splitter(int lines, char *dictionary_data, char ***dictionary)
{
	char	**splits;
	int		i;
	int		**ranges;

	i = 0;
	ranges = malloc(sizeof(int **) * lines);
	while (i < lines)
	{
		ranges[i] = malloc(sizeof(int) * 2);
		i++;
	}
	splits = splits_allocator(ranges, lines, dictionary_data);
	splits_i_allo(splits, dictionary_data, ranges, lines);
	free(ranges);
	string_validator(lines, splits, dictionary);
}

void	str_to_array(char *number, char *dictionary_data)
{
	char	***hash_map;
	int		lines;
	int		i;

	i = 0;
	lines = get_amount_of_lines(dictionary_data);
	hash_map = malloc(lines * sizeof(char **));
	while (i < lines)
	{
		hash_map[i] = malloc(sizeof(char *) * 2);
		i++;
	}
	data_splitter(lines, dictionary_data, hash_map);
	group_number(number, hash_map, lines);
}
