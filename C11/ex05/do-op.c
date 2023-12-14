/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:04:17 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/11 17:01:28 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	calcul(int a, int b, char **argv, int *result)
{
	if (!check_zero(b, argv))
		return (-1);
	if (ft_strcmp(argv[2], "+") == 0)
		*result = (a + b);
	else if (ft_strcmp(argv[2], "-") == 0)
		*result = (a - b);
	else if (ft_strcmp(argv[2], "*") == 0)
		*result = (a * b);
	else if (ft_strcmp(argv[2], "/") == 0)
		*result = (a / b);
	else if (ft_strcmp(argv[2], "%") == 0)
		*result = (a % b);
	else
		*result = 0;
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	int	result;

	if (argc != 4)
		return (-1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (calcul(a, b, argv, &result) == -1)
		return (-1);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
