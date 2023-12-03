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
/* this function is to initialize our matrix with only zeros in it. We travel in our matrix to put 0 in every block */
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
/* we travel in our matrix using a division by 4 for the columns of the matrix. */
	while (i < gap / 4)
	{
		/* we test if the value of num is already in the matrix */
		if (matrix[i][gap % 4] == num)
		{
			return (1);
		}
		i++;
	}
	i = 0;
	/* then we check for every rows of the matrix */
	while (i < gap % 4)
	{
		/* we test if the value of num is already in the matrix */
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
/* we use a gap variables to travel in our matrix and fill it with numbers. the condition below says that if we filled all the cases it means the matrix is solved. We use a recursive in this functions that is why this conditions is a the top */
	if (gap == 16)
		return (1);
	num = 0;
	while (num++ <= 4)
	{
/* we check if num is already in our matrix */
		if (check_next_cell(matrix, gap, num) == 0)
		{
/* if the previous function return 0 it means the value of num is not in the matrix. so we put the value of num in the matrix */
			matrix[gap / 4][gap % 4] = num;
/* we check if the new num if correct by using a new function that check if the number is correct according the the pattern (so arguments that were given). */
			if (check_cell(matrix, gap, pattern) == 0)
			{
/* if the number is good we go to the next cell */
				if (puzzle(matrix, pattern, gap +1) == 1)
					return (1);
			}
/* if the number is not good we remove it by putting a 0 */
			else
				matrix[gap / 4][gap % 4] = 0;
		}
	}
/* if there is no solution we return 0 so it means there is an error and the puzzle can't be solved */
	return (0);
}

int	main(int argc, char *argv[])
{
// Here we create a double strings were we are going to put our numbers
	int	matrix[4][4];
	int	*pattern;
// Here we are initiazing how double strings with only 0
	matrixinit(matrix);
/* here we check if the arguments given are correct or not. In our case it need to be a certain size, only numbers
only one arguments etc. The functions return 1 if they found an issue. if they return 1 it will be an error so we print
an error message and we end the program */
	if (check_argument(argc, argv) == 1 || check_argument2(argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
/* we take the arguments that we received and we put them in a string so we can exploit them */
	pattern = argumentconvert(argv[1]);
/* if the string pattern is empty we return 1 which in C it's always a sign of something is wrong */
	if (!pattern)
		return (1);
/* if we succeed in solving the puzzle we print the number put in our matrix and show it to the user */
	if (puzzle(matrix, pattern, 0) == 1)
		print_puzzle(matrix);
/* otherwise if we cannot find any solution we print an error message */
	else
		write(1, "Error\n", 6);
	return (0);
}
