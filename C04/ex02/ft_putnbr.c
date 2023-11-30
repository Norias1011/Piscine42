/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:58:16 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/29 18:45:58 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

/*int main()
{
	int	a = -10;
	ft_putnbr(a);
	return 0;
}*/
