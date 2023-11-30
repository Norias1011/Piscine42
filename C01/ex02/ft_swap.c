/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:59:00 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/23 13:53:15 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *b;
	*b = *a;
	*a = x;
}

/*int main()
{
	int		c;
	int		d;

	c = 10;
	d = 20;
	printf("La lettre c = %d\n", c);
	printf("la lettre d = %d\n", d);
	ft_swap(&c , &d);
	printf("Maintenant la lettre c = %d\n", c);
	printf("Et maintenant la lettre d = %d\n", d);
	return 0;
}*/
