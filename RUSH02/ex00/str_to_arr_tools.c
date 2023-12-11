/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_arr_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:59:57 by jlievano          #+#    #+#             */
/*   Updated: 2023/12/10 17:00:01 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_amount_of_lines(char *src)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

void	filler(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
