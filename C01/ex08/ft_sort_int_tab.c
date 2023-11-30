/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:28:08 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/23 19:42:12 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		f;
	int		casea;

	i = 0;
	f = 0;
	while (f < size -1)
	{
		i = 0;
		while (i < size -1)
		{
			if (tab[i] > tab[i +1])
			{
				casea = tab[i +1];
				tab[i +1] = tab[i];
				tab[i] = casea;
			}
			i++;
		}
		f++;
	}
}

/*int main()
{
	int		z=0;
	int		list[100]={8,10,23,1,99,2};
	ft_sort_int_tab(list , 6);
	while (z < 6)
	{
		printf("%d, ", list[z]);
		z++;
	}
	return 0;
}*/
