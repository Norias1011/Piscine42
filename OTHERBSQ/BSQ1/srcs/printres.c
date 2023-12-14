/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printres.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:27:52 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 22:01:26 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	mygetchar(char *c, unsigned int *ij, unsigned int *hwccc,
			unsigned int *result);

void	printres(char *path, unsigned int *hwccc, unsigned int *result)
{
	unsigned int	ij[2];
	int				file;
	char			c;
	char			*buffer;

	file = open(path, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * (hwccc[1] + 1));
	while (read(file, &c, sizeof(char)) > 0 && c != '\n')
		;
	ij[0] = 0;
	while (ij[0] < hwccc[0])
	{
		ij[1] = 0;
		read(file, buffer, (hwccc[1] + 1));
		while (ij[1] < hwccc[1])
		{
			mygetchar(&buffer[ij[1]], ij, hwccc, result);
			write(1, &buffer[ij[1]], 1);
			ij[1]++;
		}
		write(1, "\n", 1);
		ij[0]++;
	}
	close(file);
	free(buffer);
}

void	mygetchar(char *c, unsigned int *ij, unsigned int *hwccc,
				unsigned int *result)
{
	if (*c == (char)hwccc[3])
		;
	else if (ij[0] <= result[1] && result[1] < ij[0] + result[0]
		&& ij[1] <= result[2] && result[2] < ij[1] + result[0])
		*c = (char)hwccc[4];
	else
		*c = (char)hwccc[2];
}
