/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:01:29 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/26 12:14:05 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_lowercase(char *str)
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
		if ((str[i] < 97 || str[i] > 122))
		{
			result = 0;
		}
		i++;
	}
	return (result);
}

/*int main()
{
	char	c[]={"e8llo"};
	int	a = ft_str_is_lowercase(c);
	printf("%d", a);
	return 0;
}*/
