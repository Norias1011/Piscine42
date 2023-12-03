/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:38:02 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/03 16:46:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

int	check_argument2(char *str)
{
	int		i;
	int		space;
	int		ic;
/* in this function we check if we have numbers and space only and the arguments need to respect a certain size with a certain amount of space and numbers */
	i = 0;
	space = 0;
	ic = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
			return (1);
		else if (str[i] >= 48 && str[i] <= 57)
		{
			ic = ic + 1;
			if (str[i + 1] == 32)
				space++;
		}
		i++;
	}
	if (ic != (space +1))
		return (1);
	return (0);
}

int	check_argument(int argc, char *argv[])
{
/* we check if the arguments that we receive. if we receive more than 2 it means there is an error. if we do not have 31 characters it's an error */
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) != 31)
		return (1);
	return (0);
}

/* the function below help us to gather all the argument in one string without the space so we can exploit them */
int	*argumentconvert(char *str)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * 16);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
/* below is the tips to print int number in char number */
			tab[j++] = str[i] - '0';
		}
		i++;
	}
	return (tab);
}

/* this function print on the screen */
void	print_puzzle(int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
/* here we print the numbers in the matrix */
			ft_putnbr(matrix[i][j]);
			if (j < 3)
			{
/* and between every numbers we print a space to show numbers as it is requested */
				write(1, " ", 1);
			}
			j++;
		}
/* to print numbers from one row to another one we print a tab in order to print the new line */
		write(1, "\n", 1);
		i++;
	}
}
