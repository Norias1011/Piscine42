/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:32:09 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 13:51:15 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_firstletter(char *str, int i)
{
	if (str[i] >= 97 && str[i] <= 122)
	{	
		if (str[i -1] < 97 || str[i -1] > 122)
		{
			if (str[i -1] < 65 || str[i -1] > 90)
			{	
				if (str[i -1] < 48 || str[i -1] > 57)
				{	
					str[i] = str[i] - 32;
				}
			}
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{	
			str[i] = str[i] + 32;
		}
		ft_firstletter(str, i);
		i++;
	}
	return (str);
}

/*int main ()
{
	char	c[]={"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un"};
	ft_strcapitalize(c);
	printf("%s", c);

	return 0;
}*/
