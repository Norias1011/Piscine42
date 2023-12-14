/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:28:52 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 23:07:11 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	readinput(void)
{
	int		fd;
	char	ch;

	fd = open("tempinputfromternimal.map",
			O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		while (read(STDIN_FILENO, &ch, 1) > 0)
		{
			write(fd, &ch, 1);
		}
		close(fd);
	}
}
/*
int	main()
{
	readinput();
}
*/
