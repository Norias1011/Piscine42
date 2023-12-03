/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:31:45 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/03 16:45:42 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		check_argument(int argc, char *argv[]);
int		check_argument2(char *str);
int		*argumentconvert(char *str);
void	print_puzzle(int matrix[4][4]);
int		check_cell(int matrix[4][4], int gap, int pattern[16]);

void	matrixinit(int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	check_next_cell(int matrix[4][4], int gap, int num)
{
	int	i;

	i = 0;
	while (i < gap / 4)
	{
		if (matrix[i][gap % 4] == num)
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < gap % 4)
	{
		if (matrix[gap / 4][i] == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	puzzle(int matrix[4][4], int pattern[16], int gap)
{
	int	num;

	if (gap == 16)
		return (1);
	num = 0;
	while (num++ <= 4)
	{
		if (check_next_cell(matrix, gap, num) == 0)
		{
			matrix[gap / 4][gap % 4] = num;
			if (check_cell(matrix, gap, pattern) == 0)
			{
				if (puzzle(matrix, pattern, gap +1) == 1)
					return (1);
			}
			else
				matrix[gap / 4][gap % 4] = 0;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	matrix[4][4];
	int	*pattern;

	matrixinit(matrix);
	if (check_argument(argc, argv) == 1 || check_argument2(argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pattern = argumentconvert(argv[1]);
	if (!pattern)
		return (1);
	if (puzzle(matrix, pattern, 0) == 1)
		print_puzzle(matrix);
	else
		write(1, "Error\n", 6);
	return (0);
}
