/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:24 by akinzeli          #+#    #+#             */
/*   Updated: 2023/11/30 17:49:30 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] != '\0')
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_putchar(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar2(argv[i][j]);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ft_sort_params(int size, char *tab[])
{
	int		i;
	int		j;
	char	*argv;

	i = 1;
	while (i < size)
	{
		j = i;
		while (ft_strcmp(tab[j], tab[j -1]) < 0 && j > 1)
		{
			argv = tab[j -1];
			tab[j -1] = tab[j];
			tab[j] = argv;
			j--;
		}
		i++;
	}
	ft_putchar(size, tab);
}

int	main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	return (0);
}
