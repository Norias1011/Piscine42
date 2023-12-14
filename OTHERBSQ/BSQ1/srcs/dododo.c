/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dododo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:41:58 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 22:41:05 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checkfile.h"
#include <stdio.h>

void	dododo(int *file, unsigned int *hwccc, unsigned int *io)
{
	char	buffer[6001];
	int		byteread;

	byteread = read(*file, buffer, 6000);
	buffer[6000] = 0;
	if (check2line(buffer, io, hwccc, byteread) || !byteread)
	{
		io[1] = 4;
		return ;
	}
	checkfirstline(buffer, hwccc, io);
	io[0]++;
	if (io[1] == 1)
	{
		while (byteread > 0 && io[1] == 1)
		{
			checkrest(buffer, hwccc, io);
			io[0] = 0;
			byteread = read(*file, buffer, 6000);
			buffer[6000] = 0;
		}
	}
	if (io[2] != hwccc[0] || io[2] == 0)
		io[1] = 5;
}
