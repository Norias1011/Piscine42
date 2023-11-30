/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:12:16 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/30 09:45:22 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	fact;

	fact = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		fact = 1;
	}
	else
	{
		fact = ft_recursive_factorial(nb -1) * nb;
	}
	return (fact);
}

/*int main()
{
	int	a = 1;
	int	b = ft_recursive_factorial(a);
	printf("%d\n", b);
	return 0;
}*/
