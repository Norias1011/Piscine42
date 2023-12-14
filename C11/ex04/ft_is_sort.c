/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:29:19 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 16:57:31 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < length -1)
	{
		if ((*f)(tab[i], tab[i +1]) >= 0)
		{
			j++;
		}
		if ((*f)(tab[i], tab[i +1]) <= 0)
		{
			k++;
		}
		i++;
	}
	if (j == i || k == i)
	{
		return (1);
	}
	return (0);
}

/*int	test_asc(int a, int b)
{
	return (a - b);
}

int main()
{
	int	tab[] ={5, 4, 3, 2, 1};
	printf("=> %d\n", ft_is_sort(tab, 5, &test_asc));
	return (0);
}*/
