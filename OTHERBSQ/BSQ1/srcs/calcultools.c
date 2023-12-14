/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcultools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:57:22 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 15:21:26 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initvals(unsigned int *ij, unsigned int *maxlenpos)
{
	ij[0] = 0;
	ij[1] = 0;
	maxlenpos[0] = 0;
	maxlenpos[1] = 0;
	maxlenpos[2] = 0;
}

void	getmax(unsigned int *maxlenpos, unsigned int len, unsigned int *ij)
{
	maxlenpos[0] = len;
	maxlenpos[1] = ij[0];
	maxlenpos[2] = ij[1];
}

int	min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}
