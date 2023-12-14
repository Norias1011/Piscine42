/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:33:57 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 10:56:13 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	ft_check_char(char *argv)
{
	char	*buf;
	char	v;
	char	o;
	int		fd;
	int		size_file;

	v = ft_char_void(argv);
	o = ft_char_obst(argv);
	size_file = ft_size_file(argv);
	fd = open(argv, O_RDONLY);
	ft_second_line(fd);
	buf = (char *)malloc(sizeof(char) * size_file);
	while (read(fd, buf, size_file != 0))
		buf[0] = '\0';
	size_file = 0;
	while (buf[size_file])
	{
		if ((buf[size_file] != v && buf[size_file] != o)
			&& buf[size_file] != '\n')
			return (1);
		size_file++;
	}
	close(fd);
	free(buf);
	return (0);
}

int	ft_next_columns(char *argv, int fd)
{
	char	*buf;
	int		j;
	int		size_file;

	j = 0;
	size_file = ft_size_file(argv);
	buf = (char *)malloc(sizeof(char) * size_file);
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free(buf);
	return (j + 1);
}

int	ft_check_columns(char *argv)
{
	int	i;
	int	fd;
	int	j;
	int	c;
	int	l;

	i = 0;
	j = 0;
	c = ft_number_columns(argv);
	l = ft_number_lines(argv);
	fd = open(argv, O_RDONLY);
	ft_second_line(fd);
	while (i < l)
	{
		j = ft_next_columns(argv, fd);
		if (j != c)
			return (1);
		i++;
	}
	close(fd);
	return (0);
}

int	ft_check_returns(char *argv)
{
	char	*buf;
	int		fd;
	int		size_file;
	int		c;

	c = ft_number_columns(argv);
	size_file = ft_size_file(argv);
	fd = open(argv, O_RDONLY);
	ft_second_line(fd);
	buf = (char *)malloc(sizeof(char) * size_file);
	if (buf == NULL)
		return (0);
	while (read(fd, buf, c) == 0)
	{
		if (buf[-1] != '\n')
			return (1);
	}
	free(buf);
	close(fd);
	return (0);
}

int	ft_check_map(char *argv)
{
	if (open(argv, O_RDONLY) < 0)
	{
		ft_putstr("file error\n");
		return (1);
	}
	if (ft_number_columns(argv) < 1 || ft_number_lines(argv) < 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if (ft_check_char(argv) == 1 || ft_check_returns(argv) == 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	if (ft_check_columns(argv) == 1)
	{
		ft_putstr("map error\n");
		return (1);
	}
	return (0);
}
