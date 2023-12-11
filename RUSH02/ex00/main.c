/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:02:53 by akinzeli          #+#    #+#             */
/*   Updated: 2023/12/10 15:04:52 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*file_to_str(char *number, char *file);

int	checknumber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			return (-1);
		}
		if (str[i] == '.')
		{
			return (-1);
		}
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

void	errormessage(void)
{
	write(1, "Dict Error\n", 11);
}

int	main(int argc, char *argv[])
{
	char	*argument1;
	char	*argument2;
	int		num;

	if (argc == 1)
	{
		write(1, "Error", 5);
		return (1);
	}
	argument1 = argv[1];
	argument2 = argv[2];
	num = checknumber(argv[1]);
	if (num < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		file_to_str(argument1, "numbers.dict");
	else if (argc == 3)
		file_to_str(argument2, argument1);
	else
		write(1, "Error", 5);
	write(1, "\n", 1);
	return (0);
}
