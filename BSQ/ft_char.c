/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:32:26 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 11:41:15 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	ft_char_void(char *argv)
{
	char	*buf;
	char	v;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 80);
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	v = buf[i - 3];
	free(buf);
	close(fd);
	return (v);
}

char	ft_char_obst(char *argv)
{
	char	*buf;
	char	o;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 80);
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	o = buf[i - 2];
	free(buf);
	close(fd);
	return (o);
}

char	ft_char_full(char *argv)
{
	char	*buf;
	char	p;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 80);
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	p = buf[i - 1];
	free(buf);
	close(fd);
	return (p);
}
