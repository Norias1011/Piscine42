/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:40:40 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/23 14:40:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	c;
	int	d;

	c = a / b;
	d = a % b;
	*div = c;
	*mod = d;
}

/*int main ()
{
	int		a;
	int		b;
	int		*resultdiv;
	int		*resultmod;

	a = 10;
	b = 2;
	resultdiv = &a;
	resultmod = &b;

	printf(" a is equal %d\n", a);
	printf(" b is equal %d\n", b);
	ft_div_mod(a, b, resultdiv, resultmod);
	printf(" a divided by b = %d\n", a);
	printf(" a modulo of b = %d\n", b);
	return 0;
}*/
