/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:08:23 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/12 15:37:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*box;

	i = 0;
	j = 0;
	while (i == 0)
	{
		i = 1;
		j = 0;
		while (tab[j +1])
		{
			if (ft_strcmp(tab[j], tab[j +1]) > 0)
			{
				i = 0;
				box = tab[j];
				tab[j] = tab[j +1];
				tab[j +1] = box;
			}
			j++;
		}
	}
}

/*int	main()
{
	char	*c[5] = {"fdgdhg", "aausudjs", "aasudsufudf", "bbddfr"};
	int	i = 0;
	ft_sort_string_tab(c);
	while (i < 4)
	{
		printf("%s\n" , c[i]);
		i++;
	}
	return (0);
}*/
