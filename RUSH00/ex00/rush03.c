/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:12:59 by eramos-d          #+#    #+#             */
/*   Updated: 2023/11/26 16:07:58 by jeborceu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rushprint(int col, int line, int x, int y)
{
	if ((line == 1 && col == 1) || (col == 1 && line == y))
		ft_putchar('A');
	else if ((line == 1 && col == x) || (line == y && col == x))
		ft_putchar('C');
	else if ((line == 1 && col < x) || (line == y && col < x))
		ft_putchar('B');
	else if ((col == 1 && line < y) || (col == x && line < y))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	mess_error(int x, int y)
{
	if (x > 211 && y > 40000)
		write(1, "Width max: 211 and Length max: 40000\n", 37);
	else if (x > 211)
		write(1, "Width is too big, max 211\n", 26);
	else if (y > 40000)
		write(1, "Length is too big, max 40000\n", 29);
	else if (x <= 0 || y <= 0)
		write(1, "Invalid numbers, minimum 1 and an integer\n", 42);
}

void	rush(int x, int y)
{
	int	col;
	int	line;

	col = 1;
	line = 1;
	if ((x > 0 && x <= 211) && (y > 0 && y <= 40000))
	{
		while (line <= y)
		{
			while (col <= x)
			{
				rushprint(col, line, x, y);
				col++;
			}
			col = 1;
			line++;
			ft_putchar('\n');
		}
	}
	else
		mess_error(x, y);
}
