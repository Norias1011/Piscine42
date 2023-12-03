/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:50:10 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/03 14:19:19 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* theses function are standard one that we saw since the beginning of the piscine with the first one that give the size of a string, the second one that write characters and the last one that help us to write numbers from an int */ 
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
	{
		nbr = nb;
	}
	if (nbr / 10 != 0)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + 48);
}
