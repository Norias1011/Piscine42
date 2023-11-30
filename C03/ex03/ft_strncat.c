/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:00 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/28 16:59:56 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	deslen;
	unsigned int	a;

	deslen = 0;
	a = 0;
	while (dest[deslen])
	{
		deslen++;
	}
	while (src[a] != '\0' && a < nb)
	{
		dest[deslen + a] = src[a];
		a++;
	}
	dest[deslen + a] = '\0';
	return (dest);
}

/*int main()
{
	char	a[]="Hello";
	char	b[]="worlHello";
	char	d[]="Hello";
	char	e[]="worlHello";

	ft_strncat(a, b, 5);
	printf("%s\n", a);
	char	*result = strncat(d, e, 5);
	printf("%s\n", result);
	return 0;
}*/
