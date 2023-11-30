/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:55:27 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/28 12:39:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	translatec(char *str, int *number)
{
	while (*str >= 48 && *str <= 57)
	{
		*number = *number * 10;
		*number = *number + *str - 48;
		str++;
	}
	return (*number);
}

int	ft_atoi(char *str)
{
	int	parity;
	int	number;

	parity = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
	{	
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			parity++;
		}
		str++;
	}
	translatec(str, &number);
	if (!(parity % 2))
	{	
		return (number);
	}
	return (-number);
}	

/*int main()
{
	char	c[]=" ---+--+1234ab567";
	int	a = ft_atoi(c);
	printf("%d\n", a);
	return 0;
}*/
