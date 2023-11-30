/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:59:32 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/23 16:20:23 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		start;
	int		end;

	start = 0;
	end = size -1;
	while (start < end)
	{
		i = tab[start];
		tab[start] = tab[end];
		tab[end] = i;
		start++;
		end--;
	}
}

/*int main ()
{
	int		b=0;
	int		tabsize=10;
	int		a[11]={0,1,2,3,4,5,6,7,8,9};
	ft_rev_int_tab(a , 10);
	while (b < tabsize)
	{
		printf("%d, " , a[b]);
		b++;
	}
	return 0;
}*/
