/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:31:32 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/26 11:43:37 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_numeric(char *str)
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
		if ((str[i] < 48 || str[i] > 57))
		{
			result = 0;
		}
		i++;
	}
	return (result);
}

/*int main()
{
	char	c[]={0};
	int	a = ft_str_is_numeric(c);
	printf("%d", a);
	return 0;
}*/
