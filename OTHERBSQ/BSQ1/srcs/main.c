/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:36:12 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 23:08:53 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkfile.h"
#include "readinput.h"
#include "printres.h"
#include "calcul.h"
#include "calculsml.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	excute(char *path);
void	excutewithinput(void);

int	main(int ac, char *av[])
{
	int		i;

	if (ac == 1)
		excutewithinput();
	else
	{
		i = 1;
		while (i < ac)
		{
			excute(av[i++]);
			if (i < ac)
				write(1, "\n", 1);
		}
	}
	return (0);
}

void	excute(char *path)
{
	unsigned int	hwccc[5];
	unsigned int	result[3];

	if (checkfile(path, hwccc) != 1)
	{
		write(2, "map error", 9);
		write(1, "\n", 1);
	}
	else
	{
		if (hwccc[0] < 256 && hwccc[1] < 256)
			calculsml(path, hwccc, result, hwccc[1]);
		else
			calcul(path, hwccc, result, hwccc[1]);
		printres(path, hwccc, result);
	}
}

void	excutewithinput(void)
{
	readinput();
	excute("tempinputfromternimal.map");
}
