/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:09:45 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 18:10:23 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helper_functions.h"

void	add_number_to_dict(char *str, char **dictionary_key_array, int *k)
{
	int	i;
	int	j;

	j = *k;
	i = 0;
	while (str[i] != ':')
	{
		if (is_number(str[i]))
		{
			dictionary_key_array[0][j] = str[i];
			j++;
		}
		i++;
	}
}

void	get_key(char *str, char **dictionary_key_array)
{
	int	i;
	int	counter;
	int	k;

	counter = 0;
	i = 0;
	k = 0;
	while (str[i] != ':')
	{
		if (is_number(str[i]))
			counter++;
		i++;
	}
	dictionary_key_array[0] = malloc(sizeof(char) * counter + 1);
	add_number_to_dict(str, dictionary_key_array, &k);
	dictionary_key_array[counter] = NULL;
}

void	add_str(int i, int output_idx, char *str, char **dic_val_a)
{
	while (str[i])
	{
		if (is_printable(str[i]) && str[i] != ' ')
			dic_val_a[1][output_idx++] = str[i];
		i++;
	}
	dic_val_a[1][output_idx] = '\0';
}

void	get_value(char *str, char **dic_val_a)
{
	int	i;
	int	counter;
	int	output_idx;
	int	start_idx;

	i = 0;
	counter = 0;
	output_idx = 0;
	while (str[i] != ':' && str[i] != '\0')
		i++;
	if (str[i] == ':')
		i++;
	start_idx = i;
	while (str[i])
	{
		if (is_printable(str[i]) && str[i] != ' ')
			counter++;
		i++;
	}
	dic_val_a[1] = malloc(sizeof(char) * (counter + 1));
	if (!dic_val_a[1])
		return ;
	add_str(start_idx, output_idx, str, dic_val_a);
}

void	string_validator(int lines, char **splits, char ***dictionary)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		get_key(splits[i], dictionary[i]);
		get_value(splits[i], dictionary[i]);
		i++;
	}
	free(splits);
	splits = NULL;
}
