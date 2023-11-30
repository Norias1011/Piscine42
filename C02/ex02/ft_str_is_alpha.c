/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:36:04 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/26 11:16:04 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	if (str[i] == '\0')
	{
		result = 1;
	}
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			result = 0;
		}
		i++;
	}
	return (result);
}

/*int main ()
{
	char	c[]={"123df5456"};
	int	a = ft_str_is_alpha(c);
	printf("%d", a);
	return 0;
}*/
