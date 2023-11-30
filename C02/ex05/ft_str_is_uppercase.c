/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:12:20 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/26 12:19:30 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (str[i] == '\0')
	{
		result = 1;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < 65 || str[i] > 90))
		{
			result = 0;
		}
		i++;
	}
	return (result);
}

/*int main()
{
	char	c[]={"HZGh"};
	int	a = ft_str_is_uppercase(c);
	printf("%d", a);
	return 0;
}*/
