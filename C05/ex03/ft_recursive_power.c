/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:03 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/30 09:51:50 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (ft_recursive_power(nb, power -1) * nb);
	}
}

/*int main()
{
	int	a = 5;
	int	b = 3;
	int	resultat = ft_recursive_power(a, b);
	printf("%d\n" , resultat);
	return 0;
}*/
