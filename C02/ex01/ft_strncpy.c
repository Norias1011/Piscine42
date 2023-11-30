/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:14:17 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 17:02:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int main ()
{
	char	c[]="123456789";
	char	d[]="abcdefg";
	char	e[]="123456789";
	char	f[]="abcdefg";
	
	ft_strncpy(d , c, 5);
	printf("%s\n" , d);
	char	*g =strncpy(f, e, 5);
	printf("%s\n", g);
	return 0;
}*/
