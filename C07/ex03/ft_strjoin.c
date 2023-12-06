/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:17:25 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/05 17:52:31 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[a] != '\0')
	{
		dest[i + a] = src[a];
		a++;
	}
	dest[i + a] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_argsize(int size, char **strs, char *sep)
{
	char		*c;
	int			i;
	int			lenght;

	lenght = 0;
	i = 0;
	while (i < size)
	{
		lenght = lenght + ft_strlen(strs[i]);
		i++;
	}
	lenght = lenght + ft_strlen(sep) * (size -1);
	if (size <= 0)
	{
		lenght = 1;
	}
	c = (char *)malloc(sizeof(char) * lenght);
	if (c == NULL)
		return (0);
	return (c);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;

	tab = ft_argsize(size, strs, sep);
	i = 0;
	while (i < size)
	{
		tab = ft_strcat(tab, strs[i]);
		if (i < size -1)
		{
			tab = ft_strcat(tab, sep);
		}
		i++;
	}
	return (tab);
}

/*int	main()
{
	char	*strs[3] = {"Hello", "comment", "tu vas?"};
	char	*sep = " dfhdhfghfhfghfdgdgdfgdfgdfg";

	char	*result = ft_strjoin(3, strs, "dfjhdjkfhgkshgjkhgjkfhdg");
	printf("%s\n", result);
	return (0);
}*/
