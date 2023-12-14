/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:57:54 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 11:06:24 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	ft_get_len(char *argv)
{
	char	*buf;
	int		fd;
	int		len;

	len = 0;
	fd = open(argv, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * 80);
	if (buf == NULL)
		return (0);
	while (read(fd, &buf[len], 1))
	{
		if (buf[len] == '\n')
			break ;
		len++;
	}
	free(buf);
	return (len);
}

void	ft_second_line(int fd)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 5096);
	if (buf == NULL)
		return ;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			nb = nb % 10;
		}
		if (nb < 10)
		{
			ft_putchar(nb + '0');
		}
	}
}
