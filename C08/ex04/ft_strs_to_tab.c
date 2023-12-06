/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:17:25 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:36 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*charinfo;
	int			i;

	charinfo = malloc(sizeof(t_stock_str) * (ac +1));
	if (charinfo == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		charinfo[i].size = ft_strlen(av[i]);
		charinfo[i].str = malloc(sizeof(int) * charinfo[i].size +1);
		if (charinfo[i].str == NULL)
			return (NULL);
		charinfo[i].str = ft_strcpy(charinfo[i].str, av[i]);
		charinfo[i].copy = malloc(sizeof(int) * charinfo[i].size +1);
		if (charinfo[i].copy == NULL)
			return (NULL);
		charinfo[i].copy = ft_strcpy(charinfo[i].copy, charinfo[i].str);
		i++;
	}
	charinfo[i].str = 0;
	return (charinfo);
}
