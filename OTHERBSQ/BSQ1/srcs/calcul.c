/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:26:51 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 22:56:06 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "calcultools.h"
#include <stdio.h>

void	calcul_2(char *path, unsigned int *hwccc,
			unsigned int **cal_table, unsigned int *result);
void	dorest(int *file, unsigned int **cal_table,
			unsigned int **ptr2, unsigned int *result);
void	dorest_2(char *buffer, unsigned int *ij,
			unsigned int **cal_table, unsigned int **ptr2);

void	calcul(char *path, unsigned int *hwccc,
			unsigned int *result, unsigned int W)
{
	unsigned int	*cal_table[2];
	unsigned int	cal_table1[W];
	unsigned int	cal_table2[W];

	cal_table[0] = cal_table1;
	cal_table[1] = cal_table2;
	calcul_2(path, hwccc, cal_table, result);
}

void	calcul_2(char *path, unsigned int *hwccc,
		unsigned int **cal_table, unsigned int *result)
{
	unsigned int	ij[2];
	int				file;
	unsigned int	*ptr2[2];
	char			*buffer;
	char			c;

	file = open(path, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * (hwccc[1] + 1));
	while (read(file, &c, sizeof(char)) > 0 && c != '\n')
		;
	initvals(ij, result);
	read(file, buffer, (hwccc[1] + 1));
	while (ij[1] < hwccc[1])
	{
		cal_table[0][ij[1]] = (buffer[ij[1]] == (char)hwccc[2]);
		if (cal_table[0][ij[1]] > result[0])
			getmax(result, cal_table[0][ij[1]], ij);
		ij[1]++;
	}
	ptr2[0] = result;
	ptr2[1] = hwccc;
	dorest(&file, cal_table, ptr2, result);
	free(buffer);
}

void	dorest(int *file, unsigned int **cal_table,
		unsigned int **ptr2, unsigned int *result)
{
	unsigned int	ij[2];
	unsigned int	*temp;
	char			*buffer;

	ij[0] = 1;
	buffer = (char *)malloc(sizeof(char) * (ptr2[1][1] + 1));
	while (ij[0] < ptr2[1][0])
	{
		ij[1] = 0;
		read(*file, buffer, (ptr2[1][1] + 1));
		while (ij[1] < ptr2[1][1])
			dorest_2(buffer, ij, cal_table, ptr2);
		temp = cal_table[0];
		cal_table[0] = cal_table[1];
		cal_table[1] = temp;
		ij[0]++;
	}
	free(buffer);
	result = ptr2[0];
}

void	dorest_2(char *buffer, unsigned int *ij,
		unsigned int **cal_table, unsigned int **ptr2)
{
	if (ij[1] == 0)
		cal_table[1][ij[1]] = (buffer[ij[1]] == (char)ptr2[1][2]);
	else if (buffer[ij[1]] == (char)ptr2[1][2])
		cal_table[1][ij[1]] = 1 + min(cal_table[0][ij[1]],
				cal_table[1][ij[1] - 1], cal_table[0][ij[1] - 1]);
	else
		cal_table[1][ij[1]] = 0;
	if (cal_table[1][ij[1]] > (unsigned int)ptr2[0][0])
		getmax(ptr2[0], cal_table[1][ij[1]], ij);
	ij[1]++;
}
