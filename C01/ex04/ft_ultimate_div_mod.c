/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:12:00 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/23 14:50:22 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;
	int	d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}

/*int main()
{
	int		e;
	int		f;

	e = 40;
	f = 3;
	printf("e is equal to %d\n", e);
	printf("f is equal to %d\n", f);
	ft_ultimate_div_mod(&e, &f);
	printf("e divided by f = %d\n", e);
	printf("e modulo f = %d\n", f);
	return 0;
}*/
