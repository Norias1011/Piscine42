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
	if (gap / 4 == 3)
	{
		while (i >= 0)
		{
			if (matrix[i][gap % 4] > max)
			{
				max = matrix[i][gap % 4];
				count++;
			}
			i--;
		}
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
	if (gap % 4 == 3)
	{
		while (i-- >= 0)
		{
			if (matrix[gap / 4][i] > max_size)
			{
				max_size = matrix[gap / 4][i];
				visible_towers++;
			}
		}
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
	if (gap % 4 == 3)
	{
		while (i < 4)
		{
			if (matrix[gap / 4][i] > max)
			{
				max = matrix[gap / 4][i];
				count++;
			}
			i++;
		}
		if (pattern[8 + gap / 4] != count)
		{
			return (1);
		}
	}
	return (0);
}

int	check_cell(int matrix[4][4], int gap, int pattern[16])
{
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
