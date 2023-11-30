/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:38:58 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/30 10:34:56 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	resultat;
	int		i;

	resultat = 0;
	i = 1;
	while (resultat <= nb)
	{
		if (i < 46341)
		{
			resultat = i * i;
			if (resultat == nb)
			{
				return (i);
			}
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (0);
}

/*int main()
{
	int	a = 2147395600;
	int	result = ft_sqrt(a);
	printf("%d\n", result);
	return 0;
}*/
