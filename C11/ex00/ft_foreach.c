/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:22:29 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/12 17:05:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_putnbr(int nb)
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
}*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

/*int main()
{
	int	tab[] = {0,1,2,3,4,5,6};
	ft_foreach(tab, 7, &ft_putnbr);
	return (0);
}*/
