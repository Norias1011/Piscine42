/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:34:25 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/28 17:03:35 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] && i < (n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int main ()
{
	char	a[]="gfpam";
	char	b[]="wtuiz";
	char	d[]="gfpam";
	char	e[]="wtuiz";
	int	result = ft_strncmp(a , b, 4);
	printf("%d\n" , result);
	int	resultstr = strncmp(d, e, 4);
	printf("%d" , resultstr);
	return 0;
}*/
