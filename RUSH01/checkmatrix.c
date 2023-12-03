/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:44:24 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/03 14:20:14 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	check_col_up(int matrix[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (gap / 4 == 3)
	{
		while (i < 4)
		{
			if (matrix[i][gap % 4] > max)
			{
				max = matrix[i][gap % 4];
				count++;
			}
			i++;
		}
		if (pattern[gap % 4] != count)
		{
			return (1);
		}
	}
	return (0);
}

int	check_col_down(int matrix[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
/* we check if we are at the good column */
	if (gap / 4 == 3)
	{
/* we start at i = 3 to go from bottom to top */
		while (i >= 0)
		{
/* we set the max number of each cell of the column and count */
			if (matrix[i][gap % 4] > max)
			{
/* we chqnge the max value with the new number */
				max = matrix[i][gap % 4];
				count++;
			}
			i--;
		}
/* compare if the result is as expected */
		if (pattern[4 + gap % 4] != count)
		{
			return (1);
		}
	}
	return (0);
}

int	check_row_right(int matrix[4][4], int gap, int pattern[16])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
/* check if the current gap is at the right row */
	if (gap % 4 == 3)
	{
/* we start at i = 4 to go from right to left */
		while (i-- >= 0)
		{
/* for each cell of the row we set up the max value and we count */
			if (matrix[gap / 4][i] > max_size)
			{
/* we change the max value with the new number */
				max_size = matrix[gap / 4][i];
				visible_towers++;
			}
		}
/* we compare the result is as expected */ 
		if (pattern[12 + gap / 4] != visible_towers)
		{
			return (1);
		}
	}
	return (0);
}

int	check_row_left(int matrix[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
/* we add all the numbers in our matrix, we check here if we are at the good row */
	if (gap % 4 == 3)
	{
/* we start with i = 0 to go from left to right */
		while (i < 4)
		{
/* we check for every row if the num if the matrix if above the max value */
			if (matrix[gap / 4][i] > max)
			{
/* if yes we change the max value and then we compare with every numbers*/
				max = matrix[gap / 4][i];
				count++;
			}
			i++;
		}
/* we compare if the result is as expected */
		if (pattern[8 + gap / 4] != count)
		{
			return (1);
		}
	}
	return (0);
}

int	check_cell(int matrix[4][4], int gap, int pattern[16])
{
/* we test all the posibilities to see if the num can fit in the matrix */
	if (check_row_left(matrix, gap, pattern) == 1)
	{
		return (1);
	}
	if (check_row_right(matrix, gap, pattern) == 1)
	{
		return (1);
	}
	if (check_col_down(matrix, gap, pattern) == 1)
	{
		return (1);
	}
	if (check_col_up(matrix, gap, pattern) == 1)
	{
		return (1);
	}
	return (0);
}
