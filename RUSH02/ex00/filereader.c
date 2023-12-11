/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filereader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:16:29 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/10 12:22:58 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void	str_to_array(char *number, char *dictionary_data);

void	*file_to_str(char *number, char *file)
{
	char	buff;
	char	*tab;
	int		c;
	int		i;

	i = 0;
	c = open(file, O_RDONLY);
	while (read(c, &buff, 1) > 0)
	{
		i++;
	}
	tab = malloc(sizeof(char) * (i +1));
	if (tab == NULL)
		return (NULL);
	close(c);
	c = open(file, O_RDONLY);
	i = 0;
	while (read(c, &buff, 1) > 0)
	{
		tab[i] = buff;
		i++;
	}
	close(c);
	str_to_array(number, tab);
	return (tab);
}
