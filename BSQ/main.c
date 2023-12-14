/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:15:29 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/13 10:33:14 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	**ft_fill_map(char **map, int c, int l, char *argv)
{
	char	obs;
	int		i;
	int		j;
	int		length;
	int		pos;

	obs = ft_char_obst(argv);
	length = ft_biggest_square(map, c, l, obs);
	pos = ft_find_position_square(map, c, l, obs);
	i = (pos / (c - 1)) - length + 1;
	while (i < (pos / (c - 1)) + 1)
	{
		j = (pos % (c - 1)) - length + 1;
		while (j < (pos % (c -1)) + 1)
		{
			map[i][j] = ft_char_full(argv);
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_print_solution(int fd, char *argv)
{
	char	**map;
	int		c;
	int		l;

	c = ft_number_columns(argv);
	l = ft_number_lines(argv);
	fd = open (argv, O_RDONLY);
	if (fd >= 0)
	{
		map = ft_read_file(argv);
	}
	ft_fill_map(map, c, l, argv);
	c = 0;
	while (c < l)
	{
		ft_putstr(map[c]);
		ft_putchar('\n');
		c++;
	}
	free(map);
	close (fd);
}

int	main(int argc, char **argv)
{
	char	*map;
	char	*path;
	int		i;

	i = 1;
	path = "newfile.txt";
	if (argc == 1)
	{	
		map = (char *)malloc(sizeof(char) * 300000);
		map = read_input(path);
		if (ft_check_map(map) == 0)
			ft_print_solution(0, map);
		free(map);
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_check_map(argv[i]) == 0)
				ft_print_solution(0, argv[i]);
			i++;
		}
	}
	return (0);
}
