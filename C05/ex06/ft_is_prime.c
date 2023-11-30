/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:16:28 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/30 14:03:23 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	compt;

	i = 2;
	compt = 0;
	if (nb < 2)
	{
		return (0);
	}
	if (nb == i)
	{
		return (1);
	}
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			compt++;
		}
		i++;
	}
	if (compt == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int main()
{
	int	a = 97;
	int result = ft_is_prime(a);

	printf("%d\n", result);
	return 0;
}*/
