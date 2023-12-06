/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:15:35 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/05 17:57:46 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	write(1, str, i);
}

void	ft_putnbr(int nb)
{
	int	c;
	int	d;

	d = nb;
	if (d == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (d < 0)
		{
			write(1, "-", 1);
			d = d * -1;
		}
		if (d >= 10)
		{
			ft_putnbr(d / 10);
			d = d % 10;
		}
		if (d < 10)
		{
			c = d + '0';
			write(1, &c, 1);
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

/*int main()
{
	char	*av[4] = {"Hello", "comment", "tu vas", "aujourd'hui?"};
	ft_show_tab(ft_strs_to_tab(4, av));
	return (0);
}*/
