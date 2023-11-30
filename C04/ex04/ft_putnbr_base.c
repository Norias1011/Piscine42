/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:36:34 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/29 18:46:18 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb, int sizebase, char *base)
{
	long	d;

	d = nb;
	if (d < 0)
	{	
		write(1, "-", 1);
		d = d * -1;
	}	
	if (d >= sizebase)
	{
		ft_putnbr(d / sizebase, sizebase, base);
		d = d % sizebase;
	}
	if (d < sizebase)
	{
		write(1, &base[d], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;
	int	sizebase;

	i = 0;
	j = 0;
	sizebase = ft_strlen(base);
	if (sizebase < 2)
	{
		return ;
	}
	while (i < sizebase)
	{
		j = i +1;
		while (j < sizebase)
		{
			if (base[i] == base[j])
			{
				return ;
			}
			j++;
		}
		i++;
	}
	ft_putnbr(nbr, sizebase, base);
}

/*int main()
{
	int	a =-3;
	char	*c= "012";
	ft_putnbr_base(a, c);
	return 0;
}*/
