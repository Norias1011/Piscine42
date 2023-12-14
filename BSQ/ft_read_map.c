/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:23:09 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 12:39:52 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	ft_size_file(char *argv)
{
	char	buf;
	int		fd;
	int		size;

	size = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		size++;
	}
	close(fd);
	return (size);
}

int	ft_number_lines(char *argv)
{
	char	*buf;
	int		nb_l;
	int		fd;
	int		len;
	int		i;

	len = ft_get_len(argv);
	i = 0;
	nb_l = 0;
	fd = open(argv, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 80);
	close(fd);
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf[i], 1))
	{
		if ((buf[i] > 58 || buf[i] < 47) || i == len - 3)
			break ;
		nb_l = nb_l * 10 + (buf[i] - 48);
		i++;
	}
	free(buf);
	close(fd);
	return (nb_l);
}

int	ft_number_columns(char *argv)
{
	char	*buf;
	int		j;
	int		size_file;
	int		fd;

	j = 0;
	fd = open(argv, O_RDONLY);
	size_file = ft_size_file(argv);
	ft_second_line(fd);
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
	close(fd);
	return (j + 1);
}

int	check_buf(char *argv)
{
	char	**buf;
	int		i;
	int		fd;
	int		c;
	int		l;

	i = 0;
	c = ft_number_columns(argv);
	l = ft_number_lines(argv);
	fd = open(argv, O_RDONLY);
	ft_second_line(fd);
	buf = (char **)malloc(sizeof(char *) * l);
	if (buf == NULL)
		return (0);
	while (i < l)
	{
		buf[i] = (char *)malloc(sizeof(char) * c);
		if (buf[i] == NULL)
			return (0);
		i++;
	}
	free(buf);
	return (1);
}

char	**ft_read_file(char *argv)
{
	char	**buf;
	int		i;
	int		fd;
	int		c;
	int		l;

	i = 0;
	c = ft_number_columns(argv);
	l = ft_number_lines(argv);
	fd = open(argv, O_RDONLY);
	ft_second_line(fd);
	buf = (char **)malloc(sizeof(char *) * l);
	while (i < l)
	{
		buf[i] = (char *)malloc(sizeof(char) * c);
		if (((read(fd, buf[i], c)) == -1 || 0) || check_buf(argv) == 0)
			return (NULL);
		buf[i][c - 1] = '\0';
		i++;
	}
	close(fd);
	return (buf);
}
