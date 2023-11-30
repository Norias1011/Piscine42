/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:10:05 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/27 14:22:39 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size)
		{
			dest[i] = src[i];
		}
		i++;
	}
	dest[i] = '\0';
	return (size);
}

/*int main ()
{
	char	c[]="Hello";
	char	d[]="ciaodgff";
	ft_strlcpy(d , c, 5);
	printf("%s\n" , d);
	
	return 0;
}*/
