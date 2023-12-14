/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:14:26 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/12 17:07:51 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*newtab;

	i = 0;
	newtab = malloc(sizeof(int) * length);
	if (newtab == NULL)
	{
		return (NULL);
	}
	while (i < length)
	{
		newtab[i] = (*f)(tab[i]);
		i++;
	}
	return (newtab);
}

/*int	main()
{
	int	tab[]={0,1,2,3,4,5,6};
	int	i = 0;
	int	*new = ft_map(tab, 7, &ft_putnbr);
	while (new[i] != '\0')
	{
		printf("%d\n", new[i]);
		i++;
	}
	return (0);
}*/
