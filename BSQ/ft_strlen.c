/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:08:57 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 10:11:29 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "BSQ.h"

int	ft_strlen(char *str)
{
	char	c;
	int		x;

	x = 0;
	c = str[x];
	while (c != '\0')
	{
		x++;
		c = str[x];
	}
	return (x);
}

char	*read_input(char *path)
{
	char	buffer;
	int		fd;

	fd = open(path, O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		return (NULL);
	while (read(0, &buffer, 1) > 0)
		write(fd, &buffer, 1);
	close(fd);
	return (path);
}
