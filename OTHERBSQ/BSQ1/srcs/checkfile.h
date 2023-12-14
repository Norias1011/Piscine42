/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuzhao <yuzhao@student.42luxembou...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:43:44 by yuzhao            #+#    #+#             */
/*   Updated: 2023/12/13 22:23:23 by yuzhao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKFILE_H
# define CHECKFILE_H

int		checkfile(char *path, unsigned int *hwccc);
int		check2line(char *c,
			unsigned int *io, unsigned int *hwccc, int byteread);
void	checkfirstline(char *buffer, unsigned int *hwccc,
			unsigned int *io);
void	checkrest(char *buffer, unsigned int *hwccc, unsigned int *io);
void	gethatoi(char *buffer, unsigned int *hwccc,
			unsigned int *io);
#endif
