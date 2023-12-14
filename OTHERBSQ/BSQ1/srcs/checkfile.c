/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:51:57 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 22:57:33 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		check2line(char *c,
			unsigned int *io, unsigned int *hwccc, int byteread);
void	checkfirstline(char *buffer, unsigned int *hwccc,
			unsigned int *io);
void	checkrest(char *buffer, unsigned int *hwccc, unsigned int *io);
void	gethatoi(char *buffer, unsigned int *hwccc,
			unsigned int *io);
void	dododo(int *file, unsigned int *hwccc, unsigned int *io);

int	checkfile(char *path, unsigned int *hwccc)
{
	int				file;
	unsigned int	io[4];

	file = open(path, O_RDONLY);
	if (file < 0)
		return (6);
	io[0] = 0;
	io[1] = 1;
	io[2] = 0;
	io[3] = 0;
	dododo(&file, hwccc, io);
	close(file);
	return (io[1]);
}

int	check2line(char *buffer,
			unsigned int *io, unsigned int *hwccc, int byteread)
{
	int	nlcnt;

	nlcnt = 0;
	io[0] = 0;
	while ((int)io[0] < byteread && buffer[io[0]] != '\n')
		io[0]++;
	nlcnt++;
	hwccc[0] = io[0]++;
	while ((int)io[0] < byteread && buffer[io[0]] != '\n')
		io[0]++;
	if (buffer[io[0]] == '\n')
		nlcnt++;
	hwccc[1] = io[0] - hwccc[0] - 1;
	return (nlcnt != 2);
}

void	checkfirstline(char *buffer, unsigned int *hwccc,
			unsigned int *io)
{
	int	j;

	j = 0;
	io[0] = 0;
	hwccc[3] = 0;
	if (hwccc[0] < 4)
	{
		io[1] = 7;
		return ;
	}
	gethatoi(buffer, hwccc, io);
	hwccc[0] = hwccc[3];
	while (j < 3)
		hwccc[(j++) + 2] = buffer[io[0]++];
	if (hwccc[2] == hwccc[3] || hwccc[2] == hwccc[4] || hwccc[3] == hwccc[4])
		io[1] = 8;
}

void	gethatoi(char *buffer, unsigned int *hwccc,
			unsigned int *io)
{
	while (io[0] < hwccc[0] - 3)
	{
		if ('0' <= buffer[io[0]] && buffer[io[0]] <= '9')
			hwccc[3] = hwccc[3] * 10 + (buffer[io[0]] - '0');
		else
		{
			io[1] = 9;
			return ;
		}
		io[0]++;
	}
}

void	checkrest(char *buffer, unsigned int *hwccc, unsigned int *io)
{
	while (io[2] < hwccc[0] && io[1] == 1 && buffer[io[0]])
	{
		if (buffer[io[0]] == '\n')
		{
			if (io[3] != hwccc[1] || !io[3])
			{
				io[1] = 3;
			}
			io[3] = 0;
			io[2]++;
			io[0]++;
		}
		else if (buffer[io[0]] != (char)hwccc[2]
			&& buffer[io[0]] != (char)hwccc[3])
			io[1] = 4;
		else
		{
			io[3]++;
			io[0]++;
		}
	}
}
/*
  int	main()
  {
  printf("%d\n", checkfile("../test/test5.map"));
  }
*/
