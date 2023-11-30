/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:59:05 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 14:56:56 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	a;
	int	sizedest;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	sizedest = i;
	while (src[a] != '\0')
	{
		dest[sizedest + a] = src[a];
		a++;
	}
	dest[sizedest + a] = '\0';
	return (dest);
}

/*int main()
{
	char	a[]="Hello";
	char	b[]="Anthony";
//	char	c[]="Hello";
//	char	d[]="Anthony";
	ft_strcat(a, b);
	printf("%s\n" , a);
	char	*str = strcat(c , d);
	printf("%s\n" , str);
	return 0;
}*/
