/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:29:49 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 17:06:18 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if ((str[i] < 32 || str[i] > 126))
		{
			result = 0;
		}
		i++;
	}
	return (result);
}

/*int main()
{
	char	c[]={};
	int	a = ft_str_is_printable(c);
	printf("%d", a);
	return 0;
}*/
