/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:32:17 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/05 13:36:03 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * (max - min) + 1);
	if (tab == NULL)
	{
		return (NULL);
	}
	i = min;
	j = 0;
	if (min >= max)
	{
		return (NULL);
	}
	while (i < max)
	{
		tab[j] = i;
		j++;
		i++;
	}
	return (tab);
}

/*int main()
{
	int	*tab = ft_range(10, 3);
	int	i = 0;
	while (tab[i] != '\0')
	{
		printf("%d, " , tab[i]);
		i++;
	}
	return (0);
}*/
