/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:37:47 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 10:43:44 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			if (str[i] > 0)
			{
				write(1, &hexa[str[i] / 16], 1);
				write(1, &hexa[str[i] % 16], 1);
			}
			else
			{
				write(1, "0", 1);
				write(1, &hexa[str[i] % 16], 1);
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}	
}

/*int main ()
{
	char tab[]={"Coucou\ntu vas bien?"};
	ft_putstr_non_printable(tab);
	return 0;
}*/
