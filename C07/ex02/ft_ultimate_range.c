/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:09 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/05 13:34:58 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * (max - min) + 1);
	if (tab == NULL)
	{
		return (-1);
	}
	i = min;
	j = 0;
	while (i < max)
	{
		tab[j] = i;
		j++;
		i++;
	}
	*range = tab;
	return (j);
}

/*int main()
{
	int	*a;
	int	b = ft_ultimate_range(&a, 2, 10);
	printf("%d\n", b);
	return (0); 
}*/
